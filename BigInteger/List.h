/*
* @author: wuyuda
* @Date: 2021-9-27 21:06
*/
#pragma once
#include<algorithm>
/*
* ���������ݽṹ
* �洢��ǰ����ֵ�Լ��¸�����ָ��
*/
struct Node
{
	int data;
	Node* next;
	
	Node() :next(nullptr) {};
	Node(const int& d, Node* n = nullptr) :data(d), next(n) {}

};

/*
* �Զ��嵥�������޵�������
* ��Ҫ���ܣ� 
*			β���㣬
*			ͷ���㣬
*			�ж��Ƿ�Ϊ��
*			��ȡ�����С
*/
class List {
private:
	// �����С
	int size;
	// �����ͷ�����
	Node* head;
	// ��ʼ������
	void init() {
		size = 0;
		head = new Node;
	}
public:

	// �޲ι��캯��
	List();
	// �������캯����ͨ�����������ʵ��
	List& operator=(const List& rhs);

	// ��������
	~List();

	//  ����������
	void clear();

	// �������β������һ���µĽ��
	void push_back(int val );

	// ���������һ����㵯��
	void pop_back();

	// ������ͷ��������
	void push_front(int val);

	// ������ĵ�һ����㵯��
	void pop_front();

	// ��ȡ����Ĵ�С��Ԫ�ظ�����
	int getSize();
	// ��ȡ�����ͷ��ָ��
	Node* getHead();
	// �ж������Ƿ�Ϊ��
	bool isEmpty();
};
