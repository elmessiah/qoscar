#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    oscar = new QOSCAR(this);
    notifyWidget = new NotifyWidget;

    QState *state1 = new QState;
    QState *state2 = new QState;
    QDesktopWidget desktop;
    state1->assignProperty(notifyWidget, "geometry",
                           QRect(desktop.width() - notifyWidget->width(),
                                 desktop.height(), notifyWidget->width(),
                                 notifyWidget->height()));
    state2->assignProperty(notifyWidget, "geometry",
                           QRect(desktop.width() - notifyWidget->width(),
                                 desktop.height() - notifyWidget->height() - 20,
                                 notifyWidget->width(), notifyWidget->height()));
    state1->addTransition(this, SIGNAL(sShowNotify()), state2);
    state2->addTransition(notifyWidget, SIGNAL(onClicked()), state1);
    machine.addState(state1);
    machine.addState(state2);
    machine.setInitialState(state1);
    QPropertyAnimation *animation = new QPropertyAnimation(notifyWidget, "geometry");
    animation->setEasingCurve(QEasingCurve::InOutElastic);
    animation->setDuration(1000);
    machine.addDefaultAnimation(animation);
    machine.start();

    connect(oscar, SIGNAL(fError(QErrorType, QString)), this,
            SLOT(onError(QErrorType,QString)));
    connect(oscar, SIGNAL(fLoggedIn()), this, SLOT(onLogin()));
    connect(oscar, SIGNAL(fMessageReceived(QMessage)), this, SLOT(onMessage(QMessage)));
    connect(oscar, SIGNAL(fCLHandled()), this, SLOT(onCLHandled()));
    connect(oscar, SIGNAL(fLoggedOff()), this, SLOT(onLogOff()));
    QTimer::singleShot(20000, this, SLOT(onTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Debug functions */

/* Signing on */
void MainWindow::login()
{
    oscar->setScreenName(ui->SNEd->text());
    oscar->setPassword(ui->PassEd->text());
    oscar->login();
}

void MainWindow::showNotify(const QString &sHeader, const QString &sText)
{
    notifyWidget->showNotify(sHeader, sText);
    emit sShowNotify();
}

/**********************************************
    SLOTS
*********************************************/

void MainWindow::on_loginButton_clicked()
{
    if (ui->proxyTypeCB->currentIndex() != 0){
        QNetworkProxy proxy;
        proxy.setHostName(ui->proxyEd->text());
        proxy.setPort(ui->portEd->text().toInt());

        switch (ui->proxyTypeCB->currentIndex()){
            case 1:
                proxy.setType(QNetworkProxy::HttpProxy);
            case 2:
                proxy.setType(QNetworkProxy::Socks5Proxy);
            case 3:
                proxy.setType(QNetworkProxy::Socks5Proxy);
        }
    }

    if (ui->loginButton->text() == "Login"){
        ui->loginButton->setText("Logoff");
        time = QTime::currentTime();
        login();
    }else{
        ui->loginButton->setText("Login");
        oscar->logoff();
    }
}

void MainWindow::on_SendBtn_clicked()
{
    oscar->sendMessage(ui->TargetEd->text(), ui->MessageEd->toPlainText());
}

void MainWindow::onError(QErrorType errorType, QString errorString)
{
    showNotify("System::Error", QString("<b><font color=red>" + errorString +
                                        "</font></b>"));
}

void MainWindow::onLogin(void)
{
    QTime time2;
    time2 = QTime::currentTime();
    time2.addMSecs(- ((time.hour() * 3600 * 1000) + (time.minute() * 60 * 1000)
                     + (time.second() * 1000) + time.msec()));
    showNotify("System::Notify", "<b><font color=green>Logged in!</font></b>");
}

void MainWindow::onMessage(QMessage msg)
{
    QString fMsg(msg.sSender);
    fMsg.append(": ");
    fMsg.append(msg.sMessage);
    showNotify("System::Message", "<b><font color=blue>" + fMsg + "</font></b>");
}

void MainWindow::onCLHandled()
{
    QRosterItem *rosterItems = oscar->roster()->items();
    QList<QTreeWidgetItem *> items;
     for (int i = 0; i < oscar->roster()->count(); ++i)
         if ( rosterItems[i].sScreenName.length() > 0 && rosterItems[i].u16Id != 0x0000 )
             items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(rosterItems[i].sScreenName)));
    ui->treeWidget->insertTopLevelItems(0, items);
    delete rosterItems;
}


void MainWindow::on_setInfoBtn_clicked()
{
//    QSNInfo snInfo;
//    snInfo.sNickName = "Qoscar::Test";
//    snInfo.sFirstName = "РанкоР";
//    snInfo.sLastName = "Testing";
//    snInfo.sEMail = "admin@ax-soft.ru";
//    snInfo.sHomeCity = "Moscow";
//    snInfo.sHomeState = "MO";
//    snInfo.sHomePhone = "02";
//    snInfo.sHomeFax = "02";
//    snInfo.sHomeStreet = "Kremlin";
//    snInfo.sHomeCellular = "02";
//    snInfo.sHomeZip = "141707";
//    snInfo.usHomeCountry.data = 0x0007;
//    snInfo.usUserAge.data = 17;
//    snInfo.us8UserGender.data = 2;
//    snInfo.sAbout = "Testin' the Qoscar...";
//    snInfo.usBirthDay.data = 30;
//    snInfo.usBirthMonth.data = 7;
//    snInfo.usBirthYear.data = 1902;
//    oscar->setInfo(snInfo);
//    oscar->setBasicInfo();
    oscar->setAuthInfo(true, false);
}

void MainWindow::on_requestCLBtn_clicked()
{
    oscar->requestCL();
}

void MainWindow::onLogOff(void)
{
    showNotify("System::Notify", "<b><font color=green>Logged off!</font></b>");
}

void MainWindow::on_treeWidget_itemSelectionChanged()
{
    ui->TargetEd->setText(ui->treeWidget->currentItem()->text(0));
}

void MainWindow::on_pushButton_clicked()
{
    oscar->deleteUser(ui->TargetEd->text());
}

void MainWindow::on_pushButton_2_clicked()
{
    oscar->addUser(ui->TargetEd->text(), "New Contact", "", 0x4442);
}

void MainWindow::on_typeStartedBtn_clicked()
{
    oscar->sendTypingNotification(true, "210701");
}

void MainWindow::on_typeEndedBtn_clicked()
{
    oscar->sendTypingNotification(false, "210701");
}

void MainWindow::onTimer()
{
    oscar->changeStatus(STATUS_AWAY, STATUS_WEBAWARE);
}
