#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
class MyQueue
{
    T *data;
    size_t dataPos = 0;
    size_t dataSize = 0; // first invalid element
public:
    explicit MyQueue();
    MyQueue(initializer_list<T> list);

    void Print();
    T* begin();
    T& end();
};

template<typename T>
MyQueue<T>::MyQueue()
{

}

template<typename T>
MyQueue<T>::MyQueue(initializer_list<T> list)
{
    int d = distance(list.begin(), list.end());
    dataPos = d;
    dataSize = d;
    data = new T[d];
    T *ptr = data;
    for (const auto& p : list) {
        *ptr = p;
        ++ptr;
    }
}

template<typename T>
void MyQueue<T>::Print()
{
    for(int i=0;i<dataSize;++i)
    {
        std::cout << data[i].data;
    }
}

template<typename T>
T *MyQueue<T>::begin()
{
    return data[0];
}

template<typename T>
T &MyQueue<T>::end()
{
    return data[dataSize];
}

#endif // MYQUEUE_H
