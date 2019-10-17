#include"sort.h"
void  SORT::case_sorted_assign(int n){
	srand(time(NULL));
	vector<int> bucket;
	vector<int> unsorted;
	vector<int> b; b.assign(n, 0);
	for (int i = 0; i<n; i++)
		this->Arr.push_back(rand() % 1000);

	int i, m = this->Arr[0], exp = 1;
	for (i = 0; i < n; i++) {
		if (this->Arr[i] > m){
			m = this->Arr[i];
		}
	}
	while (m / exp > 0) {
		bucket.assign(10, 0);
		for (i = 0; i < n; i++){
			bucket[this->Arr[i] / exp % 10]++;
		}
		for (i = 1; i < 10; i++){
			bucket[i] += bucket[i - 1];
		}
		for (i = n - 1; i >= 0; i--){
			b[--bucket[this->Arr[i] / exp % 10]] = this->Arr[i];
		}
		for (i = 0; i < n; i++){
			this->Arr[i] = b[i];
		}
		exp *= 10;
	}
}
void SORT::case_reversed_assign(int n){
	srand(time(NULL));
	vector<int> b; b.assign(n, 0);
	vector<int> bucket;
	for (int i = 0; i<n; i++)
		this->Arr.push_back(rand() % 1000);

	int i, m = 0, exp = 1;
	for (i = 0; i<n; i++)
		if (this->Arr[i]>m)
			m = this->Arr[i];
		while (m / exp > 0)
		{
			bucket.assign(n, 0);
			for (i = 0; i < n; i++)
				bucket[9 - this->Arr[i] / exp % 10]++;
			for (i = 1; i < 10; i++)
				bucket[i] += bucket[i - 1];
			for (i = n - 1; i >= 0; i--)
				b[--bucket[9 - this->Arr[i] / exp % 10]] = this->Arr[i];
			for (i = 0; i < n; i++)
				this->Arr[i] = b[i];        
			exp *= 10;
		}
	
}

void SORT::case_random_assign(int n){
	srand(time(NULL));
	vector<int> bucket;
	vector<int> unsorted;
	vector<int> b; b.assign(n, 0);
	for (int i = 0; i < n; i++)
		this->Arr.push_back(rand() % 1000);
}

void SORT::case_sorted(int index){
	cout << "[SORTED DATA CASE]" << endl;
	N_IndexOfarray_sort(this->N_hundred, index);
	N_IndexOfarray_sort(this->N_thousand, index);
	N_IndexOfarray_sort(this->N5_thousand, index);
	N_IndexOfarray_sort(this->N10_thousand, index);
	N_IndexOfarray_sort(this->N50_thousand, index);
	N_IndexOfarray_sort(this->N100_thousand, index);
}
void SORT::case_reversed(int index){
	cout << "[REVERSED DATA CASE]" << endl;
	N_IndexOfarray_sort(this->N_hundred,index);
	N_IndexOfarray_sort(this->N_thousand,index);
	N_IndexOfarray_sort(this->N5_thousand,index);
	N_IndexOfarray_sort(this->N10_thousand,index);
	N_IndexOfarray_sort(this->N50_thousand,index);
	N_IndexOfarray_sort(this->N100_thousand,index);
}
void SORT::case_random(int index){
	cout << "[RANDOM DATA CASE]" << endl;
	//N_IndexOfarray_sort(this->N_hundred, index);
	//N_IndexOfarray_sort(this->N_thousand, index);
	N_IndexOfarray_sort(this->N5_thousand, index);
	//N_IndexOfarray_sort(this->N10_thousand, index);
	//N_IndexOfarray_sort(this->N50_thousand, index);
	//N_IndexOfarray_sort(this->N100_thousand, index);
}

void SORT::N_IndexOfarray_sort(int n, int index){
	if (index == 1)
		case_sorted_assign(n);
	else if (index == 2)
		case_reversed_assign(n);
	else
		case_random_assign(n);
	cout << "- Run time for sorting -> " << n << " <- elements of array:" << endl;

	bubbleSort_Progress(n);
	selectionSort_Progress(n);
	insertionSort_Progress(n);
	heapSort_Progress(n);
	quicksort_progress(n);
	mergeSort_Progress(n);
	radixSort_Progress(n);
}

