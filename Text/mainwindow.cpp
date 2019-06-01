#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QScrollBar>
#include <QMessageBox>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile); // I know, it's a lot of spaghetti code, but I just don't know how I should do all of this without writing such a horrible mess.
    connect(this->ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(this->ui->actionSave_as, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(this->ui->actionQuit, &QAction::triggered, this, &MainWindow::exit);
    connect(this->ui->actionCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(this->ui->actionPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(this->ui->actionCut, &QAction::triggered, this, &MainWindow::cut);
    connect(this->ui->actionTO_UPPERCASE, &QAction::triggered, this, &MainWindow::toUppercase);
    connect(this->ui->actionto_lowercase, &QAction::triggered, this, &MainWindow::toLowercase);
    connect(this->ui->actiontO_fOLDED_cASE, &QAction::triggered, this, &MainWindow::toFoldCase);
    connect(this->ui->actionRemove_duplicate_lines, &QAction::triggered, this, &MainWindow::removeDupeLines);
    connect(this->ui->actionZoom_in, &QAction::triggered, this, &MainWindow::zoomIn);
    connect(this->ui->actionZoom_out, &QAction::triggered, this, &MainWindow::zoomOut);
    connect(this->ui->actionSelect_all, &QAction::triggered, this, &MainWindow::selectAll);
    connect(this->ui->actionAb_out, &QAction::triggered, this, &MainWindow::about);
    connect(this->ui->actionH_elp, &QAction::triggered, this, &MainWindow::showHelp);
    connect(this->ui->actionAbout_Qt, &QAction::triggered, &QApplication::aboutQt);

    QScrollBar *sb = new QScrollBar();
    this->ui->textEdit->setVerticalScrollBar(sb);
    QScrollBar *vsb = new QScrollBar();
    this->ui->textEdit->setHorizontalScrollBar(vsb);
}

void MainWindow::openFile()
{
    QFile *file = new QFile(QFileDialog::getOpenFileName(this, tr("Open file"), QString()));
    this->currentFile = file;
    this->setWindowTitle(file->fileName().split("/").back() + " - Text");
    QStringList lines;
    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
       qDebug() << "Input file opened.";
       QTextStream in(file);
       QString line = "";
       if (in.atEnd())
           qDebug() << "File is empty.";
       while (!in.atEnd())
       {
            line = in.readLine();
            lines.append(line);
       }
       file->close();
    }
    this->ui->textEdit->setText(lines.join("\n"));
}

void MainWindow::openFilePath(QString path)
{
    QFile *file = new QFile(path);
    this->currentFile = file;
    this->setWindowTitle(file->fileName().split("/").back() + " - Text"); // The title thing looks really nice. A little improvement with huge impact
    QStringList lines;
    if (file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
       qDebug() << "Input file opened.";
       QTextStream in(file);
       QString line = "";
       if (in.atEnd())
           qDebug() << "File is empty.";
       while (!in.atEnd())
       {
            line = in.readLine();
            lines.append(line);
       }
       file->close();
    }
    this->ui->textEdit->setText(lines.join("\n"));
}

void MainWindow::saveFile()
{
    if (currentFile == nullptr)
    {
        this->saveFileAs();
        return;
    }
    if (this->currentFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
       QTextStream out(this->currentFile);
       out << this->ui->textEdit->toPlainText() << endl;
       this->currentFile->close();
    }
}

void MainWindow::saveFileAs()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString strFile = dialog.getSaveFileName(NULL, tr("Save as"),"","");
    if (!strFile.isEmpty()) // of couse, we don't open anything when the user clicked cancel
    {
        QFile *file = new QFile(strFile);
        file->open(QIODevice::WriteOnly);
        file->close();
        this->currentFile = file;
        this->setWindowTitle(file->fileName().split("/").back() + " - Text");
        this->saveFile();
    }
    else
    {
        qDebug("Operation cancelled.");
    }

}

void MainWindow::exit()
{
    this->saveFile();
    this->close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (this->ui->textEdit->toPlainText().replace("\n", "").replace(" ", "") != "")
        this->saveFile();
    this->close();
}

void MainWindow::copy()
{
    this->ui->textEdit->copy();
}

void MainWindow::paste()
{
    this->ui->textEdit->paste();
}

void MainWindow::cut()
{
    this->ui->textEdit->cut();
}

void MainWindow::selectAll()
{
    this->ui->textEdit->selectAll();
}

void MainWindow::toUppercase()
{
    this->ui->textEdit->setText(this->ui->textEdit->toPlainText().toUpper());
}

void MainWindow::toLowercase()
{
    this->ui->textEdit->setText(this->ui->textEdit->toPlainText().toLower());
}

void MainWindow::toFoldCase()
{
    this->ui->textEdit->setText(this->ui->textEdit->toPlainText().toCaseFolded());
}

void MainWindow::removeDupeLines()
{
    QStringList lines = this->ui->textEdit->toPlainText().split("\n");
    lines.removeDuplicates();
    this->ui->textEdit->setText(lines.join("\n"));
}

void MainWindow::zoomIn()
{
    this->ui->textEdit->zoomIn();
    QFont *newFont = new QFont(this->ui->textEdit->font());
    newFont->setPointSize(newFont->pointSize() + 1);
    this->ui->textEdit->setFont(*newFont);
    this->repaint();
    this->update();
    this->ui->textEdit->repaint();
    this->ui->textEdit->update();
}

void MainWindow::zoomOut()
{
    this->ui->textEdit->zoomOut();
    QFont *newFont = new QFont(this->ui->textEdit->font());
    newFont->setPointSize(newFont->pointSize() - 1);
    this->ui->textEdit->setFont(*newFont);
    this->repaint();
    this->update();
    this->ui->textEdit->repaint();
    this->ui->textEdit->update();
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Text"),
            tr("<p><b>Text</b> is a text editor made using Qt5.")); // I just ran out of ideas
}

void MainWindow::showHelp()
{
    QMessageBox::about(this, tr("Help - Text"),
            tr("<h2>Help - Text</h2>"
               "<b>Help and Assistance</b><br />"
               "If you need help or assistance, please join <a href=\"https://discord.gg/mhmERk8\">the official JaguDev Discord Server</a></p>"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
