#include "MainWindow.h"

#include <QImage>
#include <QTimer>
#include <QFileDialog>
#include <opencv2/opencv.hpp>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  
    camera.open(0);  
    if (!camera.isOpened()) {
        qDebug() << "Error: Camera not found!";
        return;
    }

 
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateFrame);
    timer->start(30);

    connect(ui->capture, &QPushButton::clicked, this, &MainWindow::onCaptureButtonClicked);

      
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateFrame()
{
    cv::Mat frame;
    camera >> frame;  

    if (frame.empty()) {
        qDebug() << "Error: Failed to grab frame";
        return;
    }

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

   
   QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(image));
}


void MainWindow::onCaptureButtonClicked()
{
    cv::Mat frame;
    camera >> frame;

    if (frame.empty()) {
        qDebug() << "Error: Failed to capture image";
        return;
    }

    cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);
     
    QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.xpm *.jpg)");
    if (!fileName.isEmpty()) {
       
        cv::imwrite("C:\\Users\\DT804\\Pictures\\test.jpg", frame);
        qDebug() << "Image saved to" <<"C:\\Users\\DT804\\Pictures\\test.jpg";
    }
}

