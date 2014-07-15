#ifndef UI_H
#define UI_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <qfilesystemmodel.h>

namespace Ui {
class UI;
}

class UI : public QMainWindow
{
    Q_OBJECT

public:
    explicit UI(QWidget *parent = 0);
    ~UI();

private slots:


    void on_directoryTree_clicked(const QModelIndex &index);

    void on_compressButton_clicked();

    void on_radioButton_clicked();

    void on_compressRadio_clicked();

    void on_uncompressRadio_clicked();

    void on_actionButton_clicked();

private:
    Ui::UI *ui;
    QFileSystemModel * dirmodel;
    QFileSystemModel * filemodel;
    QString m_selectedFile;

};

#endif // UI_H
