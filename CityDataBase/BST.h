#pragma once
#include<cmath>
#include<iostream>
template<typename Object>
struct Node
{
	// ���ֵ
	Object value;
	// �߶�
	int height ;
	// ������
	Node* leftChild;
	// ������
	Node* rightChild;
	Node():leftChild(nullptr),rightChild(nullptr),height(0){}
	Node(Object v):value(v),leftChild(nullptr),rightChild(nullptr),height(1){}
	Node(Object v, Node* lc, Node* rc):value(v),leftChild(lc),rightChild(rc),height(1){}

};
template<typename Object>
class BST
{
private:
	// �����
	Node<Object>* root;
	// �����
	int nodecount;
	
	/**
	* ��ȡĳ������ƽ������
	* 
	* @param node ���
	* @return �ý���ƽ������
	*/
	int getBalanceFactory(Node<Object>* node) {
		if (node != nullptr) {
			return getHeight(node->leftChild) - getHeight(node->rightChild);
		}
		return 0;
	}

	/**
	* �ж�ĳ������Ƿ�ƽ��
	* 
	* @param node ���
	* @return �Ƿ�ƽ��
	*/
	bool isBalance(Node<Object>* node) {
		if (node == nullptr) {
			return true;
		}
		int balance = fabs( getBalanceFactory(node));
		if (balance > 1) {
			return false;
		}
		return isBalance(node->leftChild) && isBalance(node->rightChild);
	}

	/**
	* ������ֵ
	*/
	void addNode(Node<Object>*& node, Object value) {
		if (node == nullptr) {
			nodecount++;
			node = new Node<Object>(value);
			if (root == nullptr) {
				std::cout << "root null" << std::endl;
			}
			return;
		}
		if (value < node->value) {
			addNode(node->leftChild, value);
		}
		else if (value > node->value) {
			addNode(node->rightChild, value);
		}

		node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
		int balance = getBalanceFactory(node);
		if (balance > 1 && getBalanceFactory(node->leftChild) > 0) {
			rightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) < 0) {
			leftRotate(node);
		}
		if (balance > 1 && getBalanceFactory(node->leftChild) < 0) {
			leftRightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) > 0) {
			rightLeftRotate(node);
		}
	}

	/**
	* �������
	*/
	Node<Object>* find(Object value) {
		Node<Object>* temp = root;
		while (temp != nullptr) {
			if (temp->value == value) {
				return temp;
			}
			else if (temp->value > value) {
				temp = temp->leftChild;
			}
			else {
				temp = temp->rightChild;
			}
		}
		return temp;
	}

	/**
	* ������С���
	*/
	Node<Object>* findMin(Node<Object>*& node) {
		Node<Object>* temp = node;
		while (temp->leftChild != nullptr) {
			temp = temp->leftChild;
		}
		return temp;
	}

	void remove(Node<Object>*& node, Object value) {
		Node<Object>* deleteNode = find(value);
		std::cout << root->value.name << std::endl;
		if (deleteNode == nullptr) {
			return;
		}
		// ��ɾ���Ľ��������Ϊ��
		if (deleteNode->leftChild == nullptr) {
			Node<Object>* temp = deleteNode->rightChild;
			delete deleteNode;
			deleteNode = temp;
			nodecount--;
		}
		else if (deleteNode->rightChild == nullptr) {
			nodecount--;
			Node<Object>* temp = deleteNode->leftChild;
			deleteNode = temp;
		}
		else {
			deleteNode->value = findMin(deleteNode->rightChild)->value;
			remove(deleteNode->rightChild, deleteNode->value);
		}
		if (deleteNode == nullptr) {
			return;
		}
		deleteNode->height = std::max(getHeight(node->leftChild), getHeight( node->rightChild) ) + 1;
		int balance = getBalanceFactory(node);
		if (balance > 1 && getBalanceFactory(node->leftChild) > 0) {
			rightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) < 0) {
			leftRotate(node);
		}
		if (balance > 1 && getBalanceFactory(node->leftChild) < 0) {
			leftRightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) > 0) {
			rightLeftRotate(node);
		}
	}
