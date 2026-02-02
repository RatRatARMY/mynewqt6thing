//
// Created by ratratarmy on 02/02/2026.
//

#ifndef MYNEWQT6THING_SDL3GAME4_DESC_HPP
#define MYNEWQT6THING_SDL3GAME4_DESC_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class SDL3Game4_DescWND;
}

QT_END_NAMESPACE

class SDL3Game4_DescWND : public QWidget {
    Q_OBJECT

public:
    explicit SDL3Game4_DescWND(QWidget *parent = nullptr);

    ~SDL3Game4_DescWND() override;

private:
    Ui::SDL3Game4_DescWND *ui;
    void ret_to_home();
    void launch_game();
};


#endif //MYNEWQT6THING_SDL3GAME4_DESC_HPP
