#pragma once
#include <vector>
/**
* ≈≈–Ú∑Ω∑®¿‡
*/
class SortUtil {
	
private:
	static void percDown(std::vector<int>&, int , int );
	static void merge(std::vector<int>&, std::vector<int>&, int, int, int);
	static void mergeSort(std::vector<int>&, std::vector<int>&, int, int);
	static void quickSort(std::vector<int>&, int, int);
public:
	SortUtil() {}
	~SortUtil() {}

	/**
	* ≤Â»Î≈≈–Ú
	*/
	static void InsertionSort(std::vector<int>&);

	/**
	* œ£∂˚≈≈–Ú
	*/
	static void ShellSort(std::vector<int>&);

	/**
	* øÏÀŸ≈≈–Ú
	*/
	static void QuickSort(std::vector<int>&);

	/**
	* πÈ≤¢≈≈–Ú
	*/
	static void MergeSort(std::vector<int>&);
	
	/**
	* ∂—≈≈–Ú
	*/
	static void HeapSort(std::vector<int>&);


};
