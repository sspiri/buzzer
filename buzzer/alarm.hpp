#ifndef ALARM_HPP
#define ALARM_HPP


#include <QTimer>
#include <QDateTime>


class alarm : public QObject{
    Q_OBJECT

signals:
    void notify(qint64 delay);

private slots:
    void check_state(){
        auto current = QDateTime::currentDateTime();

        if(datetime < current){
            timer->stop();
            emit notify(datetime.secsTo(current));
        }
    }

public:
    QDateTime datetime;

    alarm(const QDateTime& dt, QObject* parent = nullptr)
        : QObject{parent}, datetime{dt}{

        connect(timer, &QTimer::timeout, this, &alarm::check_state);

        timer->setSingleShot(false);
        timer->setInterval(1000);
        timer->start();
    }

private:
    QTimer* timer{new QTimer{this}};
};



#endif
