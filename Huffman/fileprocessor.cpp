#include "fileprocessor.h"
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QTextStream>
#include <QFileInfo>

FileProcessor::FileProcessor()
{
}

FileProcessor::FileProcessor(QFile file)
{
}

FileProcessor::FileProcessor(QString fileName)
{
    QFile * file = new QFile(fileName);
    QFileInfo fileInfo(file->fileName());
    setFileName(fileInfo.fileName());
    setFile(file);
}

FileProcessor::~FileProcessor()
{
}

QByteArray FileProcessor::byteArray()
{
    m_file->open(QIODevice::ReadOnly);

    QByteArray byteArray = file()->readAll();

    m_file->close();

    return byteArray;
}

int * FileProcessor::getFrequency(){

    if(file()->exists()){

        QByteArray byteArray = this->byteArray();

        int * frequencyArray = new int[256];

        for(int i = 0;i < 256; i++) frequencyArray[i]=0;


        for(int i = 0; i < byteArray.size(); i++){
            frequencyArray[(int)((unsigned char) byteArray[i])]++;
        }

        return frequencyArray;
        delete []frequencyArray;

    } else {
        qDebug() << "Arquivo não encontrado!";
    }

}

QFile * FileProcessor::file(){
    return m_file;
}

QString FileProcessor::fileName(){
    return m_filename;
}

void FileProcessor::setFileName(QString fileName){
    m_filename = fileName;
}

void FileProcessor::setFile(QFile * file){
    m_file = file;
}
