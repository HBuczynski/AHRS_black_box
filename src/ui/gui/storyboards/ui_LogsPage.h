/********************************************************************************
** Form generated from reading UI file 'LogsPage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGSPAGE_H
#define UI_LOGSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogsPage
{
public:
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QFrame *buttonFrame;
    QHBoxLayout *horizontalButtons;
    QGridLayout *buttonLayout;

    void setupUi(QWidget *LogsPage)
    {
        if (LogsPage->objectName().isEmpty())
            LogsPage->setObjectName(QStringLiteral("LogsPage"));
        LogsPage->resize(1024, 600);
        verticalFrame = new QFrame(LogsPage);
        verticalFrame->setObjectName(QStringLiteral("verticalFrame"));
        verticalFrame->setGeometry(QRect(0, 0, 1024, 600));
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        titleLabel = new QLabel(verticalFrame);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        verticalLayout->addWidget(titleLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonFrame = new QFrame(LogsPage);
        buttonFrame->setObjectName(QStringLiteral("buttonFrame"));
        buttonFrame->setGeometry(QRect(512, 560, 512, 40));
        buttonFrame->setStyleSheet(QStringLiteral(""));
        buttonFrame->setLineWidth(0);
        horizontalButtons = new QHBoxLayout(buttonFrame);
        horizontalButtons->setSpacing(0);
        horizontalButtons->setObjectName(QStringLiteral("horizontalButtons"));
        horizontalButtons->setContentsMargins(0, 0, 0, 0);
        buttonLayout = new QGridLayout();
        buttonLayout->setSpacing(0);
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));

        horizontalButtons->addLayout(buttonLayout);


        retranslateUi(LogsPage);

        QMetaObject::connectSlotsByName(LogsPage);
    } // setupUi

    void retranslateUi(QWidget *LogsPage)
    {
        LogsPage->setWindowTitle(QApplication::translate("LogsPage", "Form", 0));
        titleLabel->setText(QApplication::translate("LogsPage", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class LogsPage: public Ui_LogsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGSPAGE_H
