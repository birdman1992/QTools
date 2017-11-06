#include "dataconvert.h"
#include "ui_dataconvert.h"
#include <QCryptographicHash>

DataConvert::DataConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataConvert)
{
    ui->setupUi(this);
}

DataConvert::~DataConvert()
{
    delete ui;
}

void DataConvert::on_encrypt_clicked()
{
    QByteArray qba = QByteArray(ui->text->text());
    ui->textMd5->setText(qba);
    QCryptographicHash::hash ( qba, QCryptographicHash::Md5 );
}
