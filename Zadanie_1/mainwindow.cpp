#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QCoreApplication>
#include <QPainter>
#include <QMouseEvent>
#include <QCoreApplication>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    launchProgram();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::launchProgram(){
    createControls();
    setVariables();
}

void MainWindow::setVariables(){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 5; j++){
        //set buttons as unclicked
            buttonClicked[i][j] = false;
        }
    }
}

void MainWindow::createControls(){
    controlsLayout = new QGridLayout();
    //Creating buttons
    int count = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 5; j++)
        {
            buttons[i][j] = new QPushButton("", this);
            buttons[i][j]->resize(40, 40);
            buttons[i][j]->move(40*j+20, 40*i+20);
            buttons[i][j]->setObjectName("Pushbutton" + QString::number(count));
            connect(buttons[i][j], SIGNAL(clicked()), this, SLOT(buttonChangeBackgroundColor()));
            controlsLayout->addWidget(buttons[i][j],i,j);
            count++;
        }
    }
    //Creating label
    result = new QLabel(this);
    result->setText("Result: ");
    result->move(300, 150);
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
        {
        }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
        {
        }
}

void MainWindow::buttonChangeBackgroundColor(){
    //Clicked button
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    //Get row and column of clicked button
    int i = controlsLayout->indexOf(buttonSender)/5;
    int j = controlsLayout->indexOf(buttonSender)%5;
    if(buttonClicked[i][j]){
        buttonSender->setStyleSheet("QPushButton{ background-color: white }");
        buttonClicked[i][j] = !buttonClicked[i][j];
    }
    else{
        buttonSender->setStyleSheet("QPushButton{ background-color: black }");
        buttonClicked[i][j] = !buttonClicked[i][j];
    }
}
