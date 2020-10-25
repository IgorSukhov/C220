#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <list>
#include <deque>

using namespace std;

void change_case(char &c);

template<typename T>
void myNeg(T& t)
{
    t = -t;
}

template<>
inline void myNeg(string& ch)
{
    for(auto& v : ch)
    {
        change_case(v);
    }
}

template<typename T>
void NegateAll(T& t)
{
    for(auto& v : t)
    {
        myNeg(v);
    }
}

template<typename T>
void absSort(T& t)
{
    sort(begin(t), end(t), [](const auto& el1, const auto& el2) {return abs(el1) < abs(el2); });
}

template<typename T1, typename T2>
auto SumCont(T1& t1, T2& t2)
{
    vector<decltype(*begin(t1)+*begin(t2))> v(max(size(t1),size(t2)));
    copy(begin(t1),end(t1),begin(v));
    transform(begin(t2), end(t2), begin(v), begin(v), std::plus<>{});
    return v;
}

template<typename T1, typename T2, typename T3, typename F>
void Separate(T1& t1, T2& t2, T3& t3, F pred)
{
    for(auto& el : t1) {
        if(pred(el))
        {
            t2.push_back(el);
        }
        else
        {
            t3.push_back(el);
        }
    }
}

#endif // MAIN_H
