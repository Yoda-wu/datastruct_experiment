#include"List.h"

/*
* 无参构造函数
*/
List::List() {
	init();
}

/*
* 拷贝构造函数，通过重载运算符实现
* @params rhs 链表的应用
* @return List& 返回拷贝构造后的链表
*/
List& List::operator=(const List& rhs) {
	List copy = rhs;
	std::swap(*this, copy);
	return *this;
}

/*
* 将链表清零
* @params null
* @return void
*/
void List::clear() {
	Node* p = head;
	while (p != nullptr) {
		Node* del = p;
		p = p->next;
		delete del;
	}
	size = 0;
}

/*
* 从链表的尾部插入一个新的结点
* @params val 结点的值
* @return void
*/
void List:: push_back(int val) {
	Node* p = head;
	// 遍历到最后一个结点处
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = new Node(val, nullptr);
	size++;
}

/*
* 将链表最后一个结点弹出
* @params null
* @return void
*/
void List::pop_back() {
	Node* p = head;
	// 如果链表为空 则不操作
	if (isEmpty()) {
		return;
	}
	// 找到倒数第二个结点
	while (p->next->next != nullptr) {
		p = p->next;
	}
	// 要删除的结点
	Node* del = p->next;
	// 删除操作： 将倒数第二个结点的下一个结点至空
	p->next = nullptr;
	size--;
	delete del;
}

/*
* 从链表头部插入结点
* @params val	结点值
* @return void
*/
void List::push_front(int val) {
	Node* p = head;
	// 如果链表不为空
	if (!isEmpty()) {
		// 取出第一个有值的结点
		Node* temp = p->next;
		// 令head->next = 新的结点，并且新的结点的下一个结点为temp
		p->next = new Node(val, temp);
	}
	else { // 如果链表为空
		// 直接插入结点
		p->next = new Node(val, nullptr);
	}
	size++;
}

/*
* 将链表的第一个结点弹出
* @params null
* @return void
*/
void List::pop_front() {
	Node* p = head;
	// 如果链表不为空
	if (size > 0) {
		// 把原本第二个结点作为第一个结点。删去原本第一个结点
		Node* temp = p->next;
		p->next = temp->next;
		delete temp;
	}
	else {
		return;
	}
	size--;
}

/*
* 获取链表的大小（元素个数）
* @params null
* @return int 链表的大小
*/
int List::getSize() {
	return size;
}
/*
* 获取链表的头部指针
* @params null
* @return Node* 链表的头部指针
*/
Node* List::getHead() {
	return head;
}
/*
* 判断链表是否为空
* @params null
* @return bool 如果链表为空则返回true，否则返回false
*/
bool List::isEmpty() {
	return size == 0;
}

/*
* 析构函数，调用clear()
*/
List:: ~List() {
	clear();
	delete head;
}