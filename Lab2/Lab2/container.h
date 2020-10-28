#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Container
{
    vector<T> data;
public:
    Container()
    {
        data.push_back(3);
        data.push_back(23);
        data.push_back(12);
    }
    Container(initializer_list<T> list)
    {
        data.insert(data.begin(),list.begin(),list.end());
    }
    void Append(initializer_list<T> list)
    {
        for (auto& p : list) {
            add(p);
        }
    }
    void PrintData()
    {
        for (auto& d : data) {
            cout << d << " ";
        }
        cout << "\n";
    }
    void add(T t)
    {
        if(find(data.begin(),data.end(), t) != data.end())
        {
            data.push_back(t);
        }
    }
    bool compare(T t1, T t2)
    {
        return t1 == t2;
    }
};

#endif // CONTAINER_H
