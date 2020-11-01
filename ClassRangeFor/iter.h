#ifndef ITER_H
#define ITER_H

#include <string>
#include <iostream>

template<typename T>
class Iter
{
    T *data;
    size_t m_cap = 2;
    size_t m_n = 0;
    size_t m_first = 0;
    size_t m_last = 0;
public:
    explicit Iter();
    Iter(std::initializer_list<T> list);
    ~Iter();
    T *begin() const;
    T *end() const;
//    void add(const T &t);
//    void add(std::initializer_list<T> list);
    void increaseSize(size_t maxSize);
    void print();
    void push(const T& t);
    void pop();
    T& front();
};

template<typename T>
Iter<T>::Iter()
{
    data = new T[m_cap];
}

template<typename T>
Iter<T>::Iter(std::initializer_list<T> list)
{
    size_t d = std::distance(list.begin(),list.end());
    data = new T[d];
    //    increaseSize(dataPos+std::distance(list.begin(),list.end()));
    for (auto& l : list) {
        add(l);
    }
}

template<typename T>
Iter<T>::~Iter()
{
    delete[] data;
}

template<typename T>
T *Iter<T>::begin() const
{
    return data;
}

template<typename T>
T *Iter<T>::end() const
{
    return data+m_cap;
}

//template<typename T>
//void Iter<T>::add(const T &t)
//{
//    m_last = (m_first + m_n) % m_cap;
//    //    if(dataPos == dataSize)
//    //    {
//    //        increaseSize(dataSize);
//    //    }
//    data[m_first] = t;
//    ++m_first;
//}

//template<typename T>
//void Iter<T>::add(std::initializer_list<T> list)
//{
//    m_last = (m_first + m_n) % m_cap;
//    //    increaseSize(dataPos+std::distance(list.begin(),list.end()));
//    for (auto& l : list) {
//        add(l);
//    }
//}

template<typename T>
void Iter<T>::increaseSize(size_t maxSize)
{
    size_t newCap = m_n;
    while(newCap <= maxSize)
    {
        newCap = newCap << 1;
    }

    if(newCap==0)
    {
        delete [] data;
        throw;
    }
    T *dataNew = new T[newCap];

    size_t arrSize = m_n;
    for(size_t i=0;i<arrSize;++i)
    {
        dataNew[i] = front();
        pop();
    }
    delete[] data;
    data = dataNew;
    m_first = 0;
    m_last = arrSize;
    m_n = arrSize;
    m_cap = newCap;
}

template<typename T>
void Iter<T>::print()
{
    for (auto& v : *this) {
        std::cout << v << " ";
    }
    std::cout
            << std::endl
            << "m_cap:" << m_cap << " "
            << "m_n:" << m_n << " "
            << "m_first:" << m_first << " "
            << "m_last:" << m_last << std::endl;
}

template<typename T>
void Iter<T>::push(const T &t)
{
    if(m_n == m_cap)
    {
        increaseSize(m_n);
    }
    else
    {
    }
    ++m_n;
    data[m_last] = t;
    m_last = (m_first + m_n) % m_cap;
}

template<typename T>
void Iter<T>::pop()
{
    m_first = (m_first + 1) % m_cap;
    if(m_n == 0)
    {
        throw;
    }
    else
    {
        --m_n;
    }
}

template<typename T>
T &Iter<T>::front()
{
    if(!m_n) throw;
    return data[m_first];
}

#endif // ITER_H
