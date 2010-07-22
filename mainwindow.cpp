#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&oscar, SIGNAL(onError(QOscarError)), this, SLOT(onError(QOscarError)));
    connect(&oscar, SIGNAL(onLoggedIn()), this, SLOT(onLoggedIn()));
    connect(&oscar, SIGNAL(onLoggedOff()), this, SLOT(onLoggedOff()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


/** ********************************************* **/
/**		    SLOTS			  **/
/** ********************************************* **/

/* Oscar Error */
void MainWindow::onError(QOscarError error)
{
    qDebug() << "[Tester] {Error} OSCAR Error:" << error;
    ui->logsPTE->appendHtml("<font color=red><b>Error!</b></font><br>");
    ui->loginBtn->setEnabled(true);
}

/* Oscar logged in */
void MainWindow::onLoggedIn()
{
    ui->logsPTE->appendHtml("<font color=green><b>Logged in!</b></font><br>");
    qDebug() << "[Tester] {Message} OSCAR Logged in";
    ui->loginBtn->setEnabled(true);
    ui->loginBtn->setText("Logoff");

    oscar.setWebAware(true, true);
    oscar.requestOfflineMessages();
}

/* Oscar logged off */
void MainWindow::onLoggedOff()
{
    ui->logsPTE->appendHtml("<font color=blue><b>Logged off</b></font><br>");
    qDebug() << "[Tester] {Message} OSCAR Logged off";
    ui->loginBtn->setEnabled(true);
    ui->loginBtn->setText("Login");
}

/* Login BUTTON clicked */
void MainWindow::on_loginBtn_clicked()
{
    if ( ui->loginBtn->text() == "Logoff" ) {
	oscar.logoff();
	return;
    }

    oscar.setSN(ui->snLE->text().trimmed());
    oscar.setPassword(ui->passLE->text().trimmed());
    oscar.login();
    ui->loginBtn->setEnabled(false);
}

/* SEND BUTTON clicked */
void MainWindow::on_sendBtn_clicked()
{
    oscar.sendMessage(ui->targetSN->text().trimmed(), ui->msgPTE->toPlainText());
}

/* Set info button clicked */
void MainWindow::on_setInfoBtn_clicked()
{
    QOscarUserInfo info;
    info.nickName = "QOSCAR - Testing";
    info.firstName = "Artem";
    info.lastName = "Smirnov";
    info.gender = 1;
    info.birthDay = 30;
    info.birthMonth = 07;
    info.birthYear = 1932;

    oscar.setInfo(info);
}


/* Send typing notification */
void MainWindow::on_typingBtn_clicked(bool checked)
{
    oscar.sendTypingNotification(ui->targetSN->text(), checked);
}

/* Reqesting Roster */
void MainWindow::on_requestCLBtn_clicked()
{
    oscar.requestRoster();
}
