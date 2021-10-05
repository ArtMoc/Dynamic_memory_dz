#include "Clear.h"
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