#ifndef ITER_H
#define ITER_H

#include <string>
template<typename T>
class Iter
{
    T *arr;
    int dataSize = 3;
    int dataPos = 0;
public:
    Iter();
    ~Iter();
    T *begin();
    T *end();
    void add(const T &t);

};

template<typename T>
Iter<T>::Iter()
{
    arr = new T[3];
}

template<typename T>
Iter<T>::~Iter()
{
    delete[] arr;
}

template<typename T>
T *Iter<T>::begin()
{
    return arr;
}

template<typename T>
T *Iter<T>::end()
{
    return arr+dataPos;
}

template<typename T>
void Iter<T>::add(const T &t)
{
    arr[dataPos] = t;
    ++dataPos;
}



#endif // ITER_H
