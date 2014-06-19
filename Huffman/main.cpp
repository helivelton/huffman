#include <QDebug>
#include <fileprocessor.h>

int main(int argc, char *argv[])
{
    FileProcessor fp("/home/paulinha/Documents/test.txt");
    int * arr = fp.getFrequency();

    for(int i = 0; i < 256; i++){
        char ch = i;
        qDebug() << "'"<< ch << "'" << " <---> " << arr[i];
    }


}
