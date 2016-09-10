#include <iostream>
using namespace std;

template<typename T>
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T elem);
	bool pop(T &elem);
	void stackTraverse(bool isFromBottom);

private:
	T *m_pBuffer;
	int m_iTop;
	int m_iSize;
};

template<typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}
template<typename T>
MyStack<T>::~MyStack()
{
	delete[]m_pBuffer;
	m_pBuffer = nullptr;
}
template<typename T>
bool MyStack<T>::stackEmpty()
{
	if (0 == m_iTop)
	{
		return true;
	}
	return false;
}
template<typename T>
bool MyStack<T>::stackFull()
{
	if (m_iTop == m_iSize)
	{
		return true;
	}
	return false;
}
template<typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0;
}
template<typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}
template<typename T>
bool MyStack<T>::push(T elem)
{
	if (stackFull())
	{
		return false;
	}
	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}
template<typename T>
bool MyStack<T>::pop(T &elem)
{
	if (stackEmpty())
	{
		return false;
	}
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}
template<typename T>
void MyStack<T>::stackTraverse(bool isFromBottom)
{
	if (isFromBottom)
	{
		for (int i = 0; i < stackLength(); i++)
		{
			cout << m_pBuffer[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = stackLength() - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i] << " ";
		}
		cout << endl;
	}
}