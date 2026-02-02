//
// Created by ratratarmy on 02/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game2_desc.h" resolved

#include "sdl3game2_desc.hpp"
#include "ui_sdl3game2_desc.h"
#include "home.hpp"


SDL3Game2_DescWND::SDL3Game2_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game2_DescWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &SDL3Game2_DescWND::ret_to_home);
}

SDL3Game2_DescWND::~SDL3Game2_DescWND() {
    delete ui;
}

void SDL3Game2_DescWND::ret_to_home() {
    HomeWND* home = new HomeWND();
    home->show();
    this->close();
}
