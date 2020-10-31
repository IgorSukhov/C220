#ifndef ITER_H
#define ITER_H

#include <string>
#include <iostream>

template<typename T>
class Iter
{
    T *arr;
    size_t dataSize = 1;
    size_t dataPos = 0;
public:
    explicit Iter();
    Iter(std::initializer_list<T> list);
    ~Iter();
    T *begin() const;
    T *end() const;
    void add(const T &t);
    void add(std::initializer_list<T> list);
    void increaseSize(size_t maxSize);
    void print();
};

template<typename T>
Iter<T>::Iter()
{
    arr = new T[1];
}

template<typename T>
Iter<T>::Iter(std::initializer_list<T> list)
{
    increaseSize(dataPos+std::distance(list.begin(),list.end()));
    for (auto& l : list) {
        add(l);
    }
}

template<typename T>
Iter<T>::~Iter()
{
    delete[] arr;
}

template<typename T>
T *Iter<T>::begin() const
{
    return arr;
}

template<typename T>
T *Iter<T>::end() const
{
    return arr+dataPos;
}

template<typename T>
void Iter<T>::add(const T &t)
{
    if(dataPos == dataSize)
    {
        increaseSize(dataSize);
    }
    arr[dataPos] = t;
    ++dataPos;
}

template<typename T>
void Iter<T>::add(std::initializer_list<T> list)
{
    increaseSize(dataPos+std::distance(list.begin(),list.end()));
    for (auto& l : list) {
        add(l);
    }
}

template<typename T>
void Iter<T>::increaseSize(size_t maxSize)
{
    while(dataSize <= maxSize)
    {
        dataSize = dataSize << 1;
    }
    if(dataSize==0)
    {
        delete [] arr;
        throw;
    }
    T *arrNew = new T[dataSize];
    for(size_t i=0;i<dataPos;++i)
    {
        arrNew[i] = arr[i];
    }
    arr = arrNew;
}

template<typename T>
void Iter<T>::print()
{
    for (auto& v : *this) {
        std::cout << v << std::endl;
    }
}



#endif // ITER_H
