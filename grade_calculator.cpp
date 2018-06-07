#include "grade_calculator.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include<QMainWindow>
#include<QDebug>
#include<QIcon>

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);


    this->setWindowTitle("Grade Calculator");
    //this->resize(1000,1000);
    QObject::connect(ui->spinbox1, SIGNAL(  valueChanged(int) ),
                     ui->slider1, SLOT(setValue(int) ) );
    QObject::connect(ui->slider1, SIGNAL(  valueChanged(int) ),
                     ui->spinbox1, SLOT(setValue(int) ) );



    QObject::connect(ui->spinbox2, SIGNAL(  valueChanged(int) ),
                     ui->slider2, SLOT(setValue(int) ) );
    QObject::connect(ui->slider2, SIGNAL(  valueChanged(int) ),
                     ui->spinbox2, SLOT(setValue(int) ) );

    QObject::connect(ui->spinbox3, SIGNAL(  valueChanged(int) ),
                     ui->slider3, SLOT(setValue(int) ) );
    QObject::connect(ui->slider3, SIGNAL(  valueChanged(int) ),
                     ui->spinbox3, SLOT(setValue(int) ) );


    QObject::connect(ui->spinbox4, SIGNAL(  valueChanged(int) ),
                     ui->slider4, SLOT(setValue(int) ) );
    QObject::connect(ui->slider4, SIGNAL(  valueChanged(int) ),
                     ui->spinbox4, SLOT(setValue(int) ) );

    QObject::connect(ui->spinbox5, SIGNAL(  valueChanged(int) ),
                     ui->slider5, SLOT(setValue(int) ) );
    QObject::connect(ui->slider5, SIGNAL(  valueChanged(int) ),
                     ui->spinbox5, SLOT(setValue(int) ) );


    QObject::connect(ui->spinbox6, SIGNAL(  valueChanged(int) ),
                     ui->slider6, SLOT(setValue(int) ) );
    QObject::connect(ui->slider6, SIGNAL(  valueChanged(int) ),
                     ui->spinbox6, SLOT(setValue(int) ) );


    QObject::connect(ui->spinbox7, SIGNAL(  valueChanged(int) ),
                     ui->slider7, SLOT(setValue(int) ) );
    QObject::connect(ui->slider7, SIGNAL(  valueChanged(int) ),
                     ui->spinbox7, SLOT(setValue(int) ) );


    QObject::connect(ui->spinbox8, SIGNAL(  valueChanged(int) ),
                     ui->slider8, SLOT(setValue(int) ) );
    QObject::connect(ui->slider8, SIGNAL(  valueChanged(int) ),
                     ui->spinbox8, SLOT(setValue(int) ) );


    QObject::connect(ui->spinbox_m1, SIGNAL(  valueChanged(int) ),
                     ui->slider_m1, SLOT(setValue(int) ) );
    QObject::connect(ui->slider_m1 ,SIGNAL(  valueChanged(int) ),
                     ui->spinbox_m1, SLOT(setValue(int) ) );

    QObject::connect(ui->spinbox_m2, SIGNAL(  valueChanged(int) ),
                     ui->slider_m2, SLOT(setValue(int) ) );
    QObject::connect(ui->slider_m2 ,SIGNAL(  valueChanged(int) ),
                     ui->spinbox_m2, SLOT(setValue(int) ) );

    QObject::connect(ui->spinbox_f, SIGNAL(  valueChanged(int) ),
                     ui->slider_f, SLOT(setValue(int) ) );
    QObject::connect(ui->slider_f ,SIGNAL(  valueChanged(int) ),
                     ui->spinbox_f, SLOT(setValue(int) ) );


    connect(ui->choose,SIGNAL(activated(int)),this,SLOT(clickedaction(int)));
    qDebug("aaa");

     ui->choose->insertItem(0, "Pic 10A:Introduction to Programming");
     ui->choose->insertItem(1, "Pic 10B:Intermediate Programming");
     ui->choose->insertItem(2, "Pic 10C:Advanced Programming");
}



/*
grade_calculator::~grade_calculator()
{
    delete ui;
}
*/


void grade_calculator::update_overall(){

    QString hw1 = ui->spinbox1->text();
    QString hw2 = ui->spinbox2->text();
    QString hw3 = ui->spinbox3->text();
    QString hw4 = ui->spinbox4->text();
    QString hw5 = ui->spinbox5->text();
    QString hw6 = ui->spinbox6->text();
    QString hw7 = ui->spinbox7->text();
    QString hw8 = ui->spinbox8->text();
    QString mid1 = ui->spinbox_m1->text();
    QString mid2 = ui->spinbox_m2->text();
    QString final = ui->spinbox_f->text();

    double h1 = 0;
    double h2 = 0;
    double h3 = 0;
    double h4 = 0;
    double h5 = 0;
    double h6 = 0;
    double h7 = 0;
    double h8 = 0;
    double m1 = 0;
    double m2 = 0;
    double f =  0;

    h1 = hw1.toDouble();
    h2 = hw2.toDouble();
    h3 = hw3.toDouble();
    h4 = hw4.toDouble();
    h5 = hw5.toDouble();
    h6 = hw6.toDouble();
    h7 = hw7.toDouble();
    h8 = hw8.toDouble();
    m1 = mid1.toDouble();
    m2 = mid2.toDouble();
    f = final.toDouble();

    double final_score=0;
    if(schemaA == true)
    {
       final_score=(h1+h2+h3+h4+h5+h6+h7+h8)*0.25 +(m1+m2)*0.2+f*0.35;
    }
    if(schemaA == false)
    {
       if(m1 >m2)
       final_score=(h1+h2+h3+h4+h5+h6+h7+h8)*0.25 +m1*0.3+f*0.44;
       else
           final_score=(h1+h2+h3+h4+h5+h6+h7+h8)*0.25 +m2*0.3+f*0.44;
    }
    ui->final_score->setText(QString::number(final_score));
    return;

}

void grade_calculator::on_schemaA_clicked()
{
    schemaA = true;
    update_overall();
}

void grade_calculator::on_schemaB_clicked()
{
    schemaA = false;
    update_overall();
}

void grade_calculator::on_clear_clicked() //Clear All button
{
    ui->spinbox1->setValue(0);
    ui->spinbox2->setValue(0);
    ui->spinbox3->setValue(0);
    ui->spinbox4->setValue(0);
    ui->spinbox5->setValue(0);
    ui->spinbox6->setValue(0);
    ui->spinbox7->setValue(0);
    ui->spinbox8->setValue(0);
    ui->spinbox_m1->setValue(0);
    ui->spinbox_m2->setValue(0);
    ui->spinbox_f->setValue(0);
    ui->final_score->setText("");
}


