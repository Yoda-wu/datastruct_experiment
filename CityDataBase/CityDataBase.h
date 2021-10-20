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
		std::cout<<"   In city " << this->name << " > " << city.name << " " << (this->name > city.name) << std::endl;

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
	// ��ӳ��м�¼
	void insert(City city) {
		std::cout << "INSERT " << city.name << " INTO DATABASE" << std::endl;
		if (bstTree.add(city) < 0) {
			std::cout << "�ó����Ѵ���" << std::endl;
		}
		std::cout << "�ɹ����" << std::endl;
	}
	// ɾ������
	void deleteCity(std::string name) {
		City city(name);
		bstTree.remove(city);
		
	}
	// ��������
	City getCity(std::string name) {
		City city(name);
		return bstTree.findValue(city);
	}
	// ���ĳ�������
	void updateCity(City city) {
		if (bstTree.update(city) < 0) {
			std::cout << "δ��ѯ����Ӧ������" << std::endl;
		}
		else {
			std::cout << "�ɹ��޸�" << std::endl;

		}

	}
	// ��ӡ����ָ���������������г���
	void printRecord(int x, int y, double distance) {
		std::vector<Node<City>* > cityList= bstTree.traverseTree();
		std::cout << "��Ŀ��� �� " << "( " << x << " , " << y << " ) " << distance << " ��Χ�ڵĳ����У�" << std::endl;
		for (auto node : cityList) {
			City city = node->value;
			if (isNearBy(city,x,y, distance) ){
				std::cout << city.name << " ( " << city.x << " , " << city.y << " ) " << std::endl;
			}
		}
	}

	void printAll() {
		std::vector<Node<City>* > cityList = bstTree.traverseTree();
		if (cityList.size() == 0) {
			std::cout << "Ŀǰ���ݿ�Ϊ�գ����������" << std::endl;
		}
		for (auto node : cityList) {
			City city = node->value;
			
			std::cout << city.name << " ( " << city.x << " , " << city.y << " ) " << std::endl;
			
		}
	}

};