public:
	BST(Node<Object>* tree):root(tree),nodecount(0){}
	BST() {
		root = nullptr;
		nodecount = 0;
	}
	BST(Object obj) {
		nodecount = 0;
		root = new Node<Object>(obj);
	}
	~BST() {

	}

	Node<Object>* getRoot() {
		return this->root;
	}
	/**
	* ��ȡĳ�����ĸ߶�
	* 
	* @param node BST��ĳ�����
	* @return  int �ýڵ�ĸ߶�
	*/
	int getHeight(Node<Object>* node) {
		if (node != nullptr) {
			return node->height;
		}
		return 0;
	}

	/**
	* �ж�ĳ������Ƿ�ΪҶ�ӽ��
	* 
	* @param node BST��ĳ�����
	* @return bool �Ƿ�ΪҶ�ӽ��
	*/
	bool isLeaf(Node<Object>* node){
		return node->leftChild == nullptr && node->rightChild == nullptr;
	}

	/**
	* ��ȡBST�Ľ����
	* 
	* @return BST�Ľ����
	*/
	int getSize() {
		return nodecount;
	}

	/**
	* �ж����Ƿ���ƽ���
	* 
	*/
	bool isBalance() {
		return isBalance(root);
	}


	/**
	* ����ת ��Ӧ �������
	*/
	void rightRotate(Node<Object>*& node) {
		Node<Object>* target = node->leftChild;
		Node<Object>* targetRight = target->rightChild;
		target->rightChild = node;
		node->leftChild = targetRight;
		// ���¸߶�
		node->height = std::max(node->leftChild->height, node->rightChild->height) + 1;
		target->height = std::max(target->leftChild->height, target->rightChild->height) + 1;
	}

	/*
	* ���� ��Ӧ �������
	*/
	void leftRotate(Node<Object>*& node) {
		Node<Object>* target = node->rightChild;
		Node<Object>* targetLeft = target->leftChild;
		target->leftChild = node;
		node->rightChild = targetLeft;
		// ���¸߶�
		node->height = std::max(node->leftChild->height, node->rightChild->height) + 1;
		target->height = std::max(target->leftChild->height, target->rightChild->height) + 1;
	}

	/*
	* ������ ��Ӧ ��������Ҳ���
	*/
	void leftRightRotate(Node<Object>*& node) {
		leftRotate(node->leftChild);
		rightRotate(node);
	}

	/**
	* ������ ��Ӧ ���Ҷ��������
	*/
	void rightLeftRotate(Node<Object>*& node) {
		rightRotate(node->rightChild);
		leftRotate(node);
	}

	/**
	* ������
	*/
	int add(Object value) {
		Node<Object>* temp = find(value);
		if (temp != nullptr) {
			return -1;
		}
		//std::cout << " Add " << std::endl;
		addNode(root, value);
		return 1;
	}
	/**
	* ��ѯ���ֵ
	*/
	Object findValue(Object value) {
		Node<Object>* temp = root;
		while (temp != nullptr) {
			
			if (temp->value == value) {
				return temp->value;
			}
			else if (temp->value > value) {
				temp = temp->leftChild;
			}
			else {
				temp = temp->rightChild;
			}
		}
		if (root == nullptr) {
			std::cout << "OUT" << std::endl;
		}
		
		return Object();
	}

	/**
	* ɾ�����
	*/
	void remove(Object value) {
		remove(root, value);
	}
	/**
	* ���ĳ�������
	*/
	int update(Object value) {
		Node<Object>* temp = find(value);
		std::cout << (int)temp << std::endl;
		if (temp == nullptr) {
			return -1;
		}
		temp->value = value;
		return 1;
	}

};

