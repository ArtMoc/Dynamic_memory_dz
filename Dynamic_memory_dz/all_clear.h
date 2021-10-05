#pragma once
#include "stdafx.h"
int** allocate(const unsigned int rows, const unsigned int cols);
template<typename T>
void clear(T** arr, const unsigned int rows);
