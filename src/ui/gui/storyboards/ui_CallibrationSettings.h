/********************************************************************************
** Form generated from reading UI file 'CallibrationSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALLIBRATIONSETTINGS_H
#define UI_CALLIBRATIONSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CallibrationSettings
{
public:
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QPushButton *exitButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *planeLabel;
    QSpacerItem *horizontalSpacer_6;
    QLabel *planeDotsLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *planeValueLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *fromDatabaseLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *fromDatabaseDotsLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *fromDatabaseComboBox;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *newPlaneLabel;
    QSpacerItem *horizontalSpacer_4;
    QLabel *newPlaneDotsLabel;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *newPlaneLineEdit;
    QSpacerItem *verticalSpacer_4;
    QFrame *keyboardFrame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_6;
    QLabel *dotsLabel;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *leftButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *rightButton;

    void setupUi(QWidget *CallibrationSettings)
    {
        if (CallibrationSettings->objectName().isEmpty())
            CallibrationSettings->setObjectName(QStringLiteral("CallibrationSettings"));
        CallibrationSettings->resize(1024, 600);
        verticalFrame = new QFrame(CallibrationSettings);
        verticalFrame->setObjectName(QStringLiteral("verticalFrame"));
        verticalFrame->setGeometry(QRect(0, 0, 1024, 600));
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(70, 10, 70, 30);
        exitButton = new QPushButton(verticalFrame);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setMinimumSize(QSize(100, 30));
        exitButton->setMaximumSize(QSize(100, 16777215));
        exitButton->setLayoutDirection(Qt::LeftToRight);
        exitButton->setCheckable(false);

        verticalLayout->addWidget(exitButton, 0, Qt::AlignRight);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        titleLabel = new QLabel(verticalFrame);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        verticalLayout->addWidget(titleLabel);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        planeLabel = new QLabel(verticalFrame);
        planeLabel->setObjectName(QStringLiteral("planeLabel"));
        planeLabel->setMinimumSize(QSize(200, 0));
        planeLabel->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(planeLabel);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        planeDotsLabel = new QLabel(verticalFrame);
        planeDotsLabel->setObjectName(QStringLiteral("planeDotsLabel"));
        planeDotsLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(planeDotsLabel);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        planeValueLabel = new QLabel(verticalFrame);
        planeValueLabel->setObjectName(QStringLiteral("planeValueLabel"));
        planeValueLabel->setMinimumSize(QSize(160, 0));
        planeValueLabel->setMaximumSize(QSize(160, 16777215));
        planeValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(planeValueLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fromDatabaseLabel = new QLabel(verticalFrame);
        fromDatabaseLabel->setObjectName(QStringLiteral("fromDatabaseLabel"));
        fromDatabaseLabel->setMinimumSize(QSize(200, 0));
        fromDatabaseLabel->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(fromDatabaseLabel);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        fromDatabaseDotsLabel = new QLabel(verticalFrame);
        fromDatabaseDotsLabel->setObjectName(QStringLiteral("fromDatabaseDotsLabel"));

        horizontalLayout->addWidget(fromDatabaseDotsLabel);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        fromDatabaseComboBox = new QComboBox(verticalFrame);
        fromDatabaseComboBox->setObjectName(QStringLiteral("fromDatabaseComboBox"));
        fromDatabaseComboBox->setMinimumSize(QSize(160, 0));
        fromDatabaseComboBox->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(fromDatabaseComboBox);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        newPlaneLabel = new QLabel(verticalFrame);
        newPlaneLabel->setObjectName(QStringLiteral("newPlaneLabel"));
        newPlaneLabel->setMinimumSize(QSize(200, 0));
        newPlaneLabel->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(newPlaneLabel);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        newPlaneDotsLabel = new QLabel(verticalFrame);
        newPlaneDotsLabel->setObjectName(QStringLiteral("newPlaneDotsLabel"));

        horizontalLayout_4->addWidget(newPlaneDotsLabel);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        newPlaneLineEdit = new QLineEdit(verticalFrame);
        newPlaneLineEdit->setObjectName(QStringLiteral("newPlaneLineEdit"));
        newPlaneLineEdit->setMinimumSize(QSize(160, 0));
        newPlaneLineEdit->setMaximumSize(QSize(160, 16777215));

        horizontalLayout_4->addWidget(newPlaneLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        keyboardFrame = new QFrame(verticalFrame);
        keyboardFrame->setObjectName(QStringLiteral("keyboardFrame"));
        keyboardFrame->setMinimumSize(QSize(800, 222));
        keyboardFrame->setMaximumSize(QSize(820, 16777215));
        gridLayoutWidget = new QWidget(keyboardFrame);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 801, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(keyboardFrame, 0, Qt::AlignHCenter);

        verticalSpacer_6 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        dotsLabel = new QLabel(verticalFrame);
        dotsLabel->setObjectName(QStringLiteral("dotsLabel"));

        verticalLayout->addWidget(dotsLabel);

        verticalSpacer_7 = new QSpacerItem(8, 3, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        leftButton = new QPushButton(verticalFrame);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setMinimumSize(QSize(200, 35));
        leftButton->setMaximumSize(QSize(16777211, 16777215));
        leftButton->setBaseSize(QSize(200, 0));

        horizontalLayout_5->addWidget(leftButton);

        horizontalSpacer_7 = new QSpacerItem(210, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        rightButton = new QPushButton(verticalFrame);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setMinimumSize(QSize(200, 35));

        horizontalLayout_5->addWidget(rightButton);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(CallibrationSettings);

        QMetaObject::connectSlotsByName(CallibrationSettings);
    } // setupUi

    void retranslateUi(QWidget *CallibrationSettings)
    {
        CallibrationSettings->setWindowTitle(QApplication::translate("CallibrationSettings", "Form", Q_NULLPTR));
        exitButton->setText(QApplication::translate("CallibrationSettings", "AHRS", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        planeLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        planeDotsLabel->setText(QString());
        planeValueLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        fromDatabaseLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        fromDatabaseDotsLabel->setText(QString());
        newPlaneLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        newPlaneDotsLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        dotsLabel->setText(QApplication::translate("CallibrationSettings", "TextLabel", Q_NULLPTR));
        leftButton->setText(QApplication::translate("CallibrationSettings", "CANCEL", Q_NULLPTR));
        rightButton->setText(QApplication::translate("CallibrationSettings", "CONFIRM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CallibrationSettings: public Ui_CallibrationSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALLIBRATIONSETTINGS_H