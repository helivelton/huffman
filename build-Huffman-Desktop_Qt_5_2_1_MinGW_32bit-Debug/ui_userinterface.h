/********************************************************************************
** Form generated from reading UI file 'userinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    QWidget *centralwidget;
    QRadioButton *compressRadio;
    QRadioButton *uncompressRadio;
    QPushButton *actionButton;
    QTreeView *filesTree;
    QLineEdit *destinyPathLine;
    QLineEdit *resourcePathLine;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QStringLiteral("UserInterface"));
        UserInterface->resize(640, 480);
        centralwidget = new QWidget(UserInterface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        compressRadio = new QRadioButton(centralwidget);
        compressRadio->setObjectName(QStringLiteral("compressRadio"));
        compressRadio->setGeometry(QRect(130, 20, 82, 17));
        uncompressRadio = new QRadioButton(centralwidget);
        uncompressRadio->setObjectName(QStringLiteral("uncompressRadio"));
        uncompressRadio->setGeometry(QRect(270, 20, 101, 17));
        actionButton = new QPushButton(centralwidget);
        actionButton->setObjectName(QStringLiteral("actionButton"));
        actionButton->setGeometry(QRect(530, 90, 75, 23));
        filesTree = new QTreeView(centralwidget);
        filesTree->setObjectName(QStringLiteral("filesTree"));
        filesTree->setGeometry(QRect(20, 130, 501, 201));
        destinyPathLine = new QLineEdit(centralwidget);
        destinyPathLine->setObjectName(QStringLiteral("destinyPathLine"));
        destinyPathLine->setGeometry(QRect(80, 90, 441, 20));
        resourcePathLine = new QLineEdit(centralwidget);
        resourcePathLine->setObjectName(QStringLiteral("resourcePathLine"));
        resourcePathLine->setGeometry(QRect(80, 60, 441, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 46, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 46, 13));
        UserInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserInterface);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 21));
        UserInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(UserInterface);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserInterface->setStatusBar(statusbar);

        retranslateUi(UserInterface);

        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterface)
    {
        UserInterface->setWindowTitle(QApplication::translate("UserInterface", "MainWindow", 0));
        compressRadio->setText(QApplication::translate("UserInterface", "Comprimir", 0));
        uncompressRadio->setText(QApplication::translate("UserInterface", "Descomprimir", 0));
        actionButton->setText(QApplication::translate("UserInterface", "Executar", 0));
        label->setText(QApplication::translate("UserInterface", "Origem", 0));
        label_2->setText(QApplication::translate("UserInterface", "Destino", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
