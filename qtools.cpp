#include "qtools.h"
#include "ui_qtools.h"
#include <QStringList>

QTools::QTools(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTools)
{
    ui->setupUi(this);

    winListInit();
    winStackInit();

    connect(ui->winList, &QListWidget::currentRowChanged, ui->winStack, &QStackedWidget::setCurrentIndex);
}

QTools::~QTools()
{
    delete ui;
}

//此函数初始化主界面窗口切换选项卡
void QTools::winListInit()
{
    QStringList winNameList;
    winNameList<<"数据转换";

    ui->winList->addItems(winNameList);
}

//此函数初始化主界面窗口分页
void QTools::winStackInit()
{
    winDataConvert = new DataConvert(this);

    ui->winStack->addWidget(winDataConvert);
}
