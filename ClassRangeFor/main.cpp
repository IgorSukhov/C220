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
    iter.add({std::string("Hi"),std::string("Hi")});
    iter.print();

    Iter<int> it;
    it.add(15);
    it.add(23);
    it.print();
    return a.exec();
}
