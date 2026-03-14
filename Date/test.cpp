#include"Date.h"

void TestDate1()
{
    // 这里需要测试一下大的数据+和- 
    Date d1(2024, 4, 14);
    Date d2 = d1 + 30000;
    d1.Print();
    d2.Print();
    Date d3(2024, 4, 14);
    Date d4 = d3 - 5000;
    d3.Print();
    d4.Print();
    Date d5(2024, 4, 14);
    d5 += -5000;
    d5.Print();
}
void TestDate2()
{
    Date d1(2024, 4, 14);
    Date d2 = ++d1;
    d1.Print();
    d2.Print();
    Date d3 = d1++;
    d1.Print();
    d3.Print();
    /*d1.operator++(1);
    d1.operator++(100);
    d1.operator++(0);
    d1.Print();*/
}
void TestDate3()
{
    Date d1(2024, 4, 14);
    Date d2(2034, 4, 14);
    int n = d1 - d2;
    cout << n << endl;
    n = d2 - d1;
}
void TestDate4()
{
    Date d1(2024, 4, 14);
    Date d2 = d1 + 30000;
    // operator<<(cout, d1)
    cout << d1;
    cout << d2;
    cin >> d1 >> d2;
    cout << d1 << d2;
}
void TestDate5()
{
    const Date d1(2024, 4, 14);
    d1.Print();
    //d1 += 100;
    d1 + 100;
    Date d2(2024, 4, 25);
    d2.Print();
    d2 += 100;
    d1 < d2;
    d2 < d1;
}
int main()
{
    return 0;
}