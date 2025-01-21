#ifndef QUICKSORTALGO_H
#define QUICKSORTALGO_H
#include<iostream>
using namespace std;


void SwapValQuick(int& x, int& y);
int Partition_Ahmed(int Arr[], int LeftIdx, int RightIdx);
void QuickSort_Ahmed(int Arr[], int LeftIdx, int RightIdx);
int Partition_AdelNasim1(int Arr[], int LeftIdx, int RightIdx);
void QuickSort_AdelNasim1(int Arr[], int LeftIdx, int RightIdx);
int Partition_AdelNasim2(int Arr[], int LeftIdx, int RightIdx);
void  QuickSort_AdelNasim2(int Arr[], int LeftIdx, int RightIdx);
void PrintArrayQuick(int Arr[], int size);


#endif //QUICKSORTALGO_H

