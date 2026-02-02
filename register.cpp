//
// Created by ratratarmy on 02/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_register.h" resolved

#include "register.hpp"
#include "ui_register.h"
#include "home.hpp"
#include "login.hpp"
#include <QMessageBox>


RegisterWND::RegisterWND(QWidget *parent) : QWidget(parent), ui(new Ui::RegisterWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &RegisterWND::register_);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &RegisterWND::ret_to_login);
}

RegisterWND::~RegisterWND() {
    delete ui;
}
void RegisterWND::register_() {
    if (ui->lineEdit->text() != "" and ui->lineEdit_2->text() != "" and ui->lineEdit_3->text() != "" and ui->lineEdit_4->text() != ""
        and ui->lineEdit_3->text() == ui->lineEdit_4->text()) {
        HomeWND* home = new HomeWND();
        home->show();
        this->close();
    }
    else {
        QMessageBox::critical(this, "Error", "Some information is empty or not match");
    }
}
void RegisterWND::ret_to_login() {
    LoginWND* login = new LoginWND();
    login->show();
    this->close();
}
