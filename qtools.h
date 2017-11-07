#ifndef QTOOLS_H
#define QTOOLS_H

#include <QWidget>
#include <DataConvert/dataconvert.h>

namespace Ui {
class QTools;
}

class QTools : public QWidget
{
    Q_OBJECT

public:
    explicit QTools(QWidget *parent = 0);
    ~QTools();

private:
    Ui::QTools *ui;
    DataConvert* winDataConvert;

    void winListInit();//初始化窗口列表
    void winStackInit();//初始化窗口分页
};

#endif // QTOOLS_H
