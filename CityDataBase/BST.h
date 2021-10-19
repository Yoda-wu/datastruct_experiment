#pragma once
#include<cmath>
#include<iostream>
template<typename Object>
struct Node
{
	// 结点值
	Object value;
	// 高度
	int height ;
	// 左子树
	Node* leftChild;
	// 右子树
	Node* rightChild;
	Node():leftChild(nullptr),rightChild(nullptr),height(0){}
	Node(Object v):value(v),leftChild(nullptr),rightChild(nullptr),height(1){}
	Node(Object v, Node* lc, Node* rc):value(v),leftChild(lc),rightChild(rc),height(1){}

};
template<typename Object>
class BST
{
private:
	// 根结点
	Node<Object>* root;
	// 结点数
	int nodecount;
	
	/**
	* 获取某个结点的平衡因子
	* 
	* @param node 结点
	* @return 该结点的平衡因子
	*/
	int getBalanceFactory(Node<Object>* node) {
		if (node != nullptr) {
			return getHeight(node->leftChild) - getHeight(node->rightChild);
		}
		return 0;
	}

	/**
	* 判断某个结点是否平衡
	* 
	* @param node 结点
	* @return 是否平衡
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
	* 插入结点值
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
	* 搜索结点
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
	* 搜索最小结点
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
		// 待删除的结点左子树为空
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
	* 获取某个结点的高度
	* 
	* @param node BST的某个结点
	* @return  int 该节点的高度
	*/
	int getHeight(Node<Object>* node) {
		if (node != nullptr) {
			return node->height;
		}
		return 0;
	}

	/**
	* 判断某个结点是否为叶子结点
	* 
	* @param node BST的某个结点
	* @return bool 是否为叶子结点
	*/
	bool isLeaf(Node<Object>* node){
		return node->leftChild == nullptr && node->rightChild == nullptr;
	}

	/**
	* 获取BST的结点数
	* 
	* @return BST的结点数
	*/
	int getSize() {
		return nodecount;
	}

	/**
	* 判断树是否是平衡的
	* 
	*/
	bool isBalance() {
		return isBalance(root);
	}


	/**
	* 右旋转 对应 左左情况
	*/
	void rightRotate(Node<Object>*& node) {
		Node<Object>* target = node->leftChild;
		Node<Object>* targetRight = target->rightChild;
		target->rightChild = node;
		node->leftChild = targetRight;
		// 更新高度
		node->height = std::max(node->leftChild->height, node->rightChild->height) + 1;
		target->height = std::max(target->leftChild->height, target->rightChild->height) + 1;
	}

	/*
	* 左旋 对应 右右情况
	*/
	void leftRotate(Node<Object>*& node) {
		Node<Object>* target = node->rightChild;
		Node<Object>* targetLeft = target->leftChild;
		target->leftChild = node;
		node->rightChild = targetLeft;
		// 更新高度
		node->height = std::max(node->leftChild->height, node->rightChild->height) + 1;
		target->height = std::max(target->leftChild->height, target->rightChild->height) + 1;
	}

	/*
	* 左右旋 对应 对左儿子右插入
	*/
	void leftRightRotate(Node<Object>*& node) {
		leftRotate(node->leftChild);
		rightRotate(node);
	}

	/**
	* 右左旋 对应 对右儿子左插入
	*/
	void rightLeftRotate(Node<Object>*& node) {
		rightRotate(node->rightChild);
		leftRotate(node);
	}

	/**
	* 插入结点
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
	* 查询结点值
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
	* 删除结点
	*/
	void remove(Object value) {
		remove(root, value);
	}
	/**
	* 更改城市坐标
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