void SORT::merge(int *arr, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	L = new int[n1], R = new int[n2];
	for (i = 0; i < n1; i++){ L[i] = arr[l + i]; }
	for (j = 0; j < n2; j++){ R[j] = arr[m + 1 + j]; }
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}
void SORT::mergeSort(int *arr, int l, int r){
	if (l < r){
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
void SORT::mergeSort_Progress(int N){
	clock_t begin = clock();
	int *arr = NULL;
	arr = new int[N];
	for (int i = 0; i < N; i++){
		arr[i] = this->Arr[i];
	}
	int l = 0, r = N - 1;
	mergeSort(arr, l, r);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	output(time_spent, "Merge", N);
	delete[]arr;
}
int SORT::partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int i = (start - 1);

	for (int j = start; j <= end - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[end]);
	return (i + 1);
}
void SORT::quicksort(int *arr, int start, int end)
{
	if (start < end)
	{
		int pi = partition(arr, start, end);
		quicksort(arr, start, pi - 1);
		quicksort(arr, pi + 1, end);
	}
}
void SORT::quicksort_progress(int N){
	clock_t begin = clock();
	int l = 0, r = N-1; int *arr = NULL;
	arr = new int[N];
	for (int i = 0; i < N; i++){
		arr[i] = this->Arr[i];
	}
	quicksort(arr, l, r);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	output(time_spent, "Quick", N);
	delete[]arr;
}

void SORT::Shift(int* a, int l, int r){
	int x, i, j;
	i = l;   j = 2 * i;
	x = a[i - 1];
	while (j <= r)
	{
		if (j < r)
		if (a[j - 1] < a[j]){ j = j + 1; }
		if (a[j - 1] < x){ return; }
		else
		{
			a[i - 1] = a[j - 1];
			a[j - 1] = x;
			i = j;
			j = 2 * i;
		}
	}
}
void SORT::creatHeap(int* a, int N)
{
	int l;
	l = N / 2;
	while (l > 0)
	{
		Shift(a, l, N);
		l = l - 1;
	}
}
void SORT::heapSort_Progress(int N)
{
	clock_t begin = clock();
	int *arr = NULL;
	arr = new int[N];
	for (int i = 0; i<N; i++){
		arr[i] = this->Arr[i];
	}

	int r;
	creatHeap(arr, N);
	r = N - 1;
	while (r > 0)
	{
		swap(arr[0], arr[r]);
		r = r - 1;
		Shift(arr, 1, r + 1);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	output(time_spent, "Heap", N);
	delete[]arr;
}

void SORT::insertionSort_Progress(int N){
	clock_t begin = clock();
	vector<int> arr = this->Arr;
		for (int i = 1; i < N; i++){
			int j = i;
			while (j>0){
				if (arr[j] < arr[j - 1]){
					swap(arr[j], arr[j - 1]);
				}
				j--;
			}
		}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	output(time_spent, "Insertion", N);
}

void SORT::selectionSort_Progress(int N){
	clock_t begin = clock();
	vector<int> arr = this->Arr;
	int min = 0;
	for (int i = 0; i < N - 1; i++){
		min = i;
		for (int j = i + 1; j < N; j++){
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		swap(arr[min], arr[i]);
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	output(time_spent, "Selection", N);
}

void SORT::bubbleSort_Progress(int n){
	clock_t begin = clock();
	vector<int> arr = this->Arr;
	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j>i; j--)
	if (arr[j-1] < arr[j])
		swap(arr[j], arr[j - 1]);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	output(time_spent, "Bubble", n);
}


void SORT::radixSort_Progress(int n){
	clock_t begin = clock();
	vector<int> bucket;
	vector<int> arr; arr = this->Arr;
	vector<int> b; b.assign(n, 0);

	int i, m = arr[0], exp = 1;
	for (i = 0; i < n; i++) {
		if (arr[i] > m){
			m = arr[i];
		}
	}
	while (m / exp > 0) {
		bucket.assign(10, 0);
		for (i = 0; i < n; i++){
			bucket[arr[i] / exp % 10]++;
		}
		for (i = 1; i < 10; i++){
			bucket[i] += bucket[i - 1];
		}
		for (i = n - 1; i >= 0; i--){
			b[--bucket[arr[i] / exp % 10]] = arr[i];
		}
		for (i = 0; i < n; i++){
			arr[i] = b[i];
		}
		exp *= 10;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	output(time_spent, "Radix", n);
}

void SORT::output(double time, string algor, int n){
	cout << "\t" << algor << " sort = " << time << endl;
}
