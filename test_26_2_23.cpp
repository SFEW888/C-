#define _CRT_SECURE_NO_WARNINGS

//第一个C++程序
//// test.cpp
//#include<stdio.h>
//int main()
//{
//    printf("hello world\n");
//
//    return 0;
//}



//// test.cpp
//// 这里的std cout等我们都看不懂，没关系，下面我们会依次讲解 
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    cout << "hello world\n" << endl;
//
//    return 0;
//}


//#include <stdio.h>                                                             
//
//#include <stdlib.h>
//int rand = 10;
//int main()
//{
//    // 编译报错：error C2365: “rand”: 重定义；以前的定义是“函数” 
//    printf("%d\n", rand);
//    return 0;
//}



//#include <stdio.h>                                                             
//
//int rand = 10;
//int main()
//{
//    // 编译正常
//    printf("%d\n", rand);
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
////1.正常的命名空间定义 
//namespace sfew
//{
//    // 命名空间中可以定义变量/函数/类型 
//    int rand = 10;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//
//    struct Node
//    {
//        struct Node* next;
//        int val;
//    };
//}
//
//int a = 0;
//
//int main()
//{
//    int a = 10;
//    // 这里默认是访问的是局部域
//    printf("%d\n", a);
//    //访问全局的a
//    printf("%d\n", ::a);
//
//    // 这里默认是访问的是全局的rand函数指针 
//    printf("%p\n", rand);
//    // 这里指定命名空间中的rand 
//    printf("%d\n", sfew::rand);
//
//    printf("%d\n", sfew::Add(1, 2));
//
//    struct sfew::Node p;
//
//    return 0;
//}



//#include <stdio.h>
//
//namespace sfew
//{
//    //员工1 
//    namespace yg1
//    {
//        int rand = 1;
//        int Add(int left, int right)
//        {
//            return left + right;
//        }
//    }
//    //员工2 
//    namespace yg2
//    {
//        int rand = 2;
//        int Add(int left, int right)
//        {
//            return (left + right) * 10;
//        }
//    }
//}
//int main()
//{
//    printf("%d\n", sfew::yg1::rand);
//    printf("%d\n", sfew::yg2::rand);
//    printf("%d\n", sfew::yg1::Add(1, 2));
//    printf("%d\n", sfew::yg2::Add(1, 2));
//    return 0;
//}



//#include<stdio.h>
//namespace sfew
//{
//    int a = 0;
//    int b = 1;
//}
//int main()
//{
//    // 编译报错：error C2065: “a”: 未声明的标识符 
//    printf("%d\n", a);
//    return 0;
//}



//#include<stdio.h>
//namespace sfew
//{
//    int a = 0;
//    int b = 1;
//}
//
//int main()
//{
//    printf("%d\n", sfew::a);
//    return 0;
//}



//#include<stdio.h>
//namespace sfew
//{
//    int a = 0;
//    int b = 1;
//}
//
//using sfew::b;
//int main()
//{
//    printf("%d\n", sfew::a);
//    printf("%d\n", b);
//    return 0;
//}



//#include<stdio.h>
//
//namespace sfew
//{
//    int a = 0;
//    int b = 1;
//}
//
//using namespace sfew;
//
//int main()
//{
//    printf("%d\n", a);
//    printf("%d\n", b);
//    return 0;
//}



#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    double b = 3.14;
    char c = 's';

    cout << a << " " << b << "  " << c << endl;
    std::cout << a << " " << b << "  " << c << std::endl;
    scanf("%d%lf", &a, &b);
    printf("%d, %lf\n", a, b);

    // 可以自动识别变量的类型 
    cin >> a;
    cin >> b >> c;
    cout << a << endl;
    cout << b << "  " << c << endl;
    return 0;
}
