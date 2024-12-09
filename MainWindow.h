#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "ui_MainWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateFrame();             
    void onCaptureButtonClicked();    

private:
    Ui_MainWindow *ui;             
    cv::VideoCapture camera;        
    QTimer *timer;        
};
#endif 