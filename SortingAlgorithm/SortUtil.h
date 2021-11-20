#pragma once
#include <vector>
/**
* 排序方法类
*/
class SortUtil {
	
private:
	/**
	* 下陷函数
	*/
	static void percDown(std::vector<int>&, int , int );
	/**
	* 归并函数
	*/
	static void merge(std::vector<int>&, std::vector<int>&, int, int, int);
	/**
	* 归并排序递归函数
	*/
	static void mergeSort(std::vector<int>&, std::vector<int>&, int, int);
	/**
	* 快速排序递归函数
	*/
	static void quickSort(std::vector<int>&, int, int);

public:

	SortUtil() {}
	~SortUtil() {}

	/**
	* 插入排序
	*/
	static void InsertionSort(std::vector<int>&);

	/**
	* 希尔排序
	*/
	static void ShellSort(std::vector<int>&);

	/**
	* 快速排序
	*/
	static void QuickSort(std::vector<int>&);

	/**
	* 归并排序
	*/
	static void MergeSort(std::vector<int>&);
	
	/**
	* 堆排序
	*/
	static void HeapSort(std::vector<int>&);


};
