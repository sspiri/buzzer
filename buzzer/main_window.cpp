#include "main_window.hpp"

#include <QMenuBar>
#include <QGridLayout>
#include <QHBoxLayout>


main_window::main_window(){
    setCentralWidget(central);

    set_connections();
    set_layout();
}


void main_window::set_connections(){
    QMenuBar* bar = menuBar();
    QMenu* menu = bar->addMenu("File");

    connect(menu->addAction("Add alarm..."), &QAction::triggered, this, &main_window::add_alarm);
    connect(menu->addAction("Delete alarm..."), &QAction::triggered, this, &main_window::delete_alarm);
    connect(menu->addAction("Delete all alarms..."), &QAction::triggered, this, &main_window::delete_all_alarms);

    menu->addSeparator();

    connect(menu->addAction("Exit"), &QAction::triggered, this, &main_window::minimize_to_tray);

    connect(add_button, &QPushButton::clicked, this, &main_window::add_alarm);
    connect(delete_button, &QPushButton::clicked, this, &main_window::delete_alarm);
}


void main_window::set_layout(){
    auto* grid = new QGridLayout{};
    grid->addWidget(alarms_list, 0, 0);

    auto box = new QHBoxLayout{};
    box->addStretch();
    box->addWidget(add_button);
    box->addWidget(delete_button);

    grid->addLayout(box, 1, 0);
    central->setLayout(grid);
}


void main_window::add_alarm(){

}


void main_window::delete_alarm(){

}


void main_window::delete_all_alarms(){

}


void main_window::minimize_to_tray(){

}
