#pragma once
#include "List.h"
#include <string>

constexpr auto ZERO = 48;
constexpr auto POSITIVE = 0;
constexpr auto NEGATIVE = 1;

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
	// ������תΪ�ַ���
	std::string transfer(BigInteger);
	// ��ת����
	List* reverseList();

	int getSign();
};

