#include <iostream>
using namespace std;

template<typename T>
class Stack
{
	unsigned int capacity = 10; // резерв памяти
	T* ar = new T[capacity];
	unsigned int size = 0;

public:
	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	[[deprecated]] // пометка метода как устаревшего, что позволит клиенту получить некоторое время на изменение своего кода
	bool IsFull() const
	{
		return false;
	}

	int GetCount() const
	{
		return size;
	}

	void Push(T value)
	{
		if (size == capacity)
		{
			T* temp = new int[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = ar[i];
			}
			delete[] ar;
			capacity *= 2;
			ar = temp;
		}

		ar[size++] = value;
	}

	int Pop()
	{
		if (!IsEmpty())
		{
			--size;
			return ar[size];
		}
		else
		{
			throw "Stack is empty!";
		}
	}
	~Stack()
	{
		delete[] ar;
	}
};

int main()
{
	//int
	Stack<int> st; // создаём "пустой" стек

	for (int i = 0; i < 10000000; i++)
	{
		st.Push(rand() % 100);
	}
	cout << "OK!\n";
	for (int i = 0; i < 10000000; i++)
	{
		cout << st.Pop() << "\n";
	}
}