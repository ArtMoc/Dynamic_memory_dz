#pragma once
#include "stdafx.h"
template<typename T>
void push_back(T*& arr, int& n, int b_value);
template<typename T>
void push_front(T*& arr, int& n, int f_value);
template<typename T>
T** push_row_back(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>
T** push_row_front(T** arr, unsigned int& rows, const unsigned int cols);
template<typename T>
void push_col_back(T** arr, const unsigned int rows, unsigned int& cols);
template<typename T>
void push_col_front(T** arr, const unsigned int rows, unsigned int& cols);
