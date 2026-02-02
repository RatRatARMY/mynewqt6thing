//
// Created by ratratarmy on 02/02/2026.
//

#ifndef MYNEWQT6THING_HOME_HPP
#define MYNEWQT6THING_HOME_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class HomeWND;
}

QT_END_NAMESPACE

class HomeWND : public QWidget {
    Q_OBJECT

public:
    explicit HomeWND(QWidget *parent = nullptr);

    ~HomeWND() override;

private:
    Ui::HomeWND *ui;
    void go_to_game1_desc();
    void go_to_game2_desc();
    void go_to_game3_desc();
    void go_to_game4_desc();
};


#endif //MYNEWQT6THING_HOME_HPP