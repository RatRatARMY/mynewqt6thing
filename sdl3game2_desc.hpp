//
// Created by ratratarmy on 02/02/2026.
//

#ifndef MYNEWQT6THING_SDL3GAME2_DESC_HPP
#define MYNEWQT6THING_SDL3GAME2_DESC_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class SDL3Game2_DescWND;
}

QT_END_NAMESPACE

class SDL3Game2_DescWND : public QWidget {
    Q_OBJECT

public:
    explicit SDL3Game2_DescWND(QWidget *parent = nullptr);

    ~SDL3Game2_DescWND() override;

private:
    Ui::SDL3Game2_DescWND *ui;
};


#endif //MYNEWQT6THING_SDL3GAME2_DESC_HPP