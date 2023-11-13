#pragma once

template <class T>
class Stack
{
public:
	Stack(int = 10);
	~Stack() {delete[] stackPtr; }
	bool push(const T&);
	bool pop(T&);
private:
	int size;
	int top;
	T* stackPtr;
	bool isEmpty() const { return top == -1; }
	bool isFull() const { return top == size - 1; }
};

template<class T>
Stack<T>::Stack(int s)
{
	size = s > 0 ? s : 10;
	top = -1;
	stackPtr = new T[size];
}

template<class T>
bool Stack<T>::push(const T& pushValue)
{
	if (!isFull())
	{
		stackPtr[++top] = pushValue;
		return true;
	}
	return false;
}

template<class T>
bool Stack<T>::pop( T& popValue)
{
	if (!isEmpty())
	{
		popValue = stackPtr[top--];
		return true;
	}
	return false;
}