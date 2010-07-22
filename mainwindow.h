#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "qoscar/qoscar.h"

namespace Ui {
    class MainWindow;
}

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

};

#endif // MAINWINDOW_H
