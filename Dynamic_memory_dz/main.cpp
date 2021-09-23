#include <iostream>
using namespace std;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);

int* push_back(int arr[], int& n, int b_value);
int* push_front(int arr[], int& n, int f_value);
int* insert(int arr[], int& n, int i_value, int i_index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int e_index);

void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	int b_value;
	int f_value;
	cout << "Enter the size of array: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << "Enter the value to add to the end of the array: "; cin >> b_value;
	arr = push_back(arr, n, b_value);
	Print(arr, n);
	cout << "Enter the value add to the beginning of the array: "; cin >> f_value;
	arr = push_front(arr, n, f_value);
	Print(arr, n);
	int i_value;
	int i_index;
	cout << "Enter the value to add: "; cin >> i_value;
	cout << "Enter the index where to insert the value: "; cin >> i_index;
	arr = insert(arr, n, i_value, i_index);
	Print(arr, n);
	cout << "Deleting the last element of the array: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Deleting the zero element of the array: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	int e_index;
	int a = 0;
	cout << "Enter the index to delete: "; cin >> e_index;
	arr = erase(arr, n, e_index);
	Print(arr, n);
	delete[] arr;
}


void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int b_value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = b_value;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int f_value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = f_value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int i_value, int i_index)
{
	int* buffer = new int[n + 2];
	for (int i = 0; i < i_index; i++)
	{
		buffer[i] = arr[i];
		buffer[i_index] = i_value;
	}
	for (int i = i_index + 1; i < n + 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	arr[i_index] = i_value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n - 1] = n--;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int arr[], int& n, int e_index)
{
	int* buffer = new int[n];
	for (int i = e_index; i < n - 1; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}