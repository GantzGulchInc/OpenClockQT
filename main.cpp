#include "simple.h"

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    TestWidget window;

    window.resize(350, 250);
    window.setWindowTitle("Plus Minus");
    window.show();

    return app.exec();
}
