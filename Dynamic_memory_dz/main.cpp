#include "stdafx.h"
#include "FillRand.h"
#include "FillRand.cpp"
#include "Print.h"
#include "Print.cpp"
#include "Push.h"
#include "Push.cpp"
#include "Pop.h"
#include "Pop.cpp"
#include "insert_erase.h"
#include "insert_erase.cpp"
#include "all_clear.h"
#include "all_clear.cpp"

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

