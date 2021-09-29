#include <iostream>
using std::cin;
using std::cout;
using std::endl;


#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);

void push_back(int*& arr, int& n, int b_value);
void push_front(int*& arr, int& n, int f_value);
void insert(int*& arr, int& n, int i_value, int i_index);
void pop_back(int*& arr, int& n);
void pop_front(int*& arr, int& n);
void erase(int*& arr, int& n, int e_index);

//////////////////////////////////

void FillRand(int** arr, const unsigned int rows, const unsigned int cols);
void Print(int** arr, const unsigned int rows, const unsigned int cols);

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, const unsigned int i_index);
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols);
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols);
int** erase_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int e_index);

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef DYNAMIC_MEMORY_1
	int n;
	int b_value;
	int f_value;
	cout << "Enter the size of array: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << "Enter the value to add to the end of the array: "; cin >> b_value;
	push_back(arr, n, b_value);
	Print(arr, n);
	cout << "Enter the value add to the beginning of the array: "; cin >> f_value;
	push_front(arr, n, f_value);
	Print(arr, n);
	int i_value;
	int i_index;
	cout << "Enter the value to add: "; cin >> i_value;
	cout << "Enter the index where to insert the value: "; cin >> i_index;
	insert(arr, n, i_value, i_index);
	Print(arr, n);
	cout << "Deleting the last element of the array: " << endl;
	pop_back(arr, n);
	Print(arr, n);
	cout << "Deleting the zero element of the array: " << endl;
	pop_front(arr, n);
	Print(arr, n);
	int e_index;
	int a = 0;
	cout << "Enter the index to delete: "; cin >> e_index;
	erase(arr, n, e_index);
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	unsigned int rows, cols;
	cout << "Enter the number of rows: ";cin >> rows;
	cout << "Enter the number of cols: ";cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	int i_index;
	cout << "Enter the index where to insert the row: "; cin >> i_index;
	arr = insert_row(arr, rows, cols, i_index);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	int e_index;
	cout << "Enter the index of the row to delete: "; cin >> e_index;
	arr = erase_row(arr, rows, cols, e_index);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	//Вывод массива через арифметику указателей и оператор разыменования
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

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

void push_back(int*& arr, int& n, int b_value)
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
}
void push_front(int*& arr, int& n, int f_value)
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
}
void insert(int*& arr, int& n, int i_value, int i_index)
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
}
void pop_back(int*& arr, int& n)
{
	int* buffer = new int[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n - 1] = n--;
}
void pop_front(int*& arr, int& n)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void erase(int*& arr, int& n, int e_index)
{
	for (int i = e_index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

void FillRand(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	//1)добавляем указатель на указатель, и сохраняем в него адрес массива указателей:
	int** arr = new int* [rows];
	//2)создаем строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	//3)удаляем строки 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4)удаляем массив указателей
	delete[] arr;
}

int** push_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int [cols] {};
	rows++;
	return arr;
}
int** push_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int [cols] {};
	rows++;
	return arr;
}
int** insert_row(int** arr, unsigned int& rows, const unsigned int cols, const unsigned int i_index)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = rows - 1; i >= i_index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[i_index] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int** pop_row_front(int** arr, unsigned int& rows, const unsigned int cols)
{
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
int** erase_row(int** arr, unsigned int& rows, const unsigned int cols, unsigned int e_index)
{
	for (int i = e_index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}