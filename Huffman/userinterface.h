#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QtWidgets/QDialog>

namespace Ui {
class UserInterface;
}

class UserInterface : public QDialog
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = 0);
    ~UserInterface();

private:
    Ui::UserInterface *ui;
};

#endif // USERINTERFACE_H
