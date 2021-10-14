#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxValue = 100);
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxValue = 100);
void FillRand(char arr[], const unsigned int n);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const unsigned int rows, const unsigned int cols);

template<typename T>void Print(T arr[], const unsigned int n);

template<typename T>void push_back(T*& arr, int& n, int b_value);
template<typename T>void push_front(T*& arr, int& n, int f_value);
template<typename T>void insert(T*& arr, int& n, int i_value, int i_index);
template<typename T>void pop_back(T*& arr, int& n);
template<typename T>void pop_front(T*& arr, int& n);
template<typename T>void erase(T*& arr, int& n, int e_index);

///////////////////////ROWS///////////////////////
template<typename T>void FillRand(T** arr, const unsigned int rows, const unsigned int cols);
template<typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols);

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols); //yes
template<typename T>void clear(T** arr, const unsigned int rows); //yes

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** insert_row(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int i_index);
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** pop_row_front(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>T** erase_row(T** arr, unsigned int& rows, const unsigned int cols, unsigned int e_index);

//////////////////////COLS//////////////////////
template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void push_col_front(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void insert_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int i_index);
template<typename T>void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>void erase_col(T** arr, const unsigned int rows, unsigned int& cols, unsigned int e_index);

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
	typedef int DataType;
	DataType** arr = allocate<DataType>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n--------------- operations with rows ---------------\n" << endl;
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
	cout << "\n--------------- operations with cols ---------------\n" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	cout << "Enter the index where to insert the col: "; cin >> i_index;
	insert_col(arr, rows, cols, i_index);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "\n-------------------------------\n";
	cout << "Enter the index of the col to delete: "; cin >> e_index;
	erase_col(arr, rows, cols, e_index);
	Print(arr, rows, cols);
	clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

}

void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const unsigned int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>void Print(T arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	cout << endl;
}

template<typename T>void push_back(T*& arr, int& n, int b_value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = b_value;
	n++;
}
template<typename T>void push_front(T*& arr, int& n, int f_value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = f_value;
	n++;
}
template<typename T>void insert(T*& arr, int& n, int i_value, int i_index)
{
	T* buffer = new T[n + 2];
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
template<typename T>void pop_back(T*& arr, int& n)
{
	T* buffer = new T[n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n - 1] = n--;
}
template<typename T>void pop_front(T*& arr, int& n)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>void erase(T*& arr, int& n, int e_index)
{
	for (int i = e_index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

/////////////////////////
template<typename T>void FillRand(T** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
template<typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols)
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

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols)
{
	//1)добавляем указатель на указатель, и сохраняем в него адрес массива указателей:
	T** arr = new T * [rows];
	//2)создаем строки двумерного динамического массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template<typename T>void clear(T** arr, const unsigned int rows)
{
	//3)удаляем строки 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4)удаляем массив указателей
	delete[] arr;
}

template<typename T>T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T * [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** insert_row(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int i_index)
{
	T** buffer = new T * [rows + 1]{};
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
	arr[i_index] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template<typename T>T** pop_row_front(T** arr, unsigned int& rows, const unsigned int cols)
{
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template<typename T>T** erase_row(T** arr, unsigned int& rows, const unsigned int cols, unsigned int e_index)
{
	for (int i = e_index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}

template<typename T>void push_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void push_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void insert_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int i_index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < i_index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = i_index + 1; j < cols + 1; j++)
		{
			buffer[j] = arr[i][j - 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>void pop_col_back(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
template<typename T>void pop_col_front(T** arr, const unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}
template<typename T>void erase_col(T** arr, const unsigned int rows, unsigned int& cols, unsigned int e_index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < e_index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = e_index; j < cols - 1;j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;
}

