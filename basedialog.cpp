#include "basedialog.h"
#include "ui_basedialog.h"

BaseDialog::BaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseDialog)
{
    ui->setupUi(this);
}

BaseDialog::~BaseDialog()
{
    delete ui;
}
