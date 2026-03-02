#define _CRT_SECURE_NO_WARNINGS

//#include<iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//    // void Init(Date* const this, int year, int month, int day)
//    void Init(int year, int month, int day)
//    {
//        // 编译报错：error C2106: “=”: 左操作数必须为左值 
//        // this = nullptr;
//        // this->_year = year;
//        _year = year;
//        this->_month = month;
//        this->_day = day;
//    }
//
//    //void Print(Date* const this)
//    void Print()
//    {
//        cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
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
//
//    // d1.Init(&d1, 2024, 3, 31);
//    d1.Init(2024, 3, 31);
//    d1.Print();
//    d2.Init(2024, 7, 5);
//    d2.Print();
//    return 0;
//}





//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    void Print()
//    {
//        cout << "A::Print()" << endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    A* p = nullptr;
//    p->Print();
//    return 0;
//}



//#include<iostream>
//using namespace std;
//class A
//{
//public:
//    void Print()
//    {
//        cout << "A::Print()" << endl;
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->Print();
//    return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//#include<assert.h>
//typedef int STDataType;
//typedef struct Stack
//{
//    STDataType* a;
//    int top;
//    int capacity;
//}ST;
//void STInit(ST* ps)
//{
//    assert(ps);
//    ps->a = NULL;
//    ps->top = 0;
//    ps->capacity = 0;
//}
//void STDestroy(ST* ps)
//{
//    assert(ps);
//    free(ps->a);
//    ps->a = NULL;
//    ps->top = ps->capacity = 0;
//}
//void STPush(ST* ps, STDataType x)
//{
//    assert(ps);
//    // 满了， 扩容 
//    if (ps->top == ps->capacity)
//    {
//        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//        STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity *
//            sizeof(STDataType));
//        if (tmp == NULL)
//        {
//            perror("realloc fail");
//            return;
//        }
//        ps->a = tmp;
//        ps->capacity = newcapacity;
//    }
//    ps->a[ps->top] = x;
//    ps->top++;
//}
//bool STEmpty(ST* ps)
//{
//    assert(ps);
//    return ps->top == 0;
//}
//void STPop(ST* ps)
//{
//    assert(ps);
//    assert(!STEmpty(ps));
//    ps->top--;
//}
//STDataType STTop(ST* ps)
//{
//    assert(ps);
//    assert(!STEmpty(ps));
//    return ps->a[ps->top - 1];
//}
//int STSize(ST* ps)
//{
//    assert(ps);
//    return ps->top;
//}
//int main()
//{
//    ST s;
//    STInit(&s);
//    STPush(&s, 1);
//    STPush(&s, 2);
//    STPush(&s, 3);
//    STPush(&s, 4);
//    while (!STEmpty(&s))
//    {
//        printf("%d\n", STTop(&s));
//        STPop(&s);
//    }
//    STDestroy(&s);
//    return 0;
//}





#include<iostream>
#include<cassert>

using namespace std;

typedef int STDataType;
class Stack
{
public:
    // 成员函数 
    void Init(int n = 4)
    {
        _a = (STDataType*)malloc(sizeof(STDataType) * n);
        if (nullptr == _a)
        {
            perror("malloc申请空间失败");
            return;
        }
        _capacity = n;
        _top = 0;
    }
    void Push(STDataType x)
    {
        if (_top == _capacity)
        {
            int newcapacity = _capacity * 2;
            STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
                sizeof(STDataType));
            if (tmp == NULL)
            {
                perror("realloc fail");
                return;
            }
            _a = tmp;
            _capacity = newcapacity;
        }
        _a[_top++] = x;
    }
    void Pop()
    {
        assert(_top > 0);
        --_top;
    }
    bool Empty()
    {
        return _top == 0;
    }
    int Top()
    {
        assert(_top > 0);
        return _a[_top - 1];
    }
    void Destroy()
    {
        free(_a);
        _a = nullptr;
        _top = _capacity = 0;
    }
private:
    // 成员变量 
    STDataType* _a;
    size_t _capacity;
    size_t _top;
};

int main()
{
    Stack s;
    s.Init();
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    while (!s.Empty())
    {
        printf("%d\n", s.Top());
        s.Pop();
    }
    s.Destroy();
    return 0;
}