#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QMainWindow>
#include <QFileSystemModel>
namespace Ui {
class UserInterface;
}

class UserInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = 0);
    ~UserInterface();

private slots:
    void on_compressRadio_clicked();

    void on_uncompressRadio_clicked();

    void on_filesTree_clicked(const QModelIndex &index);

    void on_actionButton_clicked();

private:
    Ui::UserInterface *ui;
    QFileSystemModel * dirModel;
};

#endif // USERINTERFACE_H
