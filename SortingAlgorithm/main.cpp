#include "SortUtil.h"
#include <time.h>
#include <iostream>
constexpr auto N = 100000;
void generateData(std::vector<int>& data) {
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < N; i++)
	{
		data.push_back(1 + rand() % 100000);
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
	SortUtil::QuickSort(data);
	printhead(data);
}