#define _CRT_SECURE_NO_WARNINGS

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}



//#include <iostream>
//using namespace std;
//
//template<typename T1, typename T2>
//void func(const T1& x, const T2& y)
//{ }
//
//int main()
//{
//	int i = 1;
//	double m = 2.5;
//
//	func(i, m);
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main(void)
//{
//	int a = 10;
//	double b = 20.1;
//
//	// 显式实例化
//	cout << Add<int>(a, b) << endl;
//	cout << Add<double>(a, b) << endl;
//
//	return 0;
//}

//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.1, d2 = 20.1;
//
//	cout << Add(a1, (int)d1) << endl;
//	cout << Add((double)a1, d1) << endl;
//
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//template<class T1, class T2>
//T1 Add(const T1& left, const T2& right)
//{
//	return left + right;
//}
//
//int main(void)
//{
//	int a = 10;
//	double b = 20.1;
//
//	cout << Add(a, b) << endl;
//	
//	return 0;
//}



//#include <iostream>
//using namespace std;
//
//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0);// 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

//template<class T>
//T* func(int n)
//{
//	return new T[n];
//}
//
//int main()
//{
//	func<int>(5);
//}



//#include <iostream>
//using namespace std;
//
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t n = 4)
//		:_array(new T[n])
//		,_size(0)
//		,_capacity(n)
//	{ }
//
//	~Stack()
//	{
//		delete[] _array;
//		_array = nullptr;
//		_size = _capacity = 0;
//	}
//
//	//扩容
//	void Push(const T& x)
//	{
//		if (_size = _capacity)
//		{
//			T* tmp = new T[_capacity * 2];//开辟新空间
//			memcpy(tmp, _array, sizeof(T) * _size);//拷贝数据
//			delete[] _array;//释放旧空间
//
//			//指向新空间
//			_array = tmp;
//			_capacity *= 2;
//		}
//
//		_array[_size++] = x;
//	}
//
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//int main()
//{
//	Stack<int> st1; // int
//	Stack<double> st2; // double
//	return 0;
//}



#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack(size_t n = 4)
		:_array(new T[n])
		, _size(0)
		, _capacity(n)
	{
	}

	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}

	//扩容
	void Push(const T& x);
	

private:
	T* _array;
	size_t _capacity;
	size_t _size;
};

template<class T>
void Stack<T>::Push(const T& x)
{
	if (_size = _capacity)
	{
		T* tmp = new T[_capacity * 2];//开辟新空间
		memcpy(tmp, _array, sizeof(T) * _size);//拷贝数据
		delete[] _array;//释放旧空间

		//指向新空间
		_array = tmp;
		_capacity *= 2;
	}

	_array[_size++] = x;
}

int main()
{
	Stack<int> st1; // int
	Stack<double> st2; // double
	return 0;
}