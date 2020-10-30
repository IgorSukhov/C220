#include "main.h"

using namespace std;

void Task1()
{
    enum class months : unsigned char { January, February, March/*...*/ };
    enum class weekDays : unsigned char { Monday, Tuesday /*...*/ };
    months m = months::February;
    //а) уберите проблемы (это значит, что КОМПИЛЯТОР не
    //должен позволять программисту осуществлять опасные
    //сравнения!)
    //if (m == Monday) { /*...*/ }
    //б) оптимизируйте использование памяти
    months year[] = { months::January, months::February, months::March };
    size_t n = sizeof(year); //???
    cout << static_cast<int>(m) << n;
    //qDebug() << n << static_cast<int>(m);
}

void Task2()
{
    vector<string> strs {"Hello","Hi","Hei"};

    auto myFunc = [](char &c){c=toupper(c); return c;};

    for (auto& v : strs)
    {
        for_each(v.begin(), v.end(), myFunc);
    }

    for (string& v : strs)
        cout << v;
}

void Task3()
{
    map<char, set<const char*> > myMap { {'A',{"any","apple","away"}}};

    for(auto& [key, val] : myMap)
    {
        cout << key << " \n";
        for (auto& s : val) {
            cout << s << " ";
            cout << key << " \n";
        }
    }

    map<char, set<string> > map1;
    const char* s[] = { "yong", "away", "bar", "any", "son", "apple" };
    for(auto& arrEl : s)
    {
        map1[arrEl[0]].insert(arrEl);
    }

    for(auto& [key, val] : map1)
    {
        cout << key << " \n";
        for (auto& s : val) {
            cout << s << " ";
        }
        cout << " \n"<< " \n";
    }

}

template<typename T>
void PrintAnyCont(const T& t)
{
    for(auto& v : t)
    {
        cout << v << " ";
    }
    cout << "\n";
}

void Task4()
{

    std::vector<double> vd = { 1.1,2.2,3.3 };
    PrintAnyCont(vd);

    std::string s("abc");
    PrintAnyCont(s);

    int ar[] = { 1, 2, 3 };
    PrintAnyCont(ar);

    std::initializer_list<int> il{ 3,4,5 };
    PrintAnyCont(il);
}

void change_case (char &c) {
    if (std::isupper(c))
        c = tolower(c);
    else
        c = toupper(c);
}



void Task5()
{
    std::vector<double> vd{ 1.1,2.2,3.3 };
    NegateAll(vd);
    PrintAnyCont(vd);

    std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
    NegateAll(ls);
    PrintAnyCont(ls);

    int ar[]{ 1, 2, 3 };
    NegateAll(ar);
    PrintAnyCont(ar);
}

void Task6()
{
    std::vector<double> vd = { -3.3,  2.2, -1.1 };
    absSort(vd);
    PrintAnyCont(vd);

    int ar[] = { -3, 2, -1 };
    absSort(ar);
    PrintAnyCont(ar);
}

void Task7()
{
    std::vector<int> v{ 1,2,3,4 };
    std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5 };
    auto cont1 = SumCont(v, l);
    PrintAnyCont(cont1);

    std::list<int> ll{ 1, 2, 3, 4, 5, 6, 7, 8 };
    double ar[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    auto cont2 = SumCont(ar, ll);
    PrintAnyCont(cont2);

    std::set<std::string> s{ "abc", "qwerty", "my"};
    std::deque<const char*> d{ "111", "22" };
    auto cont3 = SumCont(s, d);
    PrintAnyCont(cont3);
}

void Task8()
{
    std::set<int> s;
    std::vector<int> v{ 1,2,3,4,5 };
    std::list<int> l; //сюда четные
    std::deque<int> d; //а сюда нечетные
    Separate(v, l, s, [](auto v) -> bool {return v%2;});
    PrintAnyCont(l);
    PrintAnyCont(d);
}

void Task9()
{
    char s[] = "Hello World!";
    int cnt = 0;
    for_each(begin(s),end(s),[&cnt](char c){if(c>='A' && c<='Z') ++cnt;});
    cout << cnt;
}

enum class COLORS { RED, GREEN, BLUE};


map<string, COLORS> EnumType<COLORS>::colors =
{ {"red", COLORS::RED}, {"green", COLORS::GREEN}, {"blue", COLORS::BLUE} };


void Task10()
{
    cout << stringToEnum<COLORS>(std::string("red")) << endl
         << stringToEnum<COLORS>("green") << endl
         << stringToEnum<COLORS>("blue") << endl;

    cout << endl;

    cout << EnumToString(COLORS::RED) << endl
         << EnumToString(COLORS::GREEN) << endl
         << EnumToString(COLORS::BLUE) << endl;

    cout << endl;

  //  cout << stringToEnum<int>("orange") << endl;
  //  cout << EnumToString<int>(6) << endl;

}

int main()
{


    //    Task1();
    //    Task2();
    //Task3();
    //Task4();
    //    Task5();
    //Task6();
    //Task7();
        Task8();
    //Task9();
//    Task10();

    return 0;
}
