#pragma once

template <class T>
class GenericTest
{
public:
	GenericTest();
	~GenericTest();

	T Add(T a, T b);
	T Add(T a, T b, T c);
	//T Substract(T a, T b);
};


template<class T>
inline GenericTest<T>::GenericTest()
{
}

template<class T>
GenericTest<T>::~GenericTest()
{
}

template<class T>
inline T GenericTest<T>::Add(T a, T b)
{
	return a + b;
}
template<class T>
inline T GenericTest<T>::Add(T a, T b, T c)
{
	return a + b + c;
}