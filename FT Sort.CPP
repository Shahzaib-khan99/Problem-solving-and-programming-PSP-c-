
#include <iostream>
using namespace std;

// A template function to implement bubble sort.

template <class T> 
void bubbleSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

int main()
{
	float a[5] = { 10.5, 50.2, 30, 40.2, 20 };
	char ch[5] = { 'y', 'x', 'a', 'd', 'b' };
	int n = sizeof(a) / sizeof(a[0]);
	int n1 = sizeof(ch) / sizeof(ch[0]);
	
	bubbleSort<float>(a, n);

	cout << " Sorted array : ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	bubbleSort<char>(ch, n1);
	cout << " Sorted array : ";
	for (int i = 0; i < n1; i++)
		cout << ch[i] << " ";

	return 0;
}

