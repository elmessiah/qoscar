#include "notifywidget.h"
#include "ui_notifywidget.h"

NotifyWidget::NotifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotifyWidget)
{
    ui->setupUi(this);
    setVisible(false);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_NoSystemBackground);
//    view = new QmlView(this);
//    view->viewport()->setAutoFillBackground(false);
//    view->setFocus();
//    QString filename = qApp->applicationDirPath() + "../QMLNotify.qml";
//    view->setUrl(QUrl::fromLocalFile(filename));
    //view->rootContext()->setContextProperty("MyObject",object);
    //view->rootContext()->setContextProperty("MyText","Hello, QML!");
}

NotifyWidget::~NotifyWidget()
{
    delete ui;
}

void NotifyWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void NotifyWidget::showNotify(const QString &sHeader, const QString &sMessage)
{
    ui->headerLb->setText(sHeader);
    ui->textBrowser->setHtml(sMessage);
    setVisible(true);
    QTimer::singleShot(5000, this, SIGNAL(onClicked()));
    QTimer::singleShot(5500, this, SLOT(onTimer()));
}

void NotifyWidget::onTimer()
{
    setVisible(false);
}
