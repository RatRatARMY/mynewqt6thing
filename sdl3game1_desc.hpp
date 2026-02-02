//
// Created by ratratarmy on 02/02/2026.
//

#ifndef MYNEWQT6THING_SDL3GAME1_DESC_HPP
#define MYNEWQT6THING_SDL3GAME1_DESC_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class SDL3Game1_DescWND;
}

QT_END_NAMESPACE

class SDL3Game1_DescWND : public QWidget {
    Q_OBJECT

public:
    explicit SDL3Game1_DescWND(QWidget *parent = nullptr);

    ~SDL3Game1_DescWND() override;

private:
    Ui::SDL3Game1_DescWND *ui;
    void ret_to_home();
};


#endif //MYNEWQT6THING_SDL3GAME1_DESC_HPP