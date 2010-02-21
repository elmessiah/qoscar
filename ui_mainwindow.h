/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 21. Feb 01:11:24 2010
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
#include <QtGui/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *SNGb;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_2;
    QLineEdit *SNEd;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QLineEdit *PassEd;
    QPushButton *loginButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_3;
    QLineEdit *proxyEd;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_7;
    QLineEdit *portEd;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_8;
    QComboBox *proxyTypeCB;
    QGroupBox *MessageGB;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *TargetEd;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QComboBox *msgTypeCB;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QTextEdit *MessageEd;
    QHBoxLayout *horizontalLayout;
    QPushButton *SendBtn;
    QPushButton *setInfoBtn;
    QPushButton *typeStartedBtn;
    QPushButton *typeEndedBtn;
    QPushButton *reqInfoBtn;
    QPushButton *searchBtn;
    QGroupBox *CLBg;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QPushButton *requestCLBtn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(405, 370);
        MainWindow->setMaximumSize(QSize(504, 370));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        SNGb = new QGroupBox(centralWidget);
        SNGb->setObjectName(QString::fromUtf8("SNGb"));
        SNGb->setMaximumSize(QSize(250, 16777215));
        verticalLayout_11 = new QVBoxLayout(SNGb);
        verticalLayout_11->setSpacing(2);
        verticalLayout_11->setContentsMargins(2, 2, 2, 2);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_2 = new QLabel(SNGb);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        SNEd = new QLineEdit(SNGb);
        SNEd->setObjectName(QString::fromUtf8("SNEd"));

        verticalLayout_6->addWidget(SNEd);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_4 = new QLabel(SNGb);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_7->addWidget(label_4);

        PassEd = new QLineEdit(SNGb);
        PassEd->setObjectName(QString::fromUtf8("PassEd"));

        verticalLayout_7->addWidget(PassEd);


        horizontalLayout_4->addLayout(verticalLayout_7);

        loginButton = new QPushButton(SNGb);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(loginButton);


        verticalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_3 = new QLabel(SNGb);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_8->addWidget(label_3);

        proxyEd = new QLineEdit(SNGb);
        proxyEd->setObjectName(QString::fromUtf8("proxyEd"));

        verticalLayout_8->addWidget(proxyEd);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_7 = new QLabel(SNGb);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_9->addWidget(label_7);

        portEd = new QLineEdit(SNGb);
        portEd->setObjectName(QString::fromUtf8("portEd"));
        portEd->setMaximumSize(QSize(39, 16777215));

        verticalLayout_9->addWidget(portEd);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_8 = new QLabel(SNGb);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_10->addWidget(label_8);

        proxyTypeCB = new QComboBox(SNGb);
        proxyTypeCB->setObjectName(QString::fromUtf8("proxyTypeCB"));

        verticalLayout_10->addWidget(proxyTypeCB);


        horizontalLayout_3->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_3);


        verticalLayout_12->addWidget(SNGb);

        MessageGB = new QGroupBox(centralWidget);
        MessageGB->setObjectName(QString::fromUtf8("MessageGB"));
        MessageGB->setMaximumSize(QSize(250, 16777215));
        verticalLayout_5 = new QVBoxLayout(MessageGB);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(MessageGB);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        TargetEd = new QLineEdit(MessageGB);
        TargetEd->setObjectName(QString::fromUtf8("TargetEd"));

        verticalLayout_3->addWidget(TargetEd);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(MessageGB);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        msgTypeCB = new QComboBox(MessageGB);
        msgTypeCB->setObjectName(QString::fromUtf8("msgTypeCB"));

        verticalLayout_2->addWidget(msgTypeCB);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_6 = new QLabel(MessageGB);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_4->addWidget(label_6);

        MessageEd = new QTextEdit(MessageGB);
        MessageEd->setObjectName(QString::fromUtf8("MessageEd"));

        verticalLayout_4->addWidget(MessageEd);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SendBtn = new QPushButton(MessageGB);
        SendBtn->setObjectName(QString::fromUtf8("SendBtn"));

        horizontalLayout->addWidget(SendBtn);

        setInfoBtn = new QPushButton(MessageGB);
        setInfoBtn->setObjectName(QString::fromUtf8("setInfoBtn"));

        horizontalLayout->addWidget(setInfoBtn);

        typeStartedBtn = new QPushButton(MessageGB);
        typeStartedBtn->setObjectName(QString::fromUtf8("typeStartedBtn"));

        horizontalLayout->addWidget(typeStartedBtn);

        typeEndedBtn = new QPushButton(MessageGB);
        typeEndedBtn->setObjectName(QString::fromUtf8("typeEndedBtn"));

        horizontalLayout->addWidget(typeEndedBtn);

        reqInfoBtn = new QPushButton(MessageGB);
        reqInfoBtn->setObjectName(QString::fromUtf8("reqInfoBtn"));

        horizontalLayout->addWidget(reqInfoBtn);


        verticalLayout_5->addLayout(horizontalLayout);

        searchBtn = new QPushButton(MessageGB);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));

        verticalLayout_5->addWidget(searchBtn);


        verticalLayout_12->addWidget(MessageGB);


        horizontalLayout_5->addLayout(verticalLayout_12);

        CLBg = new QGroupBox(centralWidget);
        CLBg->setObjectName(QString::fromUtf8("CLBg"));
        CLBg->setMaximumSize(QSize(200, 16777215));
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


        horizontalLayout_5->addWidget(CLBg);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        SNGb->setTitle(QApplication::translate("MainWindow", "SN Settings", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "SN:", 0, QApplication::UnicodeUTF8));
        SNEd->setText(QApplication::translate("MainWindow", "468295453", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Password:", 0, QApplication::UnicodeUTF8));
        PassEd->setText(QApplication::translate("MainWindow", "1234567", 0, QApplication::UnicodeUTF8));
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Proxy:", 0, QApplication::UnicodeUTF8));
        proxyEd->setText(QApplication::translate("MainWindow", "0.0.0.0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Port:", 0, QApplication::UnicodeUTF8));
        portEd->setText(QApplication::translate("MainWindow", "65535", 0, QApplication::UnicodeUTF8));
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
        TargetEd->setText(QApplication::translate("MainWindow", "210701", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        msgTypeCB->clear();
        msgTypeCB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Plain message", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth request", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth ok", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Auth deny", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "You were added", 0, QApplication::UnicodeUTF8)
        );
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
        reqInfoBtn->setText(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        searchBtn->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
        CLBg->setTitle(QApplication::translate("MainWindow", "Roster", 0, QApplication::UnicodeUTF8));
        requestCLBtn->setText(QApplication::translate("MainWindow", "Request", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
