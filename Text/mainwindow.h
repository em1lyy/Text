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
    QFile *currentFile = nullptr; // This is important, it's the file we have currently open
    void openFile();
    void openFilePath(QString path); // We need to do this, otherwise connect doesn't know which function to call
    void saveFile(); // Save the file
    void saveFileAs(); // Saves the file as
    void exit(); // Exits, with save dialog.
    void closeEvent(QCloseEvent *event); // the function that is called when the window is closed
    void copy(); // Copy the text to clipboard
    void paste(); // Paste the text from the clipboard
    void cut(); // Cut everything out
    void selectAll(); // Select all the text
    void toUppercase(); // Make everything UPPERCASE
    void toLowercase(); // make everything lowercase
    void toFoldCase(); // gOOD tO fIX cAPS lOCK aCCIDENTS
    void removeDupeLines(); // removes duplicate lines
    void zoomIn(); // Make the text bigger
    void zoomOut(); // Make the text smaller
    void showHelp(); // Show a window with a bit of help
    void about(); // Show a window with some about Text
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
