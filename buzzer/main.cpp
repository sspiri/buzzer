#include <QApplication>
#include "main_window.hpp"


int main(int argc, char** argv){
    QApplication buzzer{argc, argv};

    main_window window;
    window.show();

    return buzzer.exec();
}
