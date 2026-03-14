#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#include<cassert>

class Date
{
    // 友元函数声明 
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 2026, int month = 1, int day = 1);
	void Print() const;

    int GetMonthDay(int year, int month) const
    {
        assert(month > 0 && month < 13);

        static int monthDayArray[13] = { -1, 31, 28,31,30,31,30,31,31,30,31,30,31 };
        //因为频繁调用所以设置成静态更好

        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            return 29;
        }

        return monthDayArray[month];
    }

    bool CheckDate();

    bool operator<(const Date& d) const;
    bool operator<=(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator>=(const Date& d) const;
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;

    // d1 += 天数 
    Date& operator+=(int day);
    Date operator+(int day) const;

    // d1 -= 天数 
    Date& operator-=(int day);
    Date operator-(int day) const;

    int operator-(const Date& d) const;

    // ++d1 -> d1.operator++()
    Date& operator++();
    // d1++ -> d1.operator++(0)
    Date operator++(int);

    Date& operator--();
    Date operator--(int);

    // 流插入 
    // 不建议，因为Date* this占据了一个参数位置，使用d<<cout不符合习惯 
    //void operator<<(ostream& out);
private:
	int _year;
	int _month;
	int _day;
};


// 重载 
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);