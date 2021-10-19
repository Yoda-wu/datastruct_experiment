#include"CityDataBase.h"


int main() {
	City city("ShenZhen", 1, 1);
	CityDataBase dataBase;
	dataBase.insert(city);
	City city2("BeiJing", 2, 2);
	dataBase.insert(city2);
	city2.x = 3;
	std::cout << dataBase.getCity("BeiJing").name << std::endl;
	dataBase.updateCity(city2);
	std::cout << dataBase.getSize() << std::endl;
	dataBase.deleteCity("BeiJing");
	std::cout << dataBase.getSize() << std::endl;
	//std::cout << dataBase.getCity("ShenZhen").name << std::endl;
	std::cout << dataBase.getCity("BeiJing").name << std::endl;
	return 0;
}
