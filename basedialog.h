#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>

namespace Ui {
class BaseDialog;
}

class BaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BaseDialog(QWidget *parent = 0);
    ~BaseDialog();

private:
    Ui::BaseDialog *ui;
};

#endif // BASEDIALOG_H
