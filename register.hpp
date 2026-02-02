//
// Created by ratratarmy on 02/02/2026.
//

#ifndef MYNEWQT6THING_REGISTER_HPP
#define MYNEWQT6THING_REGISTER_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class RegisterWND;
}

QT_END_NAMESPACE

class RegisterWND : public QWidget {
    Q_OBJECT

public:
    explicit RegisterWND(QWidget *parent = nullptr);

    ~RegisterWND() override;

private:
    Ui::RegisterWND *ui;
};


#endif //MYNEWQT6THING_REGISTER_HPP