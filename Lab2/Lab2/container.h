#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T>
class Container
{
    vector<T> data;
public:
    explicit Container();
    Container(initializer_list<T> list);
    void Append(initializer_list<T> list);
    void Remove(initializer_list<T> list);
    void Sort(bool ascending);
    void PrintData();
    void add(const T& t);
    void remove(const T& t);
    T& operator[](size_t n);
    T& operator[](size_t n) const;
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
void Container<T>::add(const T &t)
{
    if(find(begin(data), end(data), t) == end(data))
    {
//        cout << t << " ";
        data.push_back(t);
    }
}

template<typename T>
void Container<T>::Remove(initializer_list<T> list)
{
    for (const auto& p : list) {
        remove(p);
    }
}

template<typename T>
void Container<T>::Sort(bool ascending)
{
    if(ascending) sort(begin(data), end(data), std::less<T>());
    else sort(begin(data), end(data), std::greater<T>());
}

template<typename T>
void Container<T>::remove(const T &t)
{
    const auto& it = find(begin(data), end(data), t);
    if(it != end(data))
    {
        data.erase(it);
    }
}

template<typename T>
T &Container<T>::operator[](size_t n) const
{
    return data[n];
}

template<typename T>
T &Container<T>::operator[](size_t n)
{
    return data[n];
}

template<typename T>
void Container<T>::PrintData()
{
    for (auto& d : data) {
        cout << d << " ";
    }
    cout << "\n";
}

#endif // CONTAINER_H
