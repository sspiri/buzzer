#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP


#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>


class main_window : public QMainWindow{
public:
    main_window();

private slots:
    void add_alarm();
    void delete_alarm();
    void delete_all_alarms();

    void minimize_to_tray();

private:
    QWidget* central{new QWidget{this}};
    QListWidget* alarms_list{new QListWidget{this}};

    QPushButton* add_button{new QPushButton{"Add", this}},
               * delete_button{new QPushButton{"Delete", this}};

    void set_connections();
    void set_layout();
};


#endif
