#include <QApplication>
#include "login.hpp"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LoginWND* root = new LoginWND();
    root->show();
    return QApplication::exec();
}