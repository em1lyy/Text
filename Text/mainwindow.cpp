#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtDebug>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(this->ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(this->ui->actionSave_as, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(this->ui->actionQuit, &QAction::triggered, this, &MainWindow::exit);
    connect(this->ui->actionCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(this->ui->actionPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(this->ui->actionCut, &QAction::triggered, this, &MainWindow::cut);
    connect(this->ui->actionTO_UPPERCASE, &QAction::triggered, this, &MainWindow::toUppercase);
    connect(this->ui->actionto_lowercase, &QAction::triggered, this, &MainWindow::toLowercase);
    connect(this->ui->actionRemove_duplicate_lines, &QAction::triggered, this, &MainWindow::removeDupeLines);
    connect(this->ui->actionZoom_in, &QAction::triggered, this, &MainWindow::zoomIn);
    connect(this->ui->actionZoom_out, &QAction::triggered, this, &MainWindow::zoomOut);
    connect(this->ui->actionSelect_all, &QAction::triggered, this, &MainWindow::selectAll);
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

void MainWindow::saveFile()
{
    if (currentFile == nullptr)
    {
        this->saveFileAs();
        return;
    }
    if (this->currentFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
       qDebug() << "Output file opened.";
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
    QFile *file = new QFile(strFile);
    file->open(QIODevice::WriteOnly);
    file->close();
    this->currentFile = file;
    this->setWindowTitle(file->fileName().split("/").back() + " - Text");
    this->saveFile();
}

void MainWindow::exit()
{
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
    qDebug() << "Zoomed in.";
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
    qDebug() << "Zoomed out.";
}

MainWindow::~MainWindow()
{
    delete ui;
}
