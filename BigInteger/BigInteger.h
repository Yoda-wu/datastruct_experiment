#pragma once
#include "List.h"
#include <string>

#define  ZERO  48
#define  POSITIVE  0
#define  NEGATIVE  1
#define  NEGATOPOS 2
#define  POSTONEGA 3


class BigInteger
{
private:
	List* numbers;
	int sign;
	void init() {
		sign = POSITIVE;
		numbers = new List;
	}
public:
	// 无参构造函数
	BigInteger();

	// 有参构造函数
	BigInteger(std::string);
	BigInteger(long);

	// 拷贝构造函数
	BigInteger(const BigInteger&);
	// 赋值操作
	BigInteger& operator=(const BigInteger&);

	// 析构函数
	~BigInteger();
	/***************比较操作符重载********************/
	bool operator==(BigInteger& op2);
	bool operator!=(BigInteger& op2);
	bool operator>(BigInteger& op2);
	bool operator >= (BigInteger& op2);
	bool operator < (BigInteger& op2);
	bool operator <= (BigInteger& op2);

	/****************算数运算符重载******************/
	// 加法
	BigInteger operator+(BigInteger& op2);
	// 减法
	BigInteger operator-(BigInteger& op2);
	// 乘法
	BigInteger operator*(BigInteger& op2);
	// 指数
	BigInteger power(int n);

	/******************基础函数接口******************/
	// 获取number链表
	List* getNumber();
	// 直接输出链表
	void printList();
	// 反转链表
	//List reverseList();

	int getSign();
};

