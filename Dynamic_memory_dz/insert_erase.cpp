#include "insert_erase.h"
template<typename T>
void insert(T*& arr, int& n, int i_value, int i_index)
{
	T* buffer = new int[n + 2];
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
template<typename T>
void erase(T*& arr, int& n, int e_index)
{
	for (int i = e_index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}
template<typename T>
T** insert_row(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int i_index)
{
	T** buffer = new int* [rows + 1]{};
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
template<typename T>
T** erase_row(T** arr, unsigned int& rows, const unsigned int cols, unsigned int e_index)
{
	for (int i = e_index; i < rows - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	rows--;
	return arr;
}
template<typename T>
void insert_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int i_index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new int[cols + 1]{};
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
template<typename T>
void erase_col(T** arr, const unsigned int rows, unsigned int& cols, unsigned int e_index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new int[cols - 1]{};
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