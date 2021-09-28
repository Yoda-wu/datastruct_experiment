#include"List.h"

/*
* �޲ι��캯��
*/
List::List() {
	init();
}

/*
* �������캯����ͨ�����������ʵ��
* @params rhs �����Ӧ��
* @return List& ���ؿ�������������
*/
List& List::operator=(const List& rhs) {
	List copy = rhs;
	std::swap(*this, copy);
	return *this;
}

/*
* ����������
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
* �������β������һ���µĽ��
* @params val ����ֵ
* @return void
*/
void List:: push_back(int val) {
	Node* p = head;
	// ���������һ����㴦
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = new Node(val, nullptr);
	size++;
}

/*
* ���������һ����㵯��
* @params null
* @return void
*/
void List::pop_back() {
	Node* p = head;
	// �������Ϊ�� �򲻲���
	if (isEmpty()) {
		return;
	}
	// �ҵ������ڶ������
	while (p->next->next != nullptr) {
		p = p->next;
	}
	// Ҫɾ���Ľ��
	Node* del = p->next;
	// ɾ�������� �������ڶ���������һ���������
	p->next = nullptr;
	size--;
	delete del;
}

/*
* ������ͷ��������
* @params val	���ֵ
* @return void
*/
void List::push_front(int val) {
	Node* p = head;
	// �������Ϊ��
	if (!isEmpty()) {
		// ȡ����һ����ֵ�Ľ��
		Node* temp = p->next;
		// ��head->next = �µĽ�㣬�����µĽ�����һ�����Ϊtemp
		p->next = new Node(val, temp);
	}
	else { // �������Ϊ��
		// ֱ�Ӳ�����
		p->next = new Node(val, nullptr);
	}
	size++;
}

/*
* ������ĵ�һ����㵯��
* @params null
* @return void
*/
void List::pop_front() {
	Node* p = head;
	// �������Ϊ��
	if (size > 0) {
		// ��ԭ���ڶ��������Ϊ��һ����㡣ɾȥԭ����һ�����
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
* ��ȡ����Ĵ�С��Ԫ�ظ�����
* @params null
* @return int ����Ĵ�С
*/
int List::getSize() {
	return size;
}
/*
* ��ȡ�����ͷ��ָ��
* @params null
* @return Node* �����ͷ��ָ��
*/
Node* List::getHead() {
	return head;
}
/*
* �ж������Ƿ�Ϊ��
* @params null
* @return bool �������Ϊ���򷵻�true�����򷵻�false
*/
bool List::isEmpty() {
	return size == 0;
}

/*
* ��������������clear()
*/
List:: ~List() {
	clear();
	delete head;
}