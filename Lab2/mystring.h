#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

class MyString
{
private:
    //queue<T> q;
public:
    string data;
    explicit MyString();
//    MyString(char *str);

    MyString(const string &str);


    MyString(string &&str);


    void Print();
};




#endif // MYSTRING_H
