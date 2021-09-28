#include "BigInteger.h"
#include<iostream>

void printList(List* l) {
	Node* p = l->getHead()->next;
	while (p != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

BigInteger::BigInteger() {
	init();
}

BigInteger::BigInteger(std::string bigNum) {
	init();
	for (int i = bigNum.size() - 1; i > 0; i--) {
		int val = bigNum[i] - ZERO;
		numbers->push_back(val);
	}
	sign = bigNum[0] == '+' ? POSITIVE : NEGATIVE;
}

BigInteger::BigInteger(long bigNum) {
	sign = bigNum > 0 ? POSITIVE : NEGATIVE;
}

BigInteger::BigInteger(const BigInteger& bigNum) {
	this->sign = bigNum.sign;
	
	this->numbers = bigNum.numbers;
}

BigInteger& BigInteger::operator=(const BigInteger&) {
	return *this;
}

bool BigInteger::operator==(BigInteger& op2) {
	List* listN1 = numbers;
	List* listN2 = op2.getNumber();
	if (listN1->getSize() != listN2->getSize()) {
		return false;
	}
	Node* h1 = listN1->getHead()->next;
	Node* h2 = listN2->getHead()->next;
	while (h1 && h2)
	{
		if (h1->data != h2->data) {
			return false;
		}
	}
	return true;
}
bool BigInteger::operator!=(BigInteger& op2) {
	return !(*this == op2);
}
bool BigInteger::operator>(BigInteger& op2) {
	if (this->numbers->getSize() > op2.getNumber()->getSize()) {
		return true;
	}

}
bool BigInteger::operator >= (BigInteger& op2) {
	return true;
}
bool BigInteger::operator < (BigInteger& op2) {
	return true;
}
bool BigInteger::operator <= (BigInteger& op2) {
	return true;
}

// 加法
BigInteger BigInteger::operator+(BigInteger& op2) {
	BigInteger b1;
	List* ans = b1.getNumber();
	Node* num1 = this->getNumber()->getHead()->next;
	Node* num2 = op2.getNumber()->getHead()->next;
	int up = 0;
	while (num1 && num2) {
		int value = num1->data + num2->data + up;
		up = value / 10;
		value %= 10;
		ans->push_back(value);
		num1 = num1->next;
		num2 = num2->next;
	}
	while (num1 != nullptr) {
		int value = num1->data + up;
		up = value / 10;
		value %= 10;
		ans->push_back(value);
		num1 = num1->next;
	}
	while (num2 != nullptr) {
		int value = num2->data + up;
		up = value / 10;
		value %= 10;
		ans->push_back(value);
		num2 = num2->next;
	}
	printList(ans);
	return b1;
}
// 减法
BigInteger BigInteger::operator-(BigInteger& op2) {
	BigInteger b1;
	return b1;
}
// 乘法
BigInteger BigInteger::operator*(BigInteger& op2) {
	BigInteger b1;
	return b1;
}
// 指数
BigInteger BigInteger::power(int n) {
	BigInteger b1;
	return b1;
}

List* BigInteger::getNumber() {
	return numbers;
}
// 将链表转为字符串
std::string BigInteger::transfer(BigInteger) {
	return "";
}
// 反转链表
List* BigInteger::reverseList() {
	return numbers;
}

int BigInteger::getSign() {
	return sign;
}

BigInteger::~BigInteger() {
	delete numbers;
}