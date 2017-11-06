#ifndef QTOOLS_H
#define QTOOLS_H

#include <QWidget>

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
};

#endif // QTOOLS_H
