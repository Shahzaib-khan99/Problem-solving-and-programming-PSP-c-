//When a function is declared as const, it can be called on any type of object, 
//const object as well as non-const objects.

#include <iostream>
using namespace std;

class Test {
	int value;

public:
	Test(int v = 0) 
	{ value = v; }

	int getValue() const 
	{ return value; }
};

int main()
{
	Test t(20);
	cout << t.getValue();
	return 0;
}

