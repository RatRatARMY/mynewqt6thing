//
// Created by ratratarmy on 02/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved

#include "login.hpp"
#include "ui_login.h"
#include "home.hpp"
#include "register.hpp"
#include <QMessageBox>


LoginWND::LoginWND(QWidget *parent) : QWidget(parent), ui(new Ui::LoginWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &LoginWND::go_to_home);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoginWND::go_to_register);
}

LoginWND::~LoginWND() {
    delete ui;
}
void LoginWND::go_to_home() {
    if ((ui->lineEdit->text() == "admin" or ui->lineEdit->text() == "admin@gmail.com")
        and ui->lineEdit_2->text() == "admin123") {
        HomeWND* home = new HomeWND();
        home->show();
        this->close();
    } else {
        auto dlg = QMessageBox::critical(this, "Error", "Username or password is incorrect\n"
            "Number of incorrect login attempt(s) left: " + QString::number(num_of_invalid_login_attempts - 1),
            QMessageBox::Ok | QMessageBox::Cancel);
        if (dlg == QMessageBox::Ok) {
            num_of_invalid_login_attempts -= 1;
        }
        if (dlg == QMessageBox::Cancel) {
            num_of_invalid_login_attempts = 0;
        }
        if (num_of_invalid_login_attempts == 0) {
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
            ui->lineEdit->setEnabled(false);
            ui->lineEdit_2->setEnabled(false);
        }
    }
}
void LoginWND::go_to_register() {
    RegisterWND* register_wnd = new RegisterWND();
    register_wnd->show();
    this->close();
}