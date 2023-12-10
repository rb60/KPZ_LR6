#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Collections.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    List* list;
    Array* arr;
    ListToArrayAdapter* listAdapter;
    ArrayToListAdapter* arrAdapter;
    Ui::MainWindow *ui;
public slots:
    void getArrNative();
    void setArrNative();

    void prevArrAdapter();
    void nextArrAdapter();
    void setArrAdapter();


    void prevListNative();
    void nextListNAtive();
    void setListNative();
    void addListNative();

    void getListAdapter();
    void setListAdapter();
};
#endif // MAINWINDOW_H
