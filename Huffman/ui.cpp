#include "ui.h"
#include "ui_ui.h"
#include "huffcompressor.h"

UI::UI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UI)
{
    ui->setupUi(this);


    QDir * actual_directory = new QDir();
    QString startPath = actual_directory->absolutePath();

    dirmodel = new QFileSystemModel(this);
    dirmodel->setRootPath(startPath);
    ui->directoryTree->setModel(dirmodel);

}

UI::~UI()
{
    delete ui;
}

void UI::on_directoryTree_clicked(const QModelIndex &index)
{
    m_selectedFile = dirmodel->filePath(index);

    QFile * file = new QFile(m_selectedFile);
    QFileInfo fileInfo(file->fileName());

    ui->futureFileName->setText(fileInfo.fileName());

}

void UI::on_compressButton_clicked()
{
    QFile * file = new QFile(m_selectedFile);
    QFileInfo fileInfo(file->fileName());

    QDir * actual_directory = new QDir();
    QString directory = actual_directory->absoluteFilePath(m_selectedFile);
    directory = directory.remove(fileInfo.fileName(),Qt::CaseSensitive);
    QString compressed = "";

}




void UI::on_uncompressRadio_clicked()
{
    ui->actionButton->setText("Des");
}


void UI::on_compressRadio_clicked()
{
    ui->actionButton->setText("Comprimir");
}

void UI::on_actionButton_clicked()
{
    ui->actionButton->setText("teste");
}
