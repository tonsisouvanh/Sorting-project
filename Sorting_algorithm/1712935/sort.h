#ifndef __sort_H__
#define __sort_H__
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<string>
static int *L = NULL, *R = NULL;
using namespace std;
class SORT{
private:
	int N_hundred = 100;
	int N_thousand = 1000;
	int N5_thousand = 5000;
	int N10_thousand = 10000;
	int N50_thousand = 50000;
	int N100_thousand = 100000;
	vector<int> Arr;
private:
	void output(double,string,int);

						void bubbleSort_Progress(int);
						void selectionSort_Progress(int);
						void insertionSort_Progress(int);
						void heapSort_Progress(int);
							void creatHeap(int*, int);
							void Shift(int*, int, int);
						void quicksort_progress(int);
							void quicksort(int*, int, int);
							int partition(int*, int, int);
						void mergeSort_Progress(int);
							void mergeSort(int *, int, int);
							void merge(int *, int, int, int);
						void radixSort_Progress(int);
public:
					 void case_sorted(int);
						 void case_sorted_assign(int);
					 void case_reversed(int);
						 void case_reversed_assign(int);
					 void case_random(int);
						 void case_random_assign(int n);

					void N_IndexOfarray_sort(int,int);
								 
};
#endif
