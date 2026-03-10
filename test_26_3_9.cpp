#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

// 编译报错：“operator +”必须至少有一个类类型的形参 
//int operator+(int x, int y)
//{
//    return x - y;
//}

class A
{
public:
    void func()
    {
        cout << "A::func()" << endl;
    }
};
typedef void(A::* PF)(); //成员函数指针类型 
int main()
{
    // C++规定成员函数要加&才能取到函数指针 
    PF pf = &A::func;
    A obj;//定义ob类对象temp 
    // 对象调用成员函数指针时，使用.*运算符 
    (obj.*pf)();
    return 0;
}