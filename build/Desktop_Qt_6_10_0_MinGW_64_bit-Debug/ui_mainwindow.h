/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *leftLayout;
    QTabWidget *tabWidget;
    QWidget *tabPersonal;
    QFormLayout *formLayout;
    QLabel *labelName;
    QLineEdit *nameEdit;
    QLabel *labelEmail;
    QLineEdit *emailEdit;
    QLabel *labelPhone;
    QLineEdit *phoneEdit;
    QLabel *labelAddress;
    QLineEdit *addressEdit;
    QLabel *labelSummary;
    QTextEdit *summaryEdit;
    QLabel *labelPhoto;
    QHBoxLayout *photoLayout;
    QLineEdit *photoPathEdit;
    QPushButton *browsePhotoButton;
    QWidget *tabEducation;
    QVBoxLayout *eduLayout;
    QTableWidget *eduTable;
    QHBoxLayout *eduButtons;
    QPushButton *addEduButton;
    QPushButton *removeEduButton;
    QSpacerItem *eduSpacer;
    QWidget *tabExperience;
    QVBoxLayout *expLayout;
    QTableWidget *expTable;
    QHBoxLayout *expButtons;
    QPushButton *addExpButton;
    QPushButton *removeExpButton;
    QSpacerItem *expSpacer;
    QWidget *tabSkills;
    QVBoxLayout *skillLayout;
    QTableWidget *skillTable;
    QHBoxLayout *skillButtons;
    QPushButton *addSkillButton;
    QPushButton *removeSkillButton;
    QSpacerItem *skillSpacer;
    QWidget *tabTemplate;
    QFormLayout *templateLayout;
    QLabel *labelTemplate;
    QComboBox *templateCombo;
    QHBoxLayout *actionButtons;
    QPushButton *generateButton;
    QPushButton *exportHtmlButton;
    QPushButton *exportPdfButton;
    QSpacerItem *bottomSpacer;
    QWidget *rightPanel;
    QVBoxLayout *rightLayout;
    QTextBrowser *previewBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout->addWidget(titleLabel);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName("leftPanel");
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(leftPanel);
        tabWidget->setObjectName("tabWidget");
        tabPersonal = new QWidget();
        tabPersonal->setObjectName("tabPersonal");
        formLayout = new QFormLayout(tabPersonal);
        formLayout->setObjectName("formLayout");
        labelName = new QLabel(tabPersonal);
        labelName->setObjectName("labelName");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelName);

        nameEdit = new QLineEdit(tabPersonal);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nameEdit);

        labelEmail = new QLabel(tabPersonal);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelEmail);

        emailEdit = new QLineEdit(tabPersonal);
        emailEdit->setObjectName("emailEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, emailEdit);

        labelPhone = new QLabel(tabPersonal);
        labelPhone->setObjectName("labelPhone");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelPhone);

        phoneEdit = new QLineEdit(tabPersonal);
        phoneEdit->setObjectName("phoneEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, phoneEdit);

        labelAddress = new QLabel(tabPersonal);
        labelAddress->setObjectName("labelAddress");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelAddress);

        addressEdit = new QLineEdit(tabPersonal);
        addressEdit->setObjectName("addressEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, addressEdit);

        labelSummary = new QLabel(tabPersonal);
        labelSummary->setObjectName("labelSummary");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelSummary);

        summaryEdit = new QTextEdit(tabPersonal);
        summaryEdit->setObjectName("summaryEdit");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, summaryEdit);

        labelPhoto = new QLabel(tabPersonal);
        labelPhoto->setObjectName("labelPhoto");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelPhoto);

        photoLayout = new QHBoxLayout();
        photoLayout->setObjectName("photoLayout");
        photoPathEdit = new QLineEdit(tabPersonal);
        photoPathEdit->setObjectName("photoPathEdit");

        photoLayout->addWidget(photoPathEdit);

        browsePhotoButton = new QPushButton(tabPersonal);
        browsePhotoButton->setObjectName("browsePhotoButton");

        photoLayout->addWidget(browsePhotoButton);


        formLayout->setLayout(5, QFormLayout::ItemRole::FieldRole, photoLayout);

        tabWidget->addTab(tabPersonal, QString());
        tabEducation = new QWidget();
        tabEducation->setObjectName("tabEducation");
        eduLayout = new QVBoxLayout(tabEducation);
        eduLayout->setObjectName("eduLayout");
        eduTable = new QTableWidget(tabEducation);
        eduTable->setObjectName("eduTable");

        eduLayout->addWidget(eduTable);

        eduButtons = new QHBoxLayout();
        eduButtons->setObjectName("eduButtons");
        addEduButton = new QPushButton(tabEducation);
        addEduButton->setObjectName("addEduButton");

        eduButtons->addWidget(addEduButton);

        removeEduButton = new QPushButton(tabEducation);
        removeEduButton->setObjectName("removeEduButton");

        eduButtons->addWidget(removeEduButton);

        eduSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        eduButtons->addItem(eduSpacer);


        eduLayout->addLayout(eduButtons);

        tabWidget->addTab(tabEducation, QString());
        tabExperience = new QWidget();
        tabExperience->setObjectName("tabExperience");
        expLayout = new QVBoxLayout(tabExperience);
        expLayout->setObjectName("expLayout");
        expTable = new QTableWidget(tabExperience);
        expTable->setObjectName("expTable");

        expLayout->addWidget(expTable);

        expButtons = new QHBoxLayout();
        expButtons->setObjectName("expButtons");
        addExpButton = new QPushButton(tabExperience);
        addExpButton->setObjectName("addExpButton");

        expButtons->addWidget(addExpButton);

        removeExpButton = new QPushButton(tabExperience);
        removeExpButton->setObjectName("removeExpButton");

        expButtons->addWidget(removeExpButton);

        expSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        expButtons->addItem(expSpacer);


        expLayout->addLayout(expButtons);

        tabWidget->addTab(tabExperience, QString());
        tabSkills = new QWidget();
        tabSkills->setObjectName("tabSkills");
        skillLayout = new QVBoxLayout(tabSkills);
        skillLayout->setObjectName("skillLayout");
        skillTable = new QTableWidget(tabSkills);
        skillTable->setObjectName("skillTable");

        skillLayout->addWidget(skillTable);

        skillButtons = new QHBoxLayout();
        skillButtons->setObjectName("skillButtons");
        addSkillButton = new QPushButton(tabSkills);
        addSkillButton->setObjectName("addSkillButton");

        skillButtons->addWidget(addSkillButton);

        removeSkillButton = new QPushButton(tabSkills);
        removeSkillButton->setObjectName("removeSkillButton");

        skillButtons->addWidget(removeSkillButton);

        skillSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        skillButtons->addItem(skillSpacer);


        skillLayout->addLayout(skillButtons);

        tabWidget->addTab(tabSkills, QString());
        tabTemplate = new QWidget();
        tabTemplate->setObjectName("tabTemplate");
        templateLayout = new QFormLayout(tabTemplate);
        templateLayout->setObjectName("templateLayout");
        labelTemplate = new QLabel(tabTemplate);
        labelTemplate->setObjectName("labelTemplate");

        templateLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelTemplate);

        templateCombo = new QComboBox(tabTemplate);
        templateCombo->setObjectName("templateCombo");

        templateLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, templateCombo);

        tabWidget->addTab(tabTemplate, QString());

        leftLayout->addWidget(tabWidget);

        actionButtons = new QHBoxLayout();
        actionButtons->setObjectName("actionButtons");
        generateButton = new QPushButton(leftPanel);
        generateButton->setObjectName("generateButton");

        actionButtons->addWidget(generateButton);

        exportHtmlButton = new QPushButton(leftPanel);
        exportHtmlButton->setObjectName("exportHtmlButton");

        actionButtons->addWidget(exportHtmlButton);

        exportPdfButton = new QPushButton(leftPanel);
        exportPdfButton->setObjectName("exportPdfButton");

        actionButtons->addWidget(exportPdfButton);

        bottomSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionButtons->addItem(bottomSpacer);


        leftLayout->addLayout(actionButtons);

        splitter->addWidget(leftPanel);
        rightPanel = new QWidget(splitter);
        rightPanel->setObjectName("rightPanel");
        rightLayout = new QVBoxLayout(rightPanel);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, 0, 0);
        previewBrowser = new QTextBrowser(rightPanel);
        previewBrowser->setObjectName("previewBrowser");

        rightLayout->addWidget(previewBrowser);

        splitter->addWidget(rightPanel);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ResumeCraft", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "<h1 style=\"text-align:center;color:#0078D7;margin:8px 0;\">ResumeCraft</h1>", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "Name*", nullptr));
        labelEmail->setText(QCoreApplication::translate("MainWindow", "Email*", nullptr));
        labelPhone->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        labelAddress->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        labelSummary->setText(QCoreApplication::translate("MainWindow", "Summary", nullptr));
        labelPhoto->setText(QCoreApplication::translate("MainWindow", "Photo", nullptr));
        browsePhotoButton->setText(QCoreApplication::translate("MainWindow", "Browse\342\200\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPersonal), QCoreApplication::translate("MainWindow", "Personal Info", nullptr));
        addEduButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeEduButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabEducation), QCoreApplication::translate("MainWindow", "Education", nullptr));
        addExpButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeExpButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExperience), QCoreApplication::translate("MainWindow", "Experience", nullptr));
        addSkillButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeSkillButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSkills), QCoreApplication::translate("MainWindow", "Skills", nullptr));
        labelTemplate->setText(QCoreApplication::translate("MainWindow", "Choose Template", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTemplate), QCoreApplication::translate("MainWindow", "Template", nullptr));
        generateButton->setText(QCoreApplication::translate("MainWindow", "Generate Resume", nullptr));
        exportHtmlButton->setText(QCoreApplication::translate("MainWindow", "Export HTML", nullptr));
        exportPdfButton->setText(QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
