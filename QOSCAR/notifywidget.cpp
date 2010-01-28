#include "notifywidget.h"
#include "ui_notifywidget.h"

NotifyWidget::NotifyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotifyWidget)
{
    ui->setupUi(this);
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
