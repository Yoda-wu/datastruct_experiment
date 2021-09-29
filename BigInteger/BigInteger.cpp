#include "BigInteger.h"
#include<iostream>

// 直接输出链表
void BigInteger::printList() {
	
	Node* p = numbers->getHead()->next;
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
	if (bigNum == 0) numbers->push_back(bigNum);
	while (bigNum) {
		int val = bigNum % 10;
		numbers->push_back(val);
		bigNum /= 10;
	}
}

BigInteger::BigInteger(const BigInteger& bigNum) {
	init();
	this->sign = bigNum.sign;
	Node* p = bigNum.numbers->getHead()->next;
	for (int i = 0; i < bigNum.numbers->getSize(); i++) {
		int v = p->data;
		numbers->push_back(v);
		p = p->next;
	}
}

BigInteger& BigInteger::operator=(const BigInteger& bigNum) {
	init();
	this->sign = bigNum.sign;
	Node* p = bigNum.numbers->getHead()->next;
	for (int i = 0; i < bigNum.numbers->getSize(); i++) {
		int v = p->data;
		numbers->push_back(v);
		p = p->next;
	}
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
	else if (this->numbers->getSize() < op2.getNumber()->getSize()) {
		return false;
	}
	else {

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
	//std::cout << "Adding...." << std::endl;
	BigInteger b1;
	List* ans = b1.getNumber();

	if (sign == POSITIVE && op2.sign == NEGATIVE) {
		op2.sign = NEGATOPOS;
		return (*this - op2);
	}
	else if (sign == NEGATIVE && op2.sign == POSITIVE) {
		this->sign = POSTONEGA;
		return (op2 - *this);
	}
	else if (sign == NEGATIVE && op2.sign == NEGATIVE) {
		b1.sign = NEGATIVE;
	}

	Node* opn1 = (*this >= op2) ? this->getNumber()->getHead()->next : op2.getNumber()->getHead()->next;
	Node* opn2 = (*this < op2) ? this->getNumber()->getHead()->next : op2.getNumber()->getHead()->next;

	Node* num1 = opn1;
	Node* num2= opn2;
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
	b1.sign = POSITIVE;
	//printList(ans);
	//std::cout << "Added" << std::endl;
	return b1;
}
// 减法
BigInteger BigInteger::operator-(BigInteger& op2) {
	BigInteger b1;
	// 答案
	List* ans = b1.getNumber();
	
	// TODO： 判断被减数和减数

	// 被减数
	Node* num1 = this->getNumber()->getHead()->next;
	// 减数
	Node* num2 = op2.getNumber()->getHead()->next;
	int up = 0;
	while (num1 && num2) {
		int value = num1->data - num2->data - up;
		up = 0;
		if (value < 0) {
			up = 1;
			value += 10;
		}
		ans->push_back(value);
		num1 = num1->next;
		num2 = num2->next;
	}
	while (num1 != nullptr) {
		int value = num1->data - up;
		up = 0;
		if (value < 0) {
			up = 1;
			value += 10;
		}
		if (value != 0) {
			ans->push_back(value);
		}
		num1 = num1->next;
	}
	int last = ans->getLast();
	if (last == 0) {
		Node* nonZero = nullptr;
		Node* tra = ans->getHead()->next;
		while (tra != nullptr) {
			if (tra->data != 0) {
				nonZero = tra;
			}
			tra = tra->next;
		}
		while (nonZero->next != nullptr) {
			ans->pop_back();
			//nonZero = nonZero->next;
		}

	}
	//printList(ans);
	return b1;
}
// 乘法
BigInteger BigInteger::operator*(BigInteger& op2) {
	BigInteger b1;
	// TODO： 判断被减数和减数

	// 被乘数
	Node* num1 = this->getNumber()->getHead()->next;
	// 乘数
	Node* num2 = op2.getNumber()->getHead()->next;
	int i = 0;
	while (num2 != nullptr) {
		BigInteger temp;
		List* tempAns = temp.getNumber();
		for (int j = 0; j < i; j++) {
			tempAns->push_back(0);
		}
		int up = 0;
		num1 = this->getNumber()->getHead()->next;
		while (num1 != nullptr) {
			int value = num1->data * num2->data + up;
			up = value / 10;
			value %= 10;
			tempAns->push_back(value);
			num1 = num1->next;
		}
		if (up != 0) {
			tempAns->push_back(up);
		}
		i++;
		b1 = b1 + temp;

		num2 = num2->next;
	}
	//printList(b1.getNumber());
	return b1;
}
// 指数
BigInteger BigInteger::power(int n) {
	if (n == 1) return *this;
	else if (n == 0) return BigInteger("+0");
	BigInteger b1(*this);
	BigInteger temp = b1;
	for (int i = 1; i < n; i++) {
		b1 = b1 * temp;
	}
	return b1;
}

List* BigInteger::getNumber() {
	return numbers;
}
// 将链表转为字符串


int BigInteger::getSign() {
	return sign;
}

BigInteger::~BigInteger() {
	//std::cout << "deleting List* numbers" << std::endl;

}