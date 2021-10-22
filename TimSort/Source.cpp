#include <iostream>
#include "vector.h"

int GetMinRun(int n) {
	int r = 0;
	while (n >= 64) {
		n >>= 1;
		r |= n & 1;
	}
	return n + r;
}

void SelectionSort(Vector <int> &p_d_arr, int left, int right) {

	for (int i = left; i < right; i++) {
		
		int minindex = i;
		
		for (int j = i + 1; j < right; j++) {
			if (p_d_arr[j] < p_d_arr[minindex]) minindex = j;
		}

		if (minindex != i) std::swap(p_d_arr[i], p_d_arr[minindex]);

	}
}

void Merge(Vector <int>& p_d_arr, int p, int q, int r)
{

	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	
	Vector <int> L(n1);
	Vector <int> R(n2);
	
	for (int i = 0; i < n1; i++) {
		L[i] = p_d_arr[p + i];
	}
	
	for (int j = 0; j < n2; j++) {
		R[j] = p_d_arr[q + j + 1];
	}
	
	i = 0, j = 0;
	
	for (k = p; i < n1 && j < n2; k++) {
		
		if (L[i] < R[j]) {
			p_d_arr[k] = L[i++];
		}
		else {
			p_d_arr[k] = R[j++];
		}
	}
	
	while (i < n1) {
		p_d_arr[k++] = L[i++];
	}

	while (j < n2) {
		p_d_arr[k++] = R[j++];
	}
}

void MergeSort(Vector <int>& p_d_arr, int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		MergeSort(p_d_arr, p, q);
		MergeSort(p_d_arr, q + 1, r);
		Merge(p_d_arr, p, q, r);
	}
}

void TimSort(Vector <int>& p_d_arr) {
	int minrun = GetMinRun(p_d_arr.size());
	int run = minrun;

	for (int i = 0; i < p_d_arr.size(); i += minrun) {
		run = std::min(minrun, int(p_d_arr.size() - i));
		SelectionSort(p_d_arr, i, i + run);
	}
	
	for (int size = run; size < p_d_arr.size(); size *= 2) {
		
		for (int left = 0; left < p_d_arr.size(); left += 2 * size) {
			
			int mid = left + size - 1;
			int right = std::min((left + 2 * size - 1), int(p_d_arr.size() - 1));
			
			if (mid < right) MergeSort(p_d_arr, left, right);
		
		}
	}
}

int main() {
	
	setlocale(LC_ALL, "rus");
	
	size_t l = 0;
	int range = 16384;
	
	//std::cout << "Enter array size: ";
	//std::cin >> l;
	l = 100000;
	std::cout << std::endl << std::endl;
	
	Vector <int> p_d_arr;
	srand(time(NULL));
	for (size_t i = 0; i < l; i++) {
		p_d_arr.push_back((rand() % range) - (range / 2));
		//std::cout << p_d_arr[i] << " ";
	}

	double atime = clock() / 1000.0;
	std::cout << std::endl << std::endl << "Approximate time of assignment: " << atime << " s";

	TimSort(p_d_arr);

	std::cout << std::endl << std::endl << "Result: " << std::endl << std::endl;

	/*for (int i = 0; i < l; i++) {
		std::cout << p_d_arr[i] << " ";
	}*/

	std::cout << std::endl << std::endl << "Approximate time of sorting: " << (clock() / 1000.0) - atime << " s" << std::endl;

	return 0;
}
