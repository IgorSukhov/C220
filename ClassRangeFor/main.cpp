#include <QCoreApplication>
#include <iostream>
#include "iter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Iter<std::string>    iter;
    iter.add(std::string("Hi"));
    iter.add(std::string("from"));
    iter.add(std::string("iter"));
    for (auto& v : iter) {
        std::cout << v << std::endl;
    }


    return a.exec();
}
