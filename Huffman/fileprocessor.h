#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QFile>
#include <QString>
#include <QByteArray>

class FileProcessor
{
public:
    FileProcessor();
    ~FileProcessor();
    FileProcessor(QFile file);
    FileProcessor(QString fileName);
    int * getFrequency();

    QFile * file();
    QString fileName();
    void setFileName(QString fileName);
    void setFile(QFile * file);
    QByteArray byteArray();


private:
    //arquivo
    QFile * m_file;
    //nome do arquivo
    QString m_filename;
};

#endif // FILEPROCESSOR_H
