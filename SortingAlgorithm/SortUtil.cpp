#include "SortUtil.h"

void SortUtil::InsertionSort(std::vector<int>& arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; i++) {
		int key = arr[i];
		int j = i - 1;
		while ((j >= 0) && (key < arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void SortUtil::ShellSort(std::vector<int>& arr) {
	
	int len = arr.size();
	int gap = len / 2; 
	for (; gap > 0; gap /= 2) {
		// 分组插入排序
		for (int i = gap; i < len; i++) {
			int key = arr[i];
			int j = i;
			while ((j >= gap) && (key < arr[j - gap])) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = key;
		}
	}
}

void SortUtil::QuickSort(std::vector<int>& arr) {
	quickSort(arr, 0, arr.size() - 1);
}

void SortUtil::quickSort(std::vector<int>& arr, int left, int right) {

	if (left < right) {
		int key = arr[left];
		int i = left;
		int j = right;
		while (i< j)
		{
			while (i < j && arr[j] > key) {
				j--;
			}
			if (i < j) {
				arr[i] = arr[j];
				i++;
			}
			while (i< j && arr[i] < key)
			{
				i++;
			}
			if (i < j) {
				arr[j] = arr[i];
				j--;
			}
		}
		arr[i] = key;
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}

}
void SortUtil::MergeSort(std::vector<int>& arr) {
	std::vector<int> tempArr(arr.size());
	mergeSort(arr, tempArr, 0, arr.size() - 1);
}

void SortUtil::mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
	if (left < right) {
		int center = left + (right - left) / 2;
		mergeSort(arr, temp, left, center);
		mergeSort(arr, temp, center + 1, right);
		merge(arr, temp, left, center + 1, right);
	}

}
	
void SortUtil::merge(std::vector<int>& arr, std::vector<int>& temp,  int left, int center, int right) {
	int leftEnd = center - 1;
	int tempPos = left;
	int numElements = right - left + 1;

	while (left <= leftEnd && center <= right)
	{
		if (arr[left] <= arr[center]) {
			temp[tempPos++] = arr[left++];
		}
		else {
			temp[tempPos++] = arr[center++];
		}
	}
	while (left <= leftEnd) temp[tempPos++] = arr[left++];
	while (center <= right) temp[tempPos++] = arr[center++];

	for (int i = 0; i < numElements; i++, --right) {
		arr[right] = temp[right];
	}
}
void SortUtil::HeapSort(std::vector<int>& arr) {

	int len = arr.size();
	// 构建最大堆
	for (int i = (len)/2 - 1; i >= 0; i--)
	{
		percDown(arr, i, len);
	}
	// 删除最大值放在堆末尾
	for(int j = len - 1;  j > 0; j--)
	{
		int temp = arr[0];
		arr[0] = arr[j];
		arr[j] = temp;
		percDown(arr, 0, j);
	}
}

void SortUtil::percDown(std::vector<int>& arr, int i, int n) {

	int child;
	int temp;

	for (temp = arr[i]; 2 * i + 1 < n; i = child) {
		child = 2 * i + 1;
		if (child != n - 1 && arr[child] < arr[child + 1]) ++child;
		if (temp < arr[child]) arr[i] = arr[child];
		else break;

	}
	arr[i] = temp;
}