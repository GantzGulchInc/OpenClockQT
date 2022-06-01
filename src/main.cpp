#include "OpenClockWindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    OpenClockWindow window;

    window.resize(350, 250);
    window.setWindowTitle("OpenClockQT");
    window.show();

    return app.exec();
}
