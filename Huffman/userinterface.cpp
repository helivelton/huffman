#include "userinterface.h"
#include "ui_userinterface.h"
#include "huffcompressor.h"

UserInterface::UserInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->setWindowTitle("Huffman");

    dirModel = new QFileSystemModel(this);
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::on_compressRadio_clicked()
{
    dirModel = new QFileSystemModel();
    dirModel->setFilter(QDir::Files | QDir::AllDirs);
    dirModel->setRootPath("/");

    ui->actionButton->setText("Comprimir");
    ui->filesTree->setModel(dirModel);
}

void UserInterface::on_uncompressRadio_clicked()
{

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::Files | QDir::AllDirs);
    dirModel->setRootPath("/");
    QStringList filter;
    filter << "*.huff";

    dirModel->setNameFilters(filter);
    dirModel->setNameFilterDisables(false);

    ui->actionButton->setText("Descomprimir");
    ui->filesTree->setModel(dirModel);
}

void UserInterface::on_filesTree_clicked(const QModelIndex &index)
{
    QString option = ui->actionButton->text();

    if(option=="Comprimir")
    {
        QString selectedPath = dirModel->fileInfo(index).absoluteFilePath();
        QString compactedPath = selectedPath;
        compactedPath.remove(compactedPath.lastIndexOf('.'),compactedPath.size()-compactedPath.lastIndexOf('.'));
        compactedPath.append(".huff");
        ui->resourcePathLine->setText(selectedPath);
        ui->destinyPathLine->setText(compactedPath);

    }

    if(option=="Descomprimir")
    {
        QString selectedPath = dirModel->fileInfo(index).absoluteFilePath();
        QString destinyPath = selectedPath;
        destinyPath.remove(destinyPath.lastIndexOf('/')+1,destinyPath.size()-destinyPath.lastIndexOf('/'));

        ui->resourcePathLine->setText(selectedPath);
        ui->destinyPathLine->setText(destinyPath);
    }



//    HuffCompressor * compressor = new HuffCompressor();
//    compressor->compress(selectedPath, compactedPath);
//    compressor->uncompress("/home/paulinha/Desktop/tela.huff", "/home/paulinha/Desktop/tela.png");

}

void UserInterface::on_actionButton_clicked()
{

    QString option = ui->actionButton->text();

    if(option=="Comprimir")
    {
        QString selectedPath = ui->resourcePathLine->text();
        QString destinyPath = ui->destinyPathLine->text();
        HuffCompressor * compressor = new HuffCompressor();
        compressor->compress(selectedPath, destinyPath);

    }

    if(option=="Descomprimir")
    {
        QString selectedPath = ui->resourcePathLine->text();
        QString destinyPath = ui->destinyPathLine->text();
        HuffCompressor * compressor = new HuffCompressor();
        compressor->uncompress(selectedPath, destinyPath);

    }

}
