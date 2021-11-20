#pragma once
#include <vector>
/**
* ���򷽷���
*/
class SortUtil {
	
private:
	/**
	* ���ݺ���
	*/
	static void percDown(std::vector<int>&, int , int );
	/**
	* �鲢����
	*/
	static void merge(std::vector<int>&, std::vector<int>&, int, int, int);
	/**
	* �鲢����ݹ麯��
	*/
	static void mergeSort(std::vector<int>&, std::vector<int>&, int, int);
	/**
	* ��������ݹ麯��
	*/
	static void quickSort(std::vector<int>&, int, int);

public:

	SortUtil() {}
	~SortUtil() {}

	/**
	* ��������
	*/
	static void InsertionSort(std::vector<int>&);

	/**
	* ϣ������
	*/
	static void ShellSort(std::vector<int>&);

	/**
	* ��������
	*/
	static void QuickSort(std::vector<int>&);

	/**
	* �鲢����
	*/
	static void MergeSort(std::vector<int>&);
	
	/**
	* ������
	*/
	static void HeapSort(std::vector<int>&);


};
