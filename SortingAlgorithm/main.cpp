#include "SortUtil.h"
#include <time.h>
#include <iostream>
constexpr auto N = 100000;
void generateData(std::vector<int>& data) {
	data.clear();
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < N; i++)
	{

		data.push_back( RAND_MAX*rand() + rand() );

	}
}
void printhead(std::vector<int>& data) {

	for (size_t i = 0; i < 20; i++)
	{
		std::cout << data.at(i) << " ";
	}
	std::cout << std::endl;

}

int main() {
	
	std::vector<int> data;
	generateData(data);
	printhead(data);
	clock_t start = clock();
	SortUtil::InsertionSort(data);
	clock_t end = clock();
	std::cout << "插入排序用时 " << (end - start) << "ms" << std::endl;
	printhead(data);
	generateData(data); 
	start = clock();
	SortUtil::ShellSort(data);
	end = clock();
	std::cout << "希尔排序用时 " << (end - start) << "ms" << std::endl;
	generateData(data);
	start = clock();
	SortUtil::MergeSort(data);
	end = clock();
	std::cout << "归并排序用时 " << (end - start)<<"ms" << std::endl;
	generateData(data);
	start = clock();
	SortUtil::HeapSort(data);
	end = clock();
	std::cout << "堆排序用时 " << (end - start) << "ms" << std::endl;
	generateData(data);
	start = clock();
	SortUtil::QuickSort(data);
	end = clock();
	std::cout << "快速排序用时 " << (end - start) << "ms" << std::endl;

}