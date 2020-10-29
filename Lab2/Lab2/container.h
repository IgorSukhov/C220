#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Container
{
    vector<T> data;
public:
    Container();
    Container(initializer_list<T> list);
    void Append(initializer_list<T> list);
    void PrintData();
    void add(const T& t);
};


template<typename T>
Container<T>::Container()
{
//    data.push_back(3);
//    data.push_back(23);
//    data.push_back(12);
}

template<typename T>
Container<T>::Container(initializer_list<T> list)
{
    //data.insert(data.begin(),list.begin(),list.end());
    Append(list);
}

template<typename T>
void Container<T>::Append(initializer_list<T> list)
{
    for (const auto& p : list) {
        add(p);
    }
}

template<typename T>
void Container<T>::PrintData()
{
    for (auto& d : data) {
        cout << d << " ";
    }
    cout << "\n";
}

template<typename T>
void Container<T>::add(const T &t)
{
    if(find(begin(data), end(data), t) == end(data))
    {
//        cout << t << " ";
        data.push_back(t);
    }
}

#endif // CONTAINER_H
