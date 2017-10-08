#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>  //Bookstore for the use of text strings
#include <cmath>    //Library for use of mathematical functions
#include "QDoubleSpinBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connections of the buttons to use.
    // each button with its corresponding name to be able to perform the manipulation of these.
    connect(ui->met,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->limpiar,SIGNAL(clicked()),this,SLOT(limpiar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::metodo (){   // method to use to solve the program
    QString temp, temp1, temp2, temp3;
    double X1=ui->x1->value();//In this part, we take the value of the spinbox and pass it to a variable
    double X2=ui->x2->value();
    double X3=ui->x3->value();
    double X4=ui->x4->value();
    double F1=ui->f1->value();
    double F2=ui->f2->value();
    double F3=ui->f3->value();
    double F4=ui->f4->value();
    double X=ui->x->value();
    double F, M;         //We declare variables that are dealt with in the program
    int i=0, j=0, n;
    A[0]=X1;A[1]=X2;A[2]=X3;A[3]=X4;  // We add the value of the variables to a vector
    B[0]=F1;B[1]=F2;B[2]=F3;B[3]=F4;
    for(n=1;n<4;n++) // for that is used by knowing the number of iterations
    {   M=0;

        for(i=0;i<=n;i++)  //for which it is used to make the sum of the terms and take control of Xi
        { F=1.00;
          for(j=0;j<=n;j++)  //for that is used to make the products
          {
              if(i!=j) //prevents the denominator from being converted 0 and therefore the program does not work
              {
                  F=F*((X-A[j])/(A[i]-A[j]));  //Formula to calculate products
              }
          }
            F=F*B[i]; //multiplication of the product that was previously obtained by the value of f (x)
            M=M+F;   //Sum of products

        }
        Fun[n]=M;  //The result of each polynomial in the vector

    }
    //F=(((X-X2)/(X1-X2))*F1)+(((X-X1)/(X2-X1))*F2);   //Helpers to compare the program to work correctly
    //F11=(((X-X2)/(X1-X2))*((X-X3)/(X1-X3))*F1)+(((X-X1)/(X2-X1))*((X-X3)/(X2-X3))*F2)+(((X-X1)/(X3-X1))*((X-X2)/(X3-X2))*F3);
   temp.append("\nFunción1=").append(temp1.setNum(Fun[1])).append("\nFunción2=").append(temp2.setNum(Fun[2])).append("\nFunción3=").append(temp3.setNum(Fun[3]));
    ui->texto->setText(temp);
}
 void MainWindow::limpiar(){
     ui->x1->setValue(0.0);
     ui->x2->setValue(0.0);
     ui->x3->setValue(0.0);
     ui->x4->setValue(0.0);
     ui->f1->setValue(0.0);
     ui->f2->setValue(0.0);
     ui->f3->setValue(0.0);
     ui->f4->setValue(0.0);
     ui->x->setValue(0.0);
     ui->texto->clear();     //Text is deleted

 }
