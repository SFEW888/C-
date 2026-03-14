#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {    }
//
//    void Print() const
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year = 1;
//    int _month = 1;
//    int _day =1;
//};
//
//int main()
//{
//    Date d1(2026, 3, 14);
//    d1.Print();
//}


//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//    Time(int hour)
//        :_hour(hour)
//    {
//        cout << "Time()" << endl;
//    }
//private:
//    int _hour;
//};
//class Date
//{
//public:
//    Date(int& x, int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//        , _t(12)
//        , _ref(x)
//        , _n(1)
//        ,_ptr((int*)malloc(10))
//    {
//        if (_ptr == nullptr)
//        {
//            perror("malloc fail");
//        }
//        else
//        {
//            memset(_ptr, 0, 10);
//        }
//        // error C2512: “Time”: 没有合适的默认构造函数可用 
//        // error C2530 : “Date::_ref” : 必须初始化引用 
//        // error C2789 : “Date::_n” : 必须初始化常量限定类型的对象 
//    }
//    void Print() const
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;          // 没有默认构造 
//    int& _ref;          // 引用 
//    const int _n; // const 
//    int* _ptr;
//};
//int main()
//{
//    int i = 0;
//    int x = 0;
//    Date d1(i);
//    Date d2(x, 2026, 3, 14);
//    d1.Print();
//    d2.Print();
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//    Time(int hour)
//        :_hour(hour)
//    {
//        cout << "Time()" << endl;
//    }
//private:
//    int _hour;
//};
//
//class Date
//{
//public:
//    Date()
//        :_month(2)
//    {
//        cout << "Date()" << endl;
//    }
//    void Print() const
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    // 注意这里不是初始化，这里给的是缺省值，这个缺省值是给初始化列表的 
//    // 如果初始化列表没有显示初始化，默认就会用这个缺省值初始化 
//    int _year = 1;
//    int _month = 1;
//    int _day;
//    Time _t = 1;
//    const int _n = 1;
//    int* _ptr = (int*)malloc(12);
//};
//
//int main()
//{
//    Date d1;
//    d1.Print();
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//    A(int a)
//        :_a1(a)
//        , _a2(_a1)
//    {
//    }
//    void Print() {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    int _a2 = 2;
//    int _a1 = 2;
//};
//
//int main()
//{
//    A aa(1);
//    aa.Print();
//}



//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//    // 构造函数explicit就不再支持隐式类型转换 
//    // explicit A(int a1)
//    A(int a1)
//        :_a1(a1)
//    {
//    }
//    //explicit A(int a1, int a2)
//    A(int a1, int a2)
//        :_a1(a1)
//        , _a2(a2)
//    {
//    }
//    void Print()
//    {
//        cout << _a1 << " " << _a2 << endl;
//    }
//    int Get() const
//    {
//        return _a1 + _a2;
//    }
//private:
//    int _a1 = 1;
//    int _a2 = 2;
//};
//
//class B
//{
//public:
//    B(const A& a)
//        :_b(a.Get())
//    {
//    }
//private:
//    int _b = 0;
//};
//
//int main()
//{
//    // 1构造一个A的临时对象，再用这个临时对象拷?构造aa3 
//    // 编译器遇到连续构造+拷?构造->优化为直接构造 
//    A aa1 = 1;
//    aa1.Print();
//    const A& aa2 = 1;
//    // C++11之后才支持多参数转化 
//    A aa3 = { 2,2 };
//    // aa3隐式类型转换为b对象 
//    // 原理跟上面类似 
//    B b = aa3;
//    const B& rb = aa3;
//    return 0;
//}


#include<iostream>
using namespace std;
class A
{
public:
    A()
    {
        ++_scount;
    }
    A(const A& t)
    {
        ++_scount;
    }
    ~A()
    {
        --_scount;
    }
    static int GetACount()
    {
        //_a++;
        return _scount;
    }
private:
    // 类里面声明 
    static int _scount;
};
// 类外面初始化 
int A::_scount = 0;

int main()
{
    cout << A::GetACount() << endl;
    A a1, a2;
    A a3(a1);
    cout << A::GetACount() << endl;
    cout << a1.GetACount() << endl;
    // 编译报错：error C2248: “A::_scount”: 无法访问 private 成员(在“A”类中声明) 
    //cout << A::_scount << endl;
    return 0;
}



