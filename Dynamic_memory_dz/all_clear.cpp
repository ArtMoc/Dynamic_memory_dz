#include "all_clear.h"
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
template<typename T>
void clear(T** arr, const unsigned int rows)
{
	//3)удаляем строки 
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4)удаляем массив указателей
	delete[] arr;
}
