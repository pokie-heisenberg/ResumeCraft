#include <QApplication>
#include <QIcon>
#include "include/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setApplicationName("ResumeCraft");
    QApplication::setOrganizationName("ResumeCraft");

    ResumeCraft::MainWindow w;
    w.setWindowTitle("ResumeCraft");
    w.setWindowIcon(QIcon());
    w.resize(1000, 700);
    w.show();

    return app.exec();
}
