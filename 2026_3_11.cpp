#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//    //private:
//    int _year;
//    int _month;
//    int _day;
//};
//// 重载为全局的面临对象访问私有成员变量的问题 
//// 有几种方法可以解决： 
//// 1、成员放公有  
//// 2、Date提供getxxx函数 
//// 3、友元函数 
//// 4、重载为成员函数 
//bool operator==(const Date& d1, const Date& d2)
//{
//    return d1._year == d2._year
//        && d1._month == d2._month
//        && d1._day == d2._day;
//}
//int main()
//{
//    Date d1(2026, 3, 10);
//    Date d2(2026, 3, 11);
//
//    // 运算符重载函数可以显示调用 
//    operator==(d1, d2);
//    // 编译器会转换成 operator==(d1, d2); 
//    d1 == d2;
//    return 0;
//}




//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//    bool operator==(const Date& d)
//    {
//        return _year == d._year
//            && _month == d._month
//            && _day == d._day;
//    }
//    Date& operator++()
//    {
//        cout << "前置++" << endl;
//        //...
//        return *this;
//    }
//    Date operator++(int)
//    {
//        Date tmp;
//        cout << "后置++" << endl;
//        //...
//        return tmp;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1(2026, 3, 10);
//    Date d2(2026, 3, 11);
//    // 运算符重载函数可以显示调用 
//    d1.operator==(d2);
//    // 编译器会转换成 d1.operator==(d2); 
//    d1 == d2;
//    // 编译器会转换成 d1.operator++(); 
//    ++d1;
//    // 编译器会转换成 d1.operator++(0); 
//    d1++;
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    Date(const Date& d)
//    {
//        cout << " Date(const Date& d)" << endl;
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    // 传引用返回减少拷? 
//    // d1 = d2;
//    Date& operator=(const Date& d)
//    {
//        // 不要检查自己给自己赋值的情况 
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        // d1 = d2表达式的返回对象应该为d1，也就是*this 
//        return *this;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1(2026, 3, 10);
//    Date d2(d1);
//    Date d3(2026, 3, 11);
//    d1 = d3;
//    // 需要注意这里是拷?构造，不是赋值重载 
//    // 请牢牢记住赋值重载完成两个已经存在的对象直接的拷?赋值 
//    // 而拷?构造用于一个对象拷?初始化给另一个要创建的对象 
//    Date d4 = d1;
//    return 0;
//}




//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    Date(const Date& d)
//    {
//        cout << " Date(const Date& d)" << endl;
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    void operator=(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1(2026, 3, 10);
//    Date d2(d1);
//    Date d3(2026, 3, 11);
//    Date d4 = d3;
//
//    //d1 = d2 = d3;
//    // 需要注意这里是拷?构造，不是赋值重载 
//    // 请牢牢记住赋值重载完成两个已经存在的对象直接的拷?赋值 
//    // 而拷?构造用于一个对象拷?初始化给另一个要创建的对象 
//    Date d4 = d1;
//    return 0;
//}




#include<iostream>
using namespace std;
class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    // void Print(const Date* const this) const
    void Print() const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    // 这里非const对象也可以调用const成员函数是一种权限的缩小 
    Date d1(2024, 7, 5);
    d1.Print();
    const Date d2(2024, 8, 5);
    d2.Print();
    return 0;
}