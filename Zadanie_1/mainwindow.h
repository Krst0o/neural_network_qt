#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMainWindow>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void buttonChangeBackgroundColor();

private:
    Ui::MainWindow *ui;

    QPushButton* buttons[7][5];
    QLabel* result;
    bool buttonClicked[7][5];
    QGridLayout *controlsLayout;

    void createControls();
    void setVariables();
    void launchProgram();
};
#endif // MAINWINDOW_H
