/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionQuit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionSelect_all;
    QAction *actionTO_UPPERCASE;
    QAction *actionto_lowercase;
    QAction *actionRemove_duplicate_lines;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionAb_out;
    QAction *actionAbout_Qt;
    QAction *actionH_elp;
    QAction *actiontO_fOLDED_cASE;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuView;
    QMenu *menuA_bout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(943, 727);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("accessories-text-editor");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionSelect_all = new QAction(MainWindow);
        actionSelect_all->setObjectName(QString::fromUtf8("actionSelect_all"));
        actionTO_UPPERCASE = new QAction(MainWindow);
        actionTO_UPPERCASE->setObjectName(QString::fromUtf8("actionTO_UPPERCASE"));
        actionto_lowercase = new QAction(MainWindow);
        actionto_lowercase->setObjectName(QString::fromUtf8("actionto_lowercase"));
        actionRemove_duplicate_lines = new QAction(MainWindow);
        actionRemove_duplicate_lines->setObjectName(QString::fromUtf8("actionRemove_duplicate_lines"));
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        actionAb_out = new QAction(MainWindow);
        actionAb_out->setObjectName(QString::fromUtf8("actionAb_out"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionH_elp = new QAction(MainWindow);
        actionH_elp->setObjectName(QString::fromUtf8("actionH_elp"));
        actiontO_fOLDED_cASE = new QAction(MainWindow);
        actiontO_fOLDED_cASE->setObjectName(QString::fromUtf8("actiontO_fOLDED_cASE"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Hack"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        textEdit->setFont(font);
        textEdit->setAutoFillBackground(true);
        textEdit->setStyleSheet(QString::fromUtf8(""));
        textEdit->setFrameShape(QFrame::StyledPanel);
        textEdit->setOverwriteMode(false);
        textEdit->setAcceptRichText(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 943, 28));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuA_bout = new QMenu(menubar);
        menuA_bout->setObjectName(QString::fromUtf8("menuA_bout"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuA_bout->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionSelect_all);
        menuTools->addAction(actionTO_UPPERCASE);
        menuTools->addAction(actionto_lowercase);
        menuTools->addAction(actiontO_fOLDED_cASE);
        menuTools->addAction(actionRemove_duplicate_lines);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);
        menuA_bout->addAction(actionH_elp);
        menuA_bout->addSeparator();
        menuA_bout->addAction(actionAb_out);
        menuA_bout->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Text", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_as->setText(QApplication::translate("MainWindow", "Save &as", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "&Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "&Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "C&ut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionSelect_all->setText(QApplication::translate("MainWindow", "&Select all", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSelect_all->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionTO_UPPERCASE->setText(QApplication::translate("MainWindow", "&TO UPPERCASE", nullptr));
#ifndef QT_NO_SHORTCUT
        actionTO_UPPERCASE->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionto_lowercase->setText(QApplication::translate("MainWindow", "to &lowercase", nullptr));
#ifndef QT_NO_SHORTCUT
        actionto_lowercase->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionRemove_duplicate_lines->setText(QApplication::translate("MainWindow", "&Remove duplicate lines", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRemove_duplicate_lines->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+D", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_in->setText(QApplication::translate("MainWindow", "&Zoom in", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_in->setShortcut(QApplication::translate("MainWindow", "Ctrl++", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom_out->setText(QApplication::translate("MainWindow", "Zoom &out", nullptr));
#ifndef QT_NO_SHORTCUT
        actionZoom_out->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        actionAb_out->setText(QApplication::translate("MainWindow", "Ab&out", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About &Qt", nullptr));
        actionH_elp->setText(QApplication::translate("MainWindow", "H&elp", nullptr));
#ifndef QT_NO_SHORTCUT
        actionH_elp->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actiontO_fOLDED_cASE->setText(QApplication::translate("MainWindow", "tO fOLDED cASE", nullptr));
#ifndef QT_NO_TOOLTIP
        actiontO_fOLDED_cASE->setToolTip(QApplication::translate("MainWindow", "tO &fOLDED cASE", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actiontO_fOLDED_cASE->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F", nullptr));
#endif // QT_NO_SHORTCUT
        textEdit->setDocumentTitle(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edi&t", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tool&s", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", nullptr));
        menuA_bout->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
