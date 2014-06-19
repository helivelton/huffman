#include "fileprocessor.h"
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QDebug>

FileProcessor::FileProcessor()
{
}

FileProcessor::FileProcessor(QFile file)
{
}

FileProcessor::FileProcessor(QString fileName)
{
    setFileName(fileName);
    QFile * file = new QFile(fileName);
    setFile(file);
}

FileProcessor::~FileProcessor()
{
}

int * FileProcessor::getFrequency(){

    if(file()->exists()){

        m_file->open(QIODevice::ReadOnly);

        QByteArray byteArray = file()->readAll();

        int * frequencyArray = new int[256];

        for(int i = 0; i < byteArray.size(); i++){
            frequencyArray[byteArray[i]]++;
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
