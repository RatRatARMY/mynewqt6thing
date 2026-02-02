//
// Created by ratratarmy on 02/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_home.h" resolved

#include "home.hpp"
#include "ui_home.h"
#include "sdl3game1_desc.hpp"
#include "sdl3game2_desc.hpp"
#include "sdl3game3_desc.hpp"
#include "sdl3game4_desc.hpp"


HomeWND::HomeWND(QWidget *parent) : QWidget(parent), ui(new Ui::HomeWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &HomeWND::go_to_game1_desc);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &HomeWND::go_to_game2_desc);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &HomeWND::go_to_game3_desc);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &HomeWND::go_to_game4_desc);
}

HomeWND::~HomeWND() {
    delete ui;
}

void HomeWND::go_to_game1_desc() {
    SDL3Game1_DescWND* descwnd = new SDL3Game1_DescWND();
    descwnd->show();
    this->close();
}

void HomeWND::go_to_game2_desc() {
    SDL3Game2_DescWND* descwnd = new SDL3Game2_DescWND();
    descwnd->show();
    this->close();
}

void HomeWND::go_to_game3_desc() {
    SDL3Game3_DescWND* descwnd = new SDL3Game3_DescWND();
    descwnd->show();
    this->close();
}

void HomeWND::go_to_game4_desc() {
    SDL3Game4_DescWND* descwnd = new SDL3Game4_DescWND();
    descwnd->show();
    this->close();
}
