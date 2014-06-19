#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QFile>
#include <QString>

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

private:
    //arquivo
    QFile * m_file;
    //nome do arquivo
    QString m_filename;
};



#endif // FILEPROCESSOR_H
