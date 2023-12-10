#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arr = new Array(5);
    for(int i = 0; i < 5; i++)
    {
        arr->set(i, i + 1);
    }
    arrAdapter = new ArrayToListAdapter(arr);

    list = new List;
    for(int i = 6; i < 11; i++)
    {
        list->add(i);
    }
    listAdapter = new ListToArrayAdapter(list);

    list->toStart();
    arrAdapter->toStart();
    ui->arr_native_index->setValue(0);
    ui->list_adapter_index->setValue(0);

    getArrNative();
    getListAdapter();
    ui->arr_adapter_value->setValue(arrAdapter->get());
    ui->list_native_value->setValue(list->get());

    connect(ui->arr_native_get, SIGNAL(clicked()), SLOT(getArrNative()));
    connect(ui->arr_native_set, SIGNAL(clicked()), SLOT(setArrNative()));

    connect(ui->arr_adapter_prev, SIGNAL(clicked()), SLOT(prevArrAdapter()));
    connect(ui->arr_adapter_next, SIGNAL(clicked()), SLOT(nextArrAdapter()));
    connect(ui->arr_adapter_set, SIGNAL(clicked()), SLOT(setArrAdapter()));


    connect(ui->list_native_prev, SIGNAL(clicked()), SLOT(prevListNative()));
    connect(ui->list_native_next, SIGNAL(clicked()), SLOT(nextListNAtive()));
    connect(ui->list_native_set, SIGNAL(clicked()), SLOT(setListNative()));
    connect(ui->list_native_add, SIGNAL(clicked()), SLOT(addListNative()));

    connect(ui->list_adapter_get, SIGNAL(clicked()), SLOT(getListAdapter()));
    connect(ui->list_adapter_set, SIGNAL(clicked()), SLOT(setListAdapter()));

}

MainWindow::~MainWindow()
{
    delete listAdapter;
    delete arrAdapter;
    delete list;
    delete arr;
    delete ui;
}

void MainWindow::getArrNative()
{
    ui->arr_native_value->setValue(arr->get(ui->arr_native_index->value()));
}

void MainWindow::setArrNative()
{
    arr->set(ui->arr_native_index->value(), ui->arr_native_value->value());
}

void MainWindow::prevArrAdapter()
{
    arrAdapter->prev();
    ui->arr_adapter_value->setValue(arrAdapter->get());
}

void MainWindow::nextArrAdapter()
{
    arrAdapter->next();
    ui->arr_adapter_value->setValue(arrAdapter->get());
}

void MainWindow::setArrAdapter()
{
    arrAdapter->set(ui->arr_adapter_value->value());
}

void MainWindow::prevListNative()
{
    list->prev();
    ui->list_native_value->setValue(list->get());
}

void MainWindow::nextListNAtive()
{
    list->next();
    ui->list_native_value->setValue(list->get());
}

void MainWindow::setListNative()
{
    list->set(ui->list_native_value->value());
}

void MainWindow::addListNative()
{
    list->add(ui->list_native_value->value());
}

void MainWindow::getListAdapter()
{
    ui->list_adapter_value->setValue(listAdapter->get(ui->list_adapter_index->value()));
}

void MainWindow::setListAdapter()
{
    listAdapter->set(ui->list_adapter_index->value(), ui->list_adapter_value->value());
}

