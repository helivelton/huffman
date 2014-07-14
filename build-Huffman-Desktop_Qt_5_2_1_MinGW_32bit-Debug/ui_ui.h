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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QPushButton *compressButton;
    QTextEdit *futureFileName;
    QMenuBar *menubar;
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
        compressButton = new QPushButton(centralwidget);
        compressButton->setObjectName(QStringLiteral("compressButton"));
        compressButton->setGeometry(QRect(490, 140, 75, 23));
        futureFileName = new QTextEdit(centralwidget);
        futureFileName->setObjectName(QStringLiteral("futureFileName"));
        futureFileName->setGeometry(QRect(480, 70, 104, 21));
        UI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UI);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 597, 21));
        UI->setMenuBar(menubar);
        statusbar = new QStatusBar(UI);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UI->setStatusBar(statusbar);

        retranslateUi(UI);

        QMetaObject::connectSlotsByName(UI);
    } // setupUi

    void retranslateUi(QMainWindow *UI)
    {
        UI->setWindowTitle(QApplication::translate("UI", "MainWindow", 0));
        compressButton->setText(QApplication::translate("UI", "Comprimir", 0));
    } // retranslateUi

};

namespace Ui {
    class UI: public Ui_UI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_H
