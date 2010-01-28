#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTime>
#include <QMessageBox>
#include <QStateMachine>
#include <QDesktopWidget>
#include <QPropertyAnimation>

#include "QOSCAR/qoscar.h"
#include "notifywidget.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void login();
        void showNotify(const QString &sHeader, const QString &sText);

    private:
        Ui::MainWindow *ui;
        QOSCAR *oscar;
        NotifyWidget *notifyWidget;
        QTime time;
        QStateMachine machine;

    private slots:
        void on_typeEndedBtn_clicked();
        void on_typeStartedBtn_clicked();
        void on_pushButton_2_clicked();
        void on_pushButton_clicked();
        void on_treeWidget_itemSelectionChanged();
        void on_requestCLBtn_clicked();
        void on_setInfoBtn_clicked();
        void on_SendBtn_clicked();
        void on_loginButton_clicked();
        void onTimer();

        // OSCAR
        void onError(QErrorType errorType, QString errorString);
        void onLogin(void);
        void onMessage(QMessage);
        void onLogOff(void);
        void onCLHandled();

    signals:
        void sShowNotify();
};

#endif // MAINWINDOW_H
