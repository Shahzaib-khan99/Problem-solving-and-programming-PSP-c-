#include <iostream>

template <typename T>
class stack {
private:
	T* data;
	int size;
	int top;

public:
	stack(int s = 100)
	{
		this->top = -1;
		this->size = s;
		this->data = new T[s];
	}

	~stack()
	{
		delete[] data;
	}

	void push(T value)
	{
		this->top++;
		this->data[this->top] = value;
	}

	T Top()
	{
		if (this->top != -1)
		{
			return this->data[this->top];
		}
	}

	void pop()
	{
		if (this->top == -1)
		{
			std::cout << "stack underflow" << std::endl;
		}
		else
		{
			std::cout << "deleted element " << data[top] << std::endl;
			this->top--;
		}
	}

	bool empty()
	{
		if (this->top == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int Size()
	{
		return (top + 1);
	}

	void display()
	{
		if (this->top == -1)
		{
			std::cout << "stack is empty" << std::endl;
		}
		else
		{
			for (int i = top; i >= 0; i--)
			{
				std::cout << data[i] << " ";
			}
			std::cout << std::endl;
		}
	}
};