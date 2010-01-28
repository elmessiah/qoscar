#ifndef NOTIFYWIDGET_H
#define NOTIFYWIDGET_H

#include <QWidget>
#include <QTimer>

//#include <QtDeclarative/QtDeclarative>
//#include "QtDeclarative/qmlview.h"

//class QmlView;

namespace Ui {
    class NotifyWidget;
}

class NotifyWidget : public QWidget {
    Q_OBJECT

//    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged);

    public:
        NotifyWidget(QWidget *parent = 0);
        ~NotifyWidget();

        void showNotify(const QString &sHeader, const QString &sMessage);

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::NotifyWidget *ui;
//        QmlView *view;

    signals:
        void onClicked();

    private slots:
        void onTimer();
};

#endif // NOTIFYWIDGET_H
