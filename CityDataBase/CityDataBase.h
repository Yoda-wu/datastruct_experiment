#pragma once
#include<string>
#include<iostream>
#include"BST.h"
struct City {
	std::string name;
	int x;
	int y;
	City(): x(-1), y(-1) {};
	City(std::string city) :name(city), x(-1),y(-1) {}
	City(std::string city, int x, int y) {
		this->name = city;
		this->x = x;
		this->y = y;
	}

	bool operator==(City city) {
		return this->name == city.name;
	}
	bool operator >(City city) {
		//std::cout<<"   In city " << this->name << " > " << city.name << " " << (this->name > city.name) << std::endl;

		return this->name > city.name;
	}
	bool operator < (City city) {
		return !(*this > city);
	}
	bool operator != (City city) {
		return !(*this == city);
	}
	bool operator <= (City city) {
		return (*this < city) || (*this == city);
	}
	bool operator >= (City city) {
		return (*this > city) || (*this == city);
	}
};



class CityDataBase
{
private:
	BST<City> bstTree;

	bool isNearBy(City city, int x, int y, double distance) {
		int cityX = city.x;
		int cityY = city.y;
		double dis = sqrt((cityX - x) * (cityX - x) + (cityY - y) * (cityY - y));
		if ((dis - distance) < 0.01) {
			return true;
		}
		return false;
	}
public:
	
	CityDataBase():bstTree(){}
	CityDataBase(City city) {
		bstTree =  BST<City>(city);
	}

	int getSize() {
		return bstTree.getSize();
	}
	// 添加城市记录
	void insert(City city) {
		//std::cout << "INSERT " << city.name << " INTO DATABASE" << std::endl;
		if (bstTree.add(city) < 0) {
			//std::cout << "该城市已存在" << std::endl;
		}
		//std::cout << "成功添加" << std::endl;
	}
	// 删除城市
	void deleteCity(std::string name) {
		City city(name);
		bstTree.remove(city);
		
	}
	// 索引城市
	City getCity(std::string name) {
		City city(name);
		return bstTree.findValue(city);
	}
	// 更改城市坐标
	void updateCity(City city) {
		if (bstTree.update(city) < 0) {
			std::cout << "未查询到相应的数据" << std::endl;
		}
		else {
			std::cout << "成功修改" << std::endl;

		}

	}
	// 打印出与指定点给定距离的所有城市
	void printRecord(int x, int y, double distance) {
		/*std::vector<Node<City>* > cityList= bstTree.traverseTree();
		std::cout << "在目标点 ： " << "( " << x << " , " << y << " ) " << distance << " 范围内的城市有：" << std::endl;
		for (auto node : cityList) {
			City city = node->value;
			if (isNearBy(city,x,y, distance) ){
				std::cout << city.name << " ( " << city.x << " , " << city.y << " ) " << std::endl;
			}
		}*/
		bstTree.printNodeInDistance(x, y, distance);
	}

	void printAll() {
		std::vector<Node<City>* > cityList = bstTree.traverseTree();
		if (cityList.size() == 0) {
			std::cout << "目前数据库为空，请添加数据" << std::endl;
			return;
		}
		std::cout << "共有" << bstTree.getSize() << "数据" << std::endl;
		int count = 0;
		for (auto node : cityList) {
			City city = node->value;
			
			std::cout << city.name << " ( " << city.x << " , " << city.y << " ) " << std::endl;
			count++;
			
		}
	}
	void getALL() {
		bstTree.traversePrintTree(false);
		
	}
};

