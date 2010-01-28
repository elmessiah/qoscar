/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 27. Jan 18:14:45 2010
**      by: Qt User Interface Compiler version 4.6.1
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *CLBg;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QPushButton *requestCLBtn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *SNGb;
    QLineEdit *SNEd;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *PassEd;
    QPushButton *loginButton;
    QLabel *label_7;
    QLineEdit *portEd;
    QLineEdit *proxyEd;
    QLabel *label_3;
    QLabel *label_8;
    QComboBox *proxyTypeCB;
    QGroupBox *MessageGB;
    QLabel *label;
    QComboBox *msgTypeCB;
    QLineEdit *TargetEd;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *MessageEd;
    QPushButton *SendBtn;
    QPushButton *setInfoBtn;
    QPushButton *typeStartedBtn;
    QPushButton *typeEndedBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(409, 370);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CLBg = new QGroupBox(centralWidget);
        CLBg->setObjectName(QString::fromUtf8("CLBg"));
        CLBg->setGeometry(QRect(270, 10, 131, 351));
        verticalLayout = new QVBoxLayout(CLBg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeWidget = new QTreeWidget(CLBg);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setAutoFillBackground(false);
        treeWidget->setDragEnabled(true);
        treeWidget->setDragDropMode(QAbstractItemView::DragDrop);
        treeWidget->setUniformRowHeights(false);
        treeWidget->setAnimated(true);
        treeWidget->setWordWrap(false);
        treeWidget->setHeaderHidden(true);

        verticalLayout->addWidget(treeWidget);

        requestCLBtn = new QPushButton(CLBg);
        requestCLBtn->setObjectName(QString::fromUtf8("requestCLBtn"));

        verticalLayout->addWidget(requestCLBtn);

        pushButton = new QPushButton(CLBg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(CLBg);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        SNGb = new QGroupBox(centralWidget);
        SNGb->setObjectName(QString::fromUtf8("SNGb"));
        SNGb->setGeometry(QRect(10, 10, 251, 121));
        SNEd = new QLineEdit(SNGb);
        SNEd->setObjectName(QString::fromUtf8("SNEd"));
        SNEd->setGeometry(QRect(20, 40, 61, 20));
        label_2 = new QLabel(SNGb);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 31, 16));
        label_4 = new QLabel(SNGb);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 20, 61, 16));
        PassEd = new QLineEdit(SNGb);
        PassEd->setObjectName(QString::fromUtf8("PassEd"));
        PassEd->setGeometry(QRect(90, 40, 71, 20));
        loginButton = new QPushButton(SNGb);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(170, 40, 71, 21));
        label_7 = new QLabel(SNGb);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 70, 31, 16));
        portEd = new QLineEdit(SNGb);
        portEd->setObjectName(QString::fromUtf8("portEd"));
        portEd->setGeometry(QRect(120, 90, 41, 20));
        proxyEd = new QLineEdit(SNGb);
        proxyEd->setObjectName(QString::fromUtf8("proxyEd"));
        proxyEd->setGeometry(QRect(20, 90, 91, 20));
        label_3 = new QLabel(SNGb);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 70, 41, 16));
        label_8 = new QLabel(SNGb);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(170, 70, 31, 16));
        proxyTypeCB = new QComboBox(SNGb);
        proxyTypeCB->setObjectName(QString::fromUtf8("proxyTypeCB"));
        proxyTypeCB->setGeometry(QRect(170, 90, 71, 22));
        MessageGB = new QGroupBox(centralWidget);
        MessageGB->setObjectName(QString::fromUtf8("MessageGB"));
        MessageGB->setGeometry(QRect(10, 130, 251, 231));
        label = new QLabel(MessageGB);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 46, 16));
        msgTypeCB = new QComboBox(MessageGB);
        msgTypeCB->setObjectName(QString::fromUtf8("msgTypeCB"));
        msgTypeCB->setGeometry(QRect(90, 40, 121, 22));
        TargetEd = new QLineEdit(MessageGB);
        TargetEd->setObjectName(QString::fromUtf8("TargetEd"));
        TargetEd->setGeometry(QRect(20, 40, 61, 20));
        label_5 = new QLabel(MessageGB);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 20, 31, 16));
        label_6 = new QLabel(MessageGB);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 70, 46, 14));
        MessageEd = new QTextEdit(MessageGB);
        MessageEd->setObjectName(QString::fromUtf8("MessageEd"));
        MessageEd->setGeometry(QRect(10, 90, 231, 71));
        SendBtn = new QPushButton(MessageGB);
        SendBtn->setObjectName(QString::fromUtf8("SendBtn"));
        SendBtn->setGeometry(QRect(10, 170, 41, 23));
        setInfoBtn = new QPushButton(MessageGB);
        setInfoBtn->setObjectName(QString::fromUtf8("setInfoBtn"));
        setInfoBtn->setGeometry(QRect(50, 170, 51, 23));
        typeStartedBtn = new QPushButton(MessageGB);
        typeStartedBtn->setObjectName(QString::fromUtf8("typeStartedBtn"));
        typeStartedBtn->setGeometry(QRect(100, 170, 41, 23));
        typeEndedBtn = new QPushButton(MessageGB);
        typeEndedBtn->setObjectName(QString::fromUtf8("typeEndedBtn"));
        typeEndedBtn->setGeometry(QRect(140, 170, 41, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        CLBg->setTitle(QApplication::translate("MainWindow", "Roster", 0, QApplication::UnicodeUTF8));
        requestCLBtn->setText(QApplication::translate("MainWindow", "Request", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        SNGb->setTitle(QApplication::translate("MainWindow", "SN Settings", 0, QApplication::UnicodeUTF8));
        SNEd->setText(QApplication::translate("MainWindow", "468295453", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "SN:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Password:", 0, QApplication::UnicodeUTF8));
        PassEd->setText(QApplication::translate("MainWindow", "1234567", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        portEd->setText(QApplication::translate("MainWindow", "65535", 0, QApplication::UnicodeUTF8));
        proxyEd->setText(QApplication::translate("MainWindow", "0.0.0.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Proxy:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        proxyTypeCB->clear();
        proxyTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "None", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Http(s)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Socks4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Socks5", 0, QApplication::UnicodeUTF8)
        );
        MessageGB->setTitle(QApplication::translate("MainWindow", "Message", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Target:", 0, QApplication::UnicodeUTF8));
        msgTypeCB->clear();
        msgTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Plain message", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth request", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth ok", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth deny", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "You were added", 0, QApplication::UnicodeUTF8)
        );
        TargetEd->setText(QApplication::translate("MainWindow", "210701", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Message:", 0, QApplication::UnicodeUTF8));
        MessageEd->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Hello!</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        SendBtn->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        setInfoBtn->setText(QApplication::translate("MainWindow", "Set Info", 0, QApplication::UnicodeUTF8));
        typeStartedBtn->setText(QApplication::translate("MainWindow", "Type s", 0, QApplication::UnicodeUTF8));
        typeEndedBtn->setText(QApplication::translate("MainWindow", "Type e", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
