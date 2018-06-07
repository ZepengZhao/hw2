#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include "grade_calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    grade_calculator w1;

    w1.show();

    return app.exec();
}
