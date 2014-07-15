/********************************************************************************
** Form generated from reading UI file 'ui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_H
#define UI_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UI
{
public:
    QWidget *centralwidget;
    QTreeView *directoryTree;
    QPushButton *actionButton;
    QTextEdit *futureFileName;
    QRadioButton *compressRadio;
    QRadioButton *uncompressRadio;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UI)
    {
        if (UI->objectName().isEmpty())
            UI->setObjectName(QStringLiteral("UI"));
        UI->resize(597, 358);
        centralwidget = new QWidget(UI);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        directoryTree = new QTreeView(centralwidget);
        directoryTree->setObjectName(QStringLiteral("directoryTree"));
        directoryTree->setGeometry(QRect(20, 61, 441, 241));
        actionButton = new QPushButton(centralwidget);
        actionButton->setObjectName(QStringLiteral("actionButton"));
        actionButton->setGeometry(QRect(480, 170, 91, 31));
        futureFileName = new QTextEdit(centralwidget);
        futureFileName->setObjectName(QStringLiteral("futureFileName"));
        futureFileName->setGeometry(QRect(480, 70, 104, 21));
        compressRadio = new QRadioButton(centralwidget);
        compressRadio->setObjectName(QStringLiteral("compressRadio"));
        compressRadio->setGeometry(QRect(110, 20, 91, 31));
        uncompressRadio = new QRadioButton(centralwidget);
        uncompressRadio->setObjectName(QStringLiteral("uncompressRadio"));
        uncompressRadio->setGeometry(QRect(240, 20, 131, 31));
        UI->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UI->setStatusBar(statusbar);

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QMainWindow *UI)
    {
        UI->setWindowTitle(QApplication::translate("UI", "MainWindow", 0));
        actionButton->setText(QApplication::translate("UI", "Comprimir", 0));
        compressRadio->setText(QApplication::translate("UI", "Compress\303\243o", 0));
        uncompressRadio->setText(QApplication::translate("UI", "Descompress\303\243o", 0));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
