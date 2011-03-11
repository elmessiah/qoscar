/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 12. Jun 00:05:59 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTreeView *rosterTree;
    QLabel *label;
    QLineEdit *snLE;
    QLineEdit *passLE;
    QLabel *label_2;
    QPushButton *loginBtn;
    QFrame *line;
    QPushButton *reqRosterBtn;
    QPlainTextEdit *msgPTE;
    QFrame *line_2;
    QLabel *label_3;
    QLineEdit *targetSN;
    QComboBox *msgTypeCB;
    QPushButton *sendBtn;
    QFrame *line_3;
    QPlainTextEdit *logsPTE;
    QPushButton *setInfoBtn;
    QPushButton *typingBtn;
    QPushButton *requestCLBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(360, 498);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        rosterTree = new QTreeView(centralWidget);
        rosterTree->setObjectName(QString::fromUtf8("rosterTree"));
        rosterTree->setGeometry(QRect(210, 10, 141, 201));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 56, 15));
        snLE = new QLineEdit(centralWidget);
        snLE->setObjectName(QString::fromUtf8("snLE"));
        snLE->setGeometry(QRect(10, 30, 81, 25));
        passLE = new QLineEdit(centralWidget);
        passLE->setObjectName(QString::fromUtf8("passLE"));
        passLE->setGeometry(QRect(100, 30, 71, 25));
        passLE->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 10, 71, 16));
        loginBtn = new QPushButton(centralWidget);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(10, 240, 88, 27));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 220, 191, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        reqRosterBtn = new QPushButton(centralWidget);
        reqRosterBtn->setObjectName(QString::fromUtf8("reqRosterBtn"));
        reqRosterBtn->setGeometry(QRect(100, 240, 88, 27));
        msgPTE = new QPlainTextEdit(centralWidget);
        msgPTE->setObjectName(QString::fromUtf8("msgPTE"));
        msgPTE->setGeometry(QRect(10, 130, 191, 84));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 60, 191, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 56, 15));
        targetSN = new QLineEdit(centralWidget);
        targetSN->setObjectName(QString::fromUtf8("targetSN"));
        targetSN->setGeometry(QRect(10, 100, 81, 25));
        msgTypeCB = new QComboBox(centralWidget);
        msgTypeCB->setObjectName(QString::fromUtf8("msgTypeCB"));
        msgTypeCB->setGeometry(QRect(100, 100, 101, 25));
        sendBtn = new QPushButton(centralWidget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));
        sendBtn->setGeometry(QRect(10, 270, 88, 27));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 300, 341, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        logsPTE = new QPlainTextEdit(centralWidget);
        logsPTE->setObjectName(QString::fromUtf8("logsPTE"));
        logsPTE->setGeometry(QRect(10, 320, 341, 161));
        setInfoBtn = new QPushButton(centralWidget);
        setInfoBtn->setObjectName(QString::fromUtf8("setInfoBtn"));
        setInfoBtn->setGeometry(QRect(100, 270, 88, 27));
        typingBtn = new QPushButton(centralWidget);
        typingBtn->setObjectName(QString::fromUtf8("typingBtn"));
        typingBtn->setGeometry(QRect(190, 240, 88, 27));
        typingBtn->setCheckable(true);
        requestCLBtn = new QPushButton(centralWidget);
        requestCLBtn->setObjectName(QString::fromUtf8("requestCLBtn"));
        requestCLBtn->setGeometry(QRect(190, 270, 88, 27));
        requestCLBtn->setCheckable(true);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "SN:", 0, QApplication::UnicodeUTF8));
        snLE->setText(QApplication::translate("MainWindow", "558639039", 0, QApplication::UnicodeUTF8));
        passLE->setText(QApplication::translate("MainWindow", "qoscarpass", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Password:", 0, QApplication::UnicodeUTF8));
        loginBtn->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        reqRosterBtn->setText(QApplication::translate("MainWindow", "Request CL", 0, QApplication::UnicodeUTF8));
        msgPTE->setPlainText(QApplication::translate("MainWindow", "Hello", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "SN:", 0, QApplication::UnicodeUTF8));
        targetSN->setText(QApplication::translate("MainWindow", "260454", 0, QApplication::UnicodeUTF8));
        msgTypeCB->clear();
        msgTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Plain", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth Req", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth OK", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth Deny", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "You were added", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Remove yourself", 0, QApplication::UnicodeUTF8)
        );
        sendBtn->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        setInfoBtn->setText(QApplication::translate("MainWindow", "Set info", 0, QApplication::UnicodeUTF8));
        typingBtn->setText(QApplication::translate("MainWindow", "Typing", 0, QApplication::UnicodeUTF8));
        requestCLBtn->setText(QApplication::translate("MainWindow", "Request CL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
