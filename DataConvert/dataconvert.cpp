#include "dataconvert.h"
#include "ui_dataconvert.h"
#include <QMimeData>
#include <QDrag>
#include <QDropEvent>
#include <QDebug>
#include <QFileInfo>
#include <QTextCodec>

DataConvert::DataConvert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataConvert)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    dropFile = NULL;
}

DataConvert::~DataConvert()
{
    delete ui;
}

void DataConvert::on_encrypt_clicked()//点击了开始加密
{
    QByteArray cipherText;
    QByteArray plainText = ui->textHash->text().toLocal8Bit();

    //MD5
    cipherText = QCryptographicHash::hash(plainText, QCryptographicHash::Md5);
    ui->textMd5->setText(cipherText.toHex());

    //MD4
    cipherText = QCryptographicHash::hash(plainText, QCryptographicHash::Md4);
    ui->textMd4->setText(cipherText.toHex());

    cipherText = QCryptographicHash::hash(plainText, QCryptographicHash::Algorithm(ui->encryption->currentIndex()+2));
    ui->textSha->setText(cipherText.toHex());
}

void DataConvert::on_encryption_currentIndexChanged(int index)//切换了加密方式
{
    QByteArray cipherText;
    QByteArray plainText = ui->textHash->text().toLocal8Bit();

    cipherText = QCryptographicHash::hash(plainText, QCryptographicHash::Algorithm(index+2));
    ui->textSha->setText(cipherText.toHex());
}

void DataConvert::dragEnterEvent(QDragEnterEvent *e)
{
    if(e->mimeData()->hasFormat("text/uri-list"))//过滤出文件拖放
    {
        e->acceptProposedAction();
    }
}

void DataConvert::dropEvent(QDropEvent *e)//拖放文件事件
{
    QUrl url = e->mimeData()->urls().at(0);
    getHashOfFile(url);//获取文件哈希
}

void DataConvert::getHashOfFile(QUrl url)//获取文件哈希
{
    QFileInfo fileInfo(url.toLocalFile());
    if(!fileInfo.isFile())
        return;

    if(dropFile != NULL)
    {
        delete dropFile;
        dropFile = NULL;
    }
    ui->textHash->setText(url.toLocalFile());

    dropFile = new QFile(url.toLocalFile());
    QByteArray cipherText;

    cipherText = getFileHash(dropFile, QCryptographicHash::Md5);
    ui->textMd5->setText(cipherText.toHex());

    cipherText = getFileHash(dropFile, QCryptographicHash::Md4);
    ui->textMd4->setText(cipherText.toHex());

    cipherText = getFileHash(dropFile, QCryptographicHash::Algorithm(ui->encryption->currentIndex()+2));
    ui->textSha->setText(cipherText.toHex());

    delete dropFile;
    dropFile = NULL;
}

//获取文件哈希实现
QByteArray DataConvert::getFileHash(QFile* file, QCryptographicHash::Algorithm hash)
{
    if(file == NULL)
        return QByteArray();

    if(!file->open(QFile::ReadOnly))
        return QByteArray();

    QCryptographicHash ch(hash);

    quint64 totalBytes = 0;
    quint64 bytesWritten = 0;
    quint64 bytesToWrite = 0;
    quint64 loadSize = 1024 * 4;
    QByteArray buf;

    totalBytes = file->size();
    bytesToWrite = totalBytes;

    while (1)
    {
        if(bytesToWrite > 0)
        {
            buf = file->read(qMin(bytesToWrite, loadSize));
            ch.addData(buf);
            bytesWritten += buf.length();
            bytesToWrite -= buf.length();
            buf.resize(0);
        }
        else
        {
            break;
        }

        if(bytesWritten == totalBytes)
        {
            break;
        }
        QCoreApplication::processEvents();
    }

    file->close();
    QByteArray md5 = ch.result();

    return md5;
}

void DataConvert::on_encryptBase64_clicked()
{
    QByteArray plainText = ui->plainText->toPlainText().toLocal8Bit();
    ui->cipherText->setText(QString(plainText.toBase64()));
}

void DataConvert::on_decryptBase64_clicked()
{
    QByteArray plainText = QByteArray::fromBase64(ui->cipherText->toPlainText().toLocal8Bit());
    ui->plainText->setText(QString(plainText));
}

void DataConvert::on_textcode_textChanged(const QString &arg1)
{
    QTextCodec *codec;
    QByteArray code;

    codec = QTextCodec::codecForName("UTF-8");
    code = codec->fromUnicode(arg1);
    ui->textUtf8->setText(code.toHex());

    codec = QTextCodec::codecForName("GB18030");
    code = codec->fromUnicode(arg1);
    ui->textGbk->setText(code.toHex());
}
