#include "BigInteger.h"
#include<iostream>

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
	while (p != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
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
	std::cout << std::endl;
	newList.setHead(pre);
	newList.push_back(node->getHead()->next->data);
	p = newList.getHead();
	while (p != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
	//std::cout << newList.getSize() << std::endl;

}
int main() {
	BigInteger b1("+999");
	BigInteger b2("+1000");
	BigInteger b3 = b2-b1;
	b3.printList();
	//List l = b3.reverseList();
	//std::cout << b3.getNumber()->getSize() << std::endl;
	printList(b3.getNumber());
	//std::cout << std::endl;
	//b3.printList();
	system("pause");
}