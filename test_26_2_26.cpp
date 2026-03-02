#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//
//class Stack
//{
//	//成员函数
//	void push(int x)
//	{ }
//	void pop()
//	{ }
//	int top()
//	{ }
//
//	//成员变量
//	int* array;
//	size_t capacity;
//	size_t top;
//};



//class Date
//{
//public:
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//private:
//    // 为了区分成员变量，一般习惯上成员变量 
//    // 会加一个特殊标识，如_ 或者 m开头 
//    int _year; // year_  m_year
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d;
//    d.Init(2024, 3, 31);
//    return 0;
//}



//#include<iostream>
//using namespace std;
//class Stack
//{
//public:
//    // 成员函数 
//    void Init(int n = 4);
//private:
//    // 成员变量 
//    int* array;
//    size_t capacity;
//    size_t top;
//};
//// 声明和定义分离，需要指定类域 
//void Stack::Init(int n)
//{
//    array = (int*)malloc(sizeof(int) * n);
//    if (nullptr == array)
//    {
//        perror("malloc申请空间失败");
//        return;
//    }
//    capacity = n;
//    top = 0;
//}
//int main()
//{
//    Stack st;
//    st.Init();
//    return 0;
//}



//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    void Print()
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//private:
//    // 这里只是声明，没有开空间 
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    // Date类实例化出对象d1和d2 
//    Date d1;
//    Date d2;
//    d1.Init(2024, 3, 31);
//    d1.Print();
//    d2.Init(2024, 7, 5);
//    d2.Print();
//    return 0;
//}



#include<iostream>
using namespace std;
// 计算一下A/B/C实例化的对象是多大？ 
class A
{
public:
    void Print()
    {
        cout << _ch << endl;
    }
private:
    char _ch;
    int _i;
};
class B
{
public:
    void Print()
    {
        //...
    }
};
class C
{ };
int main()
{
    A a;
    B b;
    C c;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(c) << endl;
    return 0;
}