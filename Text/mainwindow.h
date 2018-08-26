#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void openFile();
    void saveFile();
    void saveFileAs();
    void exit();
    void copy();
    void paste();
    void cut();
    void selectAll();
    void toUppercase();
    void toLowercase();
    void removeDupeLines(); // This thing has the lowest Priority. Just because I'm lazy. :)
    void zoomIn();
    void zoomOut();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFile *currentFile = nullptr;
};

#endif // MAINWINDOW_H
