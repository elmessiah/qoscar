/********************************************************************************
** Form generated from reading UI file 'reportwidget.ui'
**
** Created: Sat 6. Feb 17:09:24 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIDGET_H
#define UI_REPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *typeCB;
    QLabel *label_2;
    QPlainTextEdit *errorPTE;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendBtn;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ReportWidget)
    {
        if (ReportWidget->objectName().isEmpty())
            ReportWidget->setObjectName(QString::fromUtf8("ReportWidget"));
        ReportWidget->resize(309, 295);
        verticalLayout = new QVBoxLayout(ReportWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ReportWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        typeCB = new QComboBox(ReportWidget);
        typeCB->setObjectName(QString::fromUtf8("typeCB"));

        verticalLayout->addWidget(typeCB);

        label_2 = new QLabel(ReportWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        errorPTE = new QPlainTextEdit(ReportWidget);
        errorPTE->setObjectName(QString::fromUtf8("errorPTE"));

        verticalLayout->addWidget(errorPTE);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sendBtn = new QPushButton(ReportWidget);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        cancelBtn = new QPushButton(ReportWidget);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ReportWidget);

        QMetaObject::connectSlotsByName(ReportWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportWidget)
    {
        ReportWidget->setWindowTitle(QApplication::translate("ReportWidget", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ReportWidget", "Problem type:", 0, QApplication::UnicodeUTF8));
        typeCB->clear();
        typeCB->insertItems(0, QStringList()
         << QApplication::translate("ReportWidget", "Select please", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("ReportWidget", "Problem:", 0, QApplication::UnicodeUTF8));
        sendBtn->setText(QApplication::translate("ReportWidget", "Send", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ReportWidget", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReportWidget: public Ui_ReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIDGET_H
