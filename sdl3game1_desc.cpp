//
// Created by ratratarmy on 02/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_sdl3game1_desc.h" resolved

#include "sdl3game1_desc.hpp"
#include "ui_sdl3game1_desc.h"
#include "home.hpp"


SDL3Game1_DescWND::SDL3Game1_DescWND(QWidget *parent) : QWidget(parent), ui(new Ui::SDL3Game1_DescWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &SDL3Game1_DescWND::ret_to_home);
}

SDL3Game1_DescWND::~SDL3Game1_DescWND() {
    delete ui;
}

void SDL3Game1_DescWND::ret_to_home() {
    HomeWND* home = new HomeWND();
    home->show();
    this->close();
}
