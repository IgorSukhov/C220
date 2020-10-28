#include "container.h"
int main()
{
    Container<int> c = { 1, 2, 3};
    c.Append({33, 24, 3 , 2, 1});
    c.PrintData();
    return 0;
}
