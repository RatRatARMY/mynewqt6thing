//
// Created by ratratarmy on 02/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game4_desc.h" resolved

#include "sdl3game4_desc.hpp"
#include "ui_sdl3game4_desc.h"
#include "home.hpp"
#include "sdl3game4.hpp"


SDL3Game4_DescWND::SDL3Game4_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game4_DescWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &SDL3Game4_DescWND::ret_to_home);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &SDL3Game4_DescWND::launch_game);
}

SDL3Game4_DescWND::~SDL3Game4_DescWND() {
    delete ui;
}

void SDL3Game4_DescWND::ret_to_home() {
    HomeWND* home = new HomeWND();
    home->show();
    this->close();
}

void SDL3Game4_DescWND::launch_game() {
    game4::launch();
}
