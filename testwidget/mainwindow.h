#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qoscar/qoscar.h"

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

    private:
	Ui::MainWindow *ui;
        QOscar oscar;

    private slots:
	void on_requestCLBtn_clicked();
        void on_typingBtn_clicked(bool checked);
	void on_setInfoBtn_clicked();
	void on_sendBtn_clicked();
	void on_loginBtn_clicked();
	void onLoggedIn();
	void onLoggedOff();
	void onError(QOscarError error);
        void onStatusSelected(int index);
        void onMessage(const QMessage&, QOscar*);

};

#endif // MAINWINDOW_H
