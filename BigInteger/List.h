/*
* @author: wuyuda
* @Date: 2021-9-27 21:06
*/
#pragma once
#include<algorithm>
/*
* 链表结点数据结构
* 存储当前结点的值以及下个结点的指针
*/
struct Node
{
	int data;
	Node* next;
	
	Node() :next(nullptr) {};
	Node(const int& d, Node* n = nullptr) :data(d), next(n) {}

};

/*
* 自定义单向链表（无迭代器）
* 主要功能： 
*			尾插结点，
*			头插结点，
*			判断是否为空
*			获取链表大小
*/
class List {
private:
	// 链表大小
	int size;
	// 链表的头部结点
	Node* head;
	// 初始化函数
	void init() {
		size = 0;
		head = new Node;
	}
public:

	// 无参构造函数
	List();
	// 拷贝构造函数，通过重载运算符实现
	List& operator=(const List& rhs);

	// 析构函数
	~List();

	//  将链表清零
	void clear();

	// 从链表的尾部插入一个新的结点
	void push_back(int val );

	// 将链表最后一个结点弹出
	void pop_back();

	// 从链表头部插入结点
	void push_front(int val);

	// 将链表的第一个结点弹出
	void pop_front();

	// 获取链表的大小（元素个数）
	int getSize();
	// 获取链表的头部指针
	Node* getHead();
	// 判断链表是否为空
	bool isEmpty();
};
