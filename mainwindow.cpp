#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

#define IMAGE_WIDTH 200
#define IMAGE_HEIGHT 186

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pixMap(":/image/timg.jpg");
    labelLeft = new QLabel(this);
    labelLeft->setPixmap(pixMap.copy(0,0,IMAGE_WIDTH,IMAGE_HEIGHT));
    labelLeft->setGeometry(20,20,IMAGE_WIDTH/2,IMAGE_HEIGHT);
    rectLeft.setRect(20,20,IMAGE_WIDTH/2,IMAGE_HEIGHT);

    labelCenter = new QLabel(this);
    labelCenter->setPixmap(pixMap.copy(IMAGE_WIDTH,0,IMAGE_WIDTH,IMAGE_HEIGHT));
    labelCenter->setGeometry(20+IMAGE_WIDTH/2,20,IMAGE_WIDTH,IMAGE_HEIGHT);
    labelCenter->raise();
    rectCenter.setRect(20+IMAGE_WIDTH/2,20,IMAGE_WIDTH,IMAGE_HEIGHT);

    labelRight = new QLabel(this);
    labelRight->setPixmap(pixMap.copy(IMAGE_WIDTH*2,0,IMAGE_WIDTH,IMAGE_HEIGHT));
    labelRight->setGeometry(20+IMAGE_WIDTH/2+IMAGE_WIDTH,20,IMAGE_WIDTH/2,IMAGE_HEIGHT);
    rectRight.setRect(20+IMAGE_WIDTH/2+IMAGE_WIDTH,20,IMAGE_WIDTH/2,IMAGE_HEIGHT);

    animationLeft = new QPropertyAnimation(labelLeft, "geometry");
    animationLeft->setDuration(200);
    animationLeft->setEasingCurve(QEasingCurve::Linear);

    animationCenter = new QPropertyAnimation(labelCenter, "geometry");
    animationCenter->setDuration(200);
    animationCenter->setEasingCurve(QEasingCurve::Linear);

    animationRight = new QPropertyAnimation(labelRight, "geometry");
    animationRight->setDuration(200);
    animationRight->setEasingCurve(QEasingCurve::Linear);

    listRects<<rectLeft<<rectCenter<<rectRight;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    animationLeft->setStartValue(listRects.at(0));
    animationLeft->setEndValue(listRects.at(2));
    animationLeft->start();

    animationCenter->setStartValue(listRects.at(1));
    animationCenter->setEndValue(listRects.at(0));
    animationCenter->start();

    animationRight->setStartValue(listRects.at(2));
    animationRight->setEndValue(listRects.at(1));
    animationRight->start();

    labelCenter->raise();

    QRect temp0 = listRects.at(0);
    QRect temp1 = listRects.at(1);
    QRect temp2 = listRects.at(2);
    listRects.clear();
    listRects<<temp1<<temp2<<temp0;
}

void MainWindow::on_toolButton_2_clicked()
{
    animationLeft->setStartValue(listRects.at(0));
    animationLeft->setEndValue(listRects.at(1));
    animationLeft->start();

    animationCenter->setStartValue(listRects.at(1));
    animationCenter->setEndValue(listRects.at(2));
    animationCenter->start();

    animationRight->setStartValue(listRects.at(2));
    animationRight->setEndValue(listRects.at(0));
    animationRight->start();

    labelCenter->raise();

    QRect temp0 = listRects.at(0);
    QRect temp1 = listRects.at(1);
    QRect temp2 = listRects.at(2);
    listRects.clear();
    listRects<<temp2<<temp0<<temp1;
}
