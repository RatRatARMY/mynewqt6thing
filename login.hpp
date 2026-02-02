//
// Created by ratratarmy on 02/02/2026.
//

#ifndef MYNEWQT6THING_LOGIN_HPP
#define MYNEWQT6THING_LOGIN_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class LoginWND;
}

QT_END_NAMESPACE

class LoginWND : public QWidget {
    Q_OBJECT

public:
    explicit LoginWND(QWidget *parent = nullptr);

    ~LoginWND() override;

private:
    Ui::LoginWND *ui;
    int num_of_invalid_login_attempts = 8;
    void go_to_home();
    void go_to_register();
};


#endif //MYNEWQT6THING_LOGIN_HPP
