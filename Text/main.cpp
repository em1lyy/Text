#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create a QApplication
    QString locale = QLocale::system().name(); // Get the system locale
    QTranslator translator; // Create the translator
    translator.load(":/" + locale); // Load the translation file
    a.installTranslator(&translator); // And apply everything
    MainWindow w;
    if (argc == 2) { // We don't need an else exit(1) because we can just show an empty window
        std::string path(argv[1]);
        w.openFilePath(QString::fromStdString(path));
    }
    w.show();

    return a.exec();
}
