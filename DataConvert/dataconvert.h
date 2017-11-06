#ifndef DATACONVERT_H
#define DATACONVERT_H

#include <QWidget>

namespace Ui {
class DataConvert;
}

class DataConvert : public QWidget
{
    Q_OBJECT

public:
    explicit DataConvert(QWidget *parent = 0);
    ~DataConvert();

private:
    Ui::DataConvert *ui;
};

#endif // DATACONVERT_H
