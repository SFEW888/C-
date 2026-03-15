#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    A(int a = 0)
//        :_a1(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//    A(const A& aa)
//        :_a1(aa._a1)
//    {
//        cout << "A(const A& aa)" << endl;
//    }
//    A& operator=(const A& aa)
//    {
//        cout << "A& operator=(const A& aa)" << endl;
//        if (this != &aa)
//        {
//            _a1 = aa._a1;
//        }
//        return *this;
//    }
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a1 = 1;
//};
//void f1(A aa)
//{ }
//A f2()
//{
//    A aa;
//    return aa;
//}
//int main()
//{
//    // 传值传参 
//    // 构造+拷⻉构造 
//    A aa1;
//    f1(aa1);
//    cout << endl;
//    // 隐式类型，连续构造+拷⻉构造->优化为直接构造 
//    f1(1);
//    // 一个表达式中，连续构造+拷⻉构造->优化为一个构造 
//    f1(A(2));
//    cout << endl;
//    cout << "***********************************************" << endl;
//    // 传值返回 
//    // 不优化的情况下传值返回，编译器会生成一个拷⻉返回对象的临时对象作为函数调用表达式的返回值
//
//    // 无优化 （vs2019 debug） 
//    // 一些编译器会优化得更厉害，将构造的局部对象和拷⻉构造的临时对象优化为直接构造（vs2022 debug）
//    f2();
//    cout << endl;
//    // 返回时一个表达式中，连续拷⻉构造+拷⻉构造->优化一个拷⻉构造 （vs2019 debug） 
//    // 一些编译器会优化得更厉害，进行跨行合并优化，将构造的局部对象aa和拷⻉的临时对象和接收返回值对象aa2优化为一个直接构造。（vs2022 debug）
//    A aa2 = f2();
//    cout << endl;
//    // 一个表达式中，开始构造，中间拷⻉构造+赋值重载->无法优化（vs2019 debug）
//    // 一些编译器会优化得更厉害，进行跨行合并优化，将构造的局部对象aa和拷⻉临时对象合并为一个直接构造（vs2022 debug）
//    aa1 = f2();
//    cout << endl;
//    return 0;
//}


#include<iostream>
using namespace std;

class A
{
public:
    A(int a = 0)
        :_a1(a)
    {
        cout << "A(int a)" << endl;
    }
    A(const A& aa)
        :_a1(aa._a1)
    {
        cout << "A(const A& aa)" << endl;
    }
    A& operator=(const A& aa)
    {
        cout << "A& operator=(const A& aa)" << endl;
        if (this != &aa)
        {
            _a1 = aa._a1;
        }
        return *this;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    int _a1 = 1;
};

void f1(A aa)
{ }

A f2()
{
    A aa;
    return aa;
}

int main()
{
    A aa1;
    f1(aa1);
    cout << endl;

    // 传值返回 
    // 不优化的情况下传值返回，编译器会生成一个拷贝返回对象的临时对象作为函数调用表达式的返回值

    // 无优化 （vs2019 debug） 
    // 一些编译器会优化得更厉害，将构造的局部对象和拷贝构造的临时对象优化为直接构造（vs2022 debug）
    f2();
    cout << endl;

    // 返回时一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造 （vs2019 debug） 
    // 一些编译器会优化得更厉害，进行跨行合并优化，将构造的局部对象aa和拷贝的临时对象和接收返回值对象aa2优化为一个直接构造。（vs2022 debug）
    A aa2 = f2();
    cout << endl;

    // 一个表达式中，开始构造，中间拷贝构造+赋值重载->无法优化（vs2019 debug）
    // 一些编译器会优化得更厉害，进行跨行合并优化，将构造的局部对象aa和拷贝临时对象合并为一个直接构造（vs2022 debug）
    aa1 = f2();
    cout << endl;

    return 0;
}

//int main()
//{
//    // 传值传参 
//    // 构造+拷贝构造 
//    A aa1;
//    f1(aa1);
//    cout << endl;
//
//    // 一个表达式中，连续构造+拷贝构造->优化为一个构造 
//    f1(A(1));
//    cout << endl;
//
//    // 隐式类型，连续构造+拷贝构造->优化为直接构造 
//    f1(1);
//
//    return 0;
//}

//int main()
//{
//    A aa1;//构造
//    f1(aa1);//拷贝构造
//
//    return 0;
//}


//int main()
//{
//    //由1构造临时对象，再拷贝构造，但编辑器优化为构造了
//    A aa1 = 1;
//
//    //一定会生成临时对象，但不会拷贝构造，因为是引用临时对象
//    const A& aa2 = 1;
//}