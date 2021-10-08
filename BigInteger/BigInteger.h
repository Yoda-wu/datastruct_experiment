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
	// �޲ι��캯��
	BigInteger();

	// �вι��캯��
	BigInteger(std::string);
	BigInteger(long);

	// �������캯��
	BigInteger(const BigInteger&);
	// ��ֵ����
	BigInteger& operator=(const BigInteger&);

	// ��������
	~BigInteger();
	/***************�Ƚϲ���������********************/
	bool operator==(BigInteger& op2);
	bool operator!=(BigInteger& op2);
	bool operator>(BigInteger& op2);
	bool operator >= (BigInteger& op2);
	bool operator < (BigInteger& op2);
	bool operator <= (BigInteger& op2);

	/****************�������������******************/
	// �ӷ�
	BigInteger operator+(BigInteger& op2);
	// ����
	BigInteger operator-(BigInteger& op2);
	// �˷�
	BigInteger operator*(BigInteger& op2);
	// ָ��
	BigInteger power(int n);

	/******************���������ӿ�******************/
	// ��ȡnumber����
	List* getNumber();
	// ֱ���������
	void printList();
	// ��ת����
	//List reverseList();

	int getSign();
};

