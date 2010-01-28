/********************************************************************************
** Form generated from reading UI file 'notifywidget.ui'
**
** Created: Thu 28. Jan 16:20:42 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTIFYWIDGET_H
#define UI_NOTIFYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NotifyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLb;
    QFrame *line;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *NotifyWidget)
    {
        if (NotifyWidget->objectName().isEmpty())
            NotifyWidget->setObjectName(QString::fromUtf8("NotifyWidget"));
        NotifyWidget->resize(190, 189);
        verticalLayout = new QVBoxLayout(NotifyWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headerLb = new QLabel(NotifyWidget);
        headerLb->setObjectName(QString::fromUtf8("headerLb"));
        headerLb->setScaledContents(true);
        headerLb->setWordWrap(true);
        headerLb->setOpenExternalLinks(false);
        headerLb->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(headerLb);

        line = new QFrame(NotifyWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        textBrowser = new QTextBrowser(NotifyWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setAutoFormatting(QTextEdit::AutoAll);
        textBrowser->setUndoRedoEnabled(false);

        verticalLayout->addWidget(textBrowser);


        retranslateUi(NotifyWidget);

        QMetaObject::connectSlotsByName(NotifyWidget);
    } // setupUi

    void retranslateUi(QWidget *NotifyWidget)
    {
        NotifyWidget->setWindowTitle(QApplication::translate("NotifyWidget", "Form", 0, QApplication::UnicodeUTF8));
        headerLb->setText(QApplication::translate("NotifyWidget", "Header", 0, QApplication::UnicodeUTF8));
        textBrowser->setDocumentTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class NotifyWidget: public Ui_NotifyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTIFYWIDGET_H
