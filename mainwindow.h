#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double funcion(double c);
    double A[4];
    double B[4];
    double Fun[4];
private:
    Ui::MainWindow *ui;
public slots:
    void metodo(); //Slot que realiza el método de gauss-seidel
    void limpiar(); //Slot that erases the contents of the spinbox and text
};

#endif // MAINWINDOW_H
