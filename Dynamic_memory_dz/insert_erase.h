#pragma once
#include "stdafx.h"
template<typename T>
void insert(T*& arr, int& n, int i_value, int i_index);
template<typename T>
void erase(T*& arr, int& n, int e_index);
template<typename T>
T** insert_row(T** arr, unsigned int& rows, const unsigned int cols, const unsigned int i_index);
template<typename T>
T** erase_row(T** arr, unsigned int& rows, const unsigned int cols, unsigned int e_index);
template<typename T>
void insert_col(T** arr, const unsigned int rows, unsigned int& cols, const unsigned int i_index);
template<typename T>
void erase_col(T** arr, const unsigned int rows, unsigned int& cols, unsigned int e_index);
