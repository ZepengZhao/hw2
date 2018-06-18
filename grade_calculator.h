#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>

namespace Ui {
    class grade_calculator;
}

class grade_calculator : public QMainWindow
{
    Q_OBJECT

   public:
        explicit grade_calculator(QWidget *parent = 0);
        ~grade_calculator();

public slots:
        void update_overall();

private slots:
    void on_schemaA_clicked();

    void on_clear_clicked();

    void on_schemaB_clicked();

private:
     Ui::grade_calculator *ui;
     bool schemaA = true;
};

#endif // GRADE_CALCULATOR_H
