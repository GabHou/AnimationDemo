#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QLabel>
#include <QRect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QLabel *labelLeft;
    QLabel *labelRight;
    QLabel *labelCenter;

    QRect rectLeft;
    QRect rectCenter;
    QRect rectRight;
    QList<QRect> listRects;

    QPropertyAnimation* animationLeft;
    QPropertyAnimation* animationRight;
    QPropertyAnimation* animationCenter;
};

#endif // MAINWINDOW_H
