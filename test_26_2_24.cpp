#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <assert.h>
//using namespace std;
//void Func(int a = 0)
//{
//    cout << a << endl;
//}
//int main()
//{
//    Func();     // 没有传参时，使用参数的默认值 
//    Func(10);   // 传参时，使用指定的实参 
//    return 0;
//}



//#include <iostream>
//using namespace std;
//// 全缺省 
//void Func1(int a = 1, int b = 2, int c = 3)
//{
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl << endl;
//}
//// 半缺省 
//void Func2(int a, int b = 1, int c = 2)
//{
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl << endl;
//}
//int main()
//{
//    Func1();
//    Func1(10);
//    Func1(10, 20);
//    Func1(10, 20, 30);
//    Func2(100);
//    Func2(100, 200);
//    Func2(100, 200, 300);
//    return 0;
//}



//#include<iostream>
//using namespace std;
//
//int Add(int left, int right)
//{
//    cout << "int Add(int left, int right)" << endl;
//    return left + right;
//}
//double Add(double left, double right)
//{
//    cout << "double Add(double left, double right)" << endl;
//    return left + right;
//}
//
//int main()
//{
//    cout << Add(1, 1) << endl;
//    cout << Add(1.1, 2.2) << endl;
//
//    return 0;
//}



//#include<iostream>
//using namespace std;
//
//void f()
//{
//    cout << "f()" << endl;
//}
//void f(int a)
//{
//    cout << "f(int a)" << endl;
//}
//
//int main()
//{
//    f();
//    f(10);
//}


//#include<iostream>
//using namespace std;
//
//void f(int a, char b)
//{
//    cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//    cout << "f(char b, int a)" << endl;
//}
//
//int main()
//{
//    f(1, 'a');
//    f('a',1);
//}




//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 0;
//    // 引用：b和c是a的别名 
//    int& b = a;
//    int& c = a;
//    // 也可以给别名b取别名，d相当于还是a的别名 
//    int& d = b;
//    ++d;
//    // 这里取地址我们看到是一样的 
//    cout << &a << endl;
//    cout << &b << endl;
//    cout << &c << endl;
//    cout << &d << endl;
//    return 0;
//}



//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int a = 10;
//
//    // 编译报错：“ra”: 必须初始化引用 
//    //int& ra;
//
//    int& b = a;
//
//    int c = 20;
//    // 这里并非让b引用c，因为C++引用不能改变指向， 
//    // 这里是一个赋值 
//    b = c;
//    int& d = c;//引用取引用
//
//    cout << &a << endl;
//    cout << &b << endl;
//    cout << &c << endl;
//    cout << &d << endl;
//    return 0;
//}



#include<iostream>
using namespace std;

void Swap(int& rx, int& ry)
{
    int tmp = rx;
    rx = ry;
    ry = tmp;
}
int main()
{
    int x = 0, y = 1;
    cout << x << " " << y << endl;
    Swap(x, y);
    cout << x << " " << y << endl;
    return 0;
}




