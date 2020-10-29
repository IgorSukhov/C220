#include "container.h"
#include "myqueue.h"
#include "mystring.h"

void Task1()
{
    Container<int> c = { 1, 2, 3, 4, 3};
    c.Append({33, 24, 3 , 2, 1, 21 ,4 ,2});
    c.Append({2,544, 3, 23, 544, 5, 23 ,1 ,7});
    c.Remove({4, 544, 654, 4});
    c.Sort(false);
    c.PrintData();
    c.Sort(true);
    c.PrintData();
//    c[6] = 123;

    cout << c[6] << endl;
}

void Task2()
{

    MyQueue<MyString>  q1{ MyString("AAA"), MyString ("qwerty") };

    q1.Print();

    //использование MyQueue в диапазонном for:
//    for (auto& el : q1)  {  std::cout << el << ' '; }
//    MyString s(“abc”);
//    q1.push(s);
//    q1.push(MyString(“123”));
//    MyString s1 = q1.pop();
//    q1.push(“qqq”);
//    MyQueue < MyString >  q2 = q1;
//    MyQueue < MyString >  q22 = std::move(q1);

//    MyQueue < MyString >  q3{10, MyString (“!”)}; //очередь должна содержать 10 элементов со строкой «!»
//    q1 = q3;
//    q2 = MyQueue < MyString >  (5, MyString (“?”));
//    q1 = { MyString(“bbb”), MyString (“ssss”)};
}

int main()
{
//    Task1();

    Task2();


    return 0;
}
