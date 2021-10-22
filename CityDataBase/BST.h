#pragma once
#include<cmath>
#include<vector>
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
	Node<Object>* addNode(Node<Object>*& node, Object value) {
		//if (node != nullptr) {
		//	//std::cout << "In add function: " << node->value.name << std::endl;
		//}
		
		if (node == nullptr) {
			nodecount++;
			return new Node<Object>(value);
			//if (node == nullptr) {
			////	std::cout << "root null" << std::endl;
			//}
			//else {
			//	std::cout << "In add function Node: " << node->value.name << std::endl;
			//}
		}
		if (value < node->value) {
			node->leftChild = addNode(node->leftChild, value);
		}
		else if (value > node->value) {
			node->rightChild = addNode(node->rightChild, value);
		}

		node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
		int balance = getBalanceFactory(node);
		if (balance > 1 && getBalanceFactory(node->leftChild) > 0) {
			//std::cout << "In add function need right rotate: " << node->value.name << std::endl;
			return rightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) < 0) {
			//std::cout << "In add function need left rotate: " << node->value.name << std::endl;

			return leftRotate(node);
		}
		if (balance > 1 && getBalanceFactory(node->leftChild) < 0) {
			//std::cout << "In add function need leftRight rotate: " << node->value.name << std::endl;
			node->leftChild = leftRotate(node->leftChild);
			return rightRotate(node);
			
			//std::cout << "	" << node->rightChild->value.name << std::endl;
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) > 0) {
			//std::cout << "In add function need rightLeft rotate: " << node->value.name << std::endl;

			node->rightChild = rightRotate(node->rightChild);
			return leftRotate(node);
		}
		return node;
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
				//std::cout <<"In find function "<< temp->value.name << " > " << value.name << " "<< ( temp->value.name > value.name) << std::endl;
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

	Node<Object>* remove(Node<Object>*& node, Object value) {
		Node<Object>* deleteNode = find(value);
		if (deleteNode == nullptr) {
			return nullptr;
		}
		//std::cout << "In remove function Node value = " << deleteNode->value.name << " address = " << (int)deleteNode
		//	<< " left child =  " << (int)deleteNode->leftChild << " right child =  " << (int)deleteNode->rightChild << std::endl;

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
			Node<Object>* mini = findMin(deleteNode->rightChild);
			Object tempValue = deleteNode->value;
			deleteNode->value = mini->value;
			mini->value = tempValue;
			//std::cout << "In remove function update : " << deleteNode->value.name <<" "<<(int)deleteNode->rightChild << std::endl;
			deleteNode->rightChild =  remove(mini, tempValue);
		}
		if (deleteNode == nullptr) {
			return node;
		}
		//std::cout << "In remove function 2 : " << deleteNode->value.name << std::endl;
		deleteNode->height = std::max(getHeight(node->leftChild), getHeight( node->rightChild) ) + 1;
		int balance = getBalanceFactory(node);
		if (balance > 1 && getBalanceFactory(node->leftChild) > 0) {
			return rightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) < 0) {
			return leftRotate(node);
		}
		if (balance > 1 && getBalanceFactory(node->leftChild) < 0) {
			node->leftChild = leftRotate(node->leftChild);
			return rightRotate(node);
		}
		if (balance < -1 && getBalanceFactory(node->rightChild) > 0) {
			node->rightChild = rightRotate(node->rightChild);
			return leftRotate(node);
		}
		return node;
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
	Node<Object>* rightRotate(Node<Object>*& node) {
		Node<Object>* target = node->leftChild;
		//std::cout << "	In right rotate: " << node->value.name << " " << target->value.name << std::endl;

		Node<Object>* targetRight = target->rightChild;
		target->rightChild = node;
		node->leftChild = targetRight;
		//	std::cout << "	In right rotate: " << node->value.name << " = " << target->rightChild->value.name << std::endl;

		// 更新高度
		node->height = std::max( getHeight(node->leftChild),getHeight( node->rightChild) ) + 1;
		target->height = std::max(getHeight(target->leftChild), getHeight( target->rightChild )) + 1;
		return target;
	}

	/*
	* 左旋 对应 右右情况
	*/
	Node<Object>* leftRotate(Node<Object>*& node) {
		Node<Object>* target = node->rightChild;
		//std::cout << "	In left rotate: " <<node->value.name<<" "<< target->value.name << (int)target<< std::endl;
		Node<Object>* targetLeft = target->leftChild;
		target->leftChild = node;
		node->rightChild = targetLeft;
		//std::cout << "	In left rotate: " << node->value.name << " = " << target->leftChild->value.name<<(int)target->leftChild << "  "<<(int)node<< std::endl;

		// 更新高度
		node->height = std::max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
		target->height = std::max(getHeight(target->leftChild),getHeight( target->rightChild) ) + 1;
		return target;
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
		root = addNode(root, value);
		return 1;
	}
	/**
	* 查询结点值
	*/
	Object findValue(Object value) {
		Node<Object>* temp = root;
		
		while (temp != nullptr) {
			//std::cout << temp->value.name << " ";
			if (temp->value == value) {
				std::cout << (int)temp->rightChild<<" "<< (int)temp->leftChild << " ";
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
			//std::cout << "OUT" << std::endl;
		}
		std::cout << std::endl;
		return Object();
	}

	/**
	* 删除结点
	*/
	void remove(Object value) {
		Node<Object>* node = find(value);
		if (node != nullptr) {
			root = remove(root, value);	
			//std::cout <<"In remove"<< (int)root << std::endl;

			return;
		}
		else {
			std::cout << "数据库中无该城市" << std::endl;
		}
		
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

	/**
	* 遍历返回结点
	*/
	std::vector<Node<Object>*> traverseTree() {
		Node<Object>* temp = root;
		std::vector<Node<Object>*> list;
		if (temp == nullptr) {
			return  list;
		}
		std::vector< Node<Object>* > stack;
		
		stack.push_back(temp);
		while (!stack.empty()) {
			Node<Object>* p = stack.back();
			stack.pop_back();
			list.push_back(p);
			if (p->leftChild != nullptr) {
				stack.push_back(p->leftChild);
				
			}
			if (p->rightChild != nullptr) {
				stack.push_back(p->rightChild);
				
			}
		}
		return list;
	}

	void traversePrintTree(bool isPrint) {
		Node<Object>* temp = root;
		if (temp == nullptr) {
			return;
		}
		std::vector< Node<Object>* > stack;

		stack.push_back(temp);
		while (!stack.empty()) {
			Node<Object>* p = stack.back();
			stack.pop_back();
			if (isPrint) {
				std::cout << " Node value = " << p->value.name << " address = " << (int)p
					<< " left child =  " << (int)p->leftChild << " right child =  " << (int)p->rightChild << std::endl;
			}
			if (p->leftChild != nullptr) {
				stack.push_back(p->leftChild);

			}
			if (p->rightChild != nullptr) {
				stack.push_back(p->rightChild);

			}
		}

	}
	bool isNearBy(Object city, int x, int y, double distance) {
		int cityX = city.x;
		int cityY = city.y;
		double dis = sqrt((cityX - x) * (cityX - x) + (cityY - y) * (cityY - y));
		if ((dis - distance) < 0.01) {
			return true;
		}
		return false;
	}
	void printNodeInDistance(int x, int y, int distance) {
		Node<Object>* temp = root;
		if (temp == nullptr) {
			return;
		}
		std::vector< Node<Object>* > stack;
		std::cout << "在目标点 ： " << "( " << x << " , " << y << " ) " << distance << " 范围内的城市有：" << std::endl;
		stack.push_back(temp);
		while (!stack.empty()) {
			Node<Object>* p = stack.back();
			stack.pop_back();
			if (isNearBy(p->value, x, y, distance) ){
				std::cout << p->value.name << " ( " << p->value.x << " , " << p->value.y << " ) " << std::endl;
			}
			if (p->leftChild != nullptr) {
				stack.push_back(p->leftChild);

			}
			if (p->rightChild != nullptr) {
				stack.push_back(p->rightChild);

			}
		}
	}
};

