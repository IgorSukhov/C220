#include "mystring.h"

MyString::MyString()
{

}

MyString::MyString(const string &str) : data(str) {}

MyString::MyString(string &&str) : data(move(str)) {}



void MyString::Print()
{
    cout << data << endl;
}
