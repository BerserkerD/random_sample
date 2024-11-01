#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentList.h"
#include <QRandomGenerator>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("随机抽号");
    setFixedSize(500, 400); // 设置固定大小为 400x300 像素
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_executeButton_clicked()
{
    int i = ui->classChoiceBox->currentIndex();
    int size = classList[i].size();
    int random = produce_random_number(size);
    ui->lineEdit->setText(classList[i][random]);
}

int MainWindow::produce_random_number(int upbound)
{
    std::random_device rd;
    std::mt19937 gen(rd()); // 随机数生成器
    std::uniform_int_distribution<> dis(0, upbound-1); // 定义分布范围数
    return dis(gen);
}
