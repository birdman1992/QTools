#include "qtools.h"
#include "ui_qtools.h"

QTools::QTools(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTools)
{
    ui->setupUi(this);
}

QTools::~QTools()
{
    delete ui;
}
