#include <iostream>
#include "iter.h"

int main()
{
    Iter<int> it;
    it.push(1);
    it.push(11);
    it.push(22);
    it.push(33);
    it.print();
    it.push(44);
    it.pop();
    it.print();
    it.push(55);
    it.print();

    return 0;
}
