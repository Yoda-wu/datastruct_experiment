#include "BigInteger.h"
#include<iostream>
#include <ctime>
// 反转链表输出
void printList(List* node) {
	List newList;
	if (node->getSize() == 1) return;
	Node* numHead = node->getHead()->next;
	while(numHead != nullptr) {
		newList.push_back(numHead->data);
		numHead = numHead->next;
	}
	//newList.pop_back();
	Node* p = newList.getHead()->next;
	Node* head = (newList.getHead())->next;

	Node* temp;
	Node* pre = NULL;
	Node* cur = head->next;
	head->next = NULL;
	while (cur != nullptr) {
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	
	newList.setHead(pre);
	newList.push_back(node->getHead()->next->data);
	p = newList.getHead();
	while (p != nullptr) {
		std::cout << p->data ;
		p = p->next;
	}
	//std::cout << newList.getSize() << std::endl;

}
int main() {
	BigInteger b1("+1235674557441661541512316167126");
	BigInteger b2("+25167378532541248123515152461626");
	clock_t beginTime = clock();
	std::cout << "1235674557441661541512316167126 ^(6) = " ;
	BigInteger b3 = b1.power(6);
	double second = double(clock() - beginTime) / CLOCKS_PER_SEC;

	printList(b3.getNumber());
	std::cout << " 用时： " << second << "s" << std::endl;
	//std::cout << std::endl;
	//b3.printList();
	system("pause");
}