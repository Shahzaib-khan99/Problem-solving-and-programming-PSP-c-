#pragma once
#include<chrono>

std::chrono::microseconds correct_selectionsort(int* arr, int s);

std::chrono::microseconds wrong_selectionsort(int* arr, int s);

std::chrono::microseconds bubblesort(int* arr, int s);

std::chrono::microseconds insertionsort(int* arr, int s);

int* random_array(int s);
int* ascending_array(int s);
int* descending_array(int s);