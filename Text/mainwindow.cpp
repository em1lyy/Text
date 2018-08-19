#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
}

void MainWindow::openFile()
{
    QFile *file = new QFile(QFileDialog::getOpenFileName(this, tr("Open file"), QString()));
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

MainWindow::~MainWindow()
{
    delete ui;
}
