#ifndef DATACONVERT_H
#define DATACONVERT_H

#include <QWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QUrl>
#include <QFile>
#include <QCryptographicHash>

namespace Ui {
class DataConvert;
}

class DataConvert : public QWidget
{
    Q_OBJECT

public:
    explicit DataConvert(QWidget *parent = 0);
    ~DataConvert();

private slots:
    void on_encrypt_clicked();
    void on_encryption_currentIndexChanged(int index);

    void on_encryptBase64_clicked();

    void on_decryptBase64_clicked();

    void on_textcode_textChanged(const QString &arg1);

protected:
    void dragEnterEvent(QDragEnterEvent* e);
    void dropEvent(QDropEvent* e);

private:
    Ui::DataConvert *ui;
    QFile* dropFile;

    void getHashOfFile(QUrl url);
    QByteArray getFileHash(QFile* file,QCryptographicHash::Algorithm hash);
};

#endif // DATACONVERT_H
