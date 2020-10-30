#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
class MyQueue
{
    queue<T> data;
public:
    explicit MyQueue();
    MyQueue(initializer_list<T> list);

    void Print();
};

template<typename T>
MyQueue<T>::MyQueue(initializer_list<T> list)
{
    for (const auto& p : list) {
        data.push(p);
    }
}

template<typename T>
void MyQueue<T>::Print()
{



}

#endif // MYQUEUE_H
