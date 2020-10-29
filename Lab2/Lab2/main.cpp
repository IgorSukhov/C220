#include "container.h"
int main()
{
    Container<int> c = { 1, 2, 3, 4, 3};
    c.Append({33, 24, 3 , 2, 1, 21 ,4,2});
    c.Append({2,544, 3, 23, 544, 5, 23 ,1 ,7});
    c.PrintData();

//    vector<int> v = {1,7,8};
//    auto p = find(v.begin(),v.end(),7);
//    if(p==v.end())
//    cout << "not found";

    return 0;
}
