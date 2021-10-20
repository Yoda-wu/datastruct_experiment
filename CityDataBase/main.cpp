#include"CityDataBase.h"
#include<iomanip>
#include<time.h>
void window() {
	std::cout << "		    	1.查看所有城市  			" << std::endl;
	std::cout << "		    	2.检索城市  			" << std::endl;
	std::cout << "		    	3.修改城市  			" << std::endl;
	std::cout << "		    	4.添加城市  			" << std::endl;
	std::cout << "		    	5.删除城市  			" << std::endl;
	std::cout << "		    	6.退出       			" << std::endl;
}


int main() {
	
	CityDataBase dataBase;
	
	char choose;
	while (true)
	{
		window();
		std::cout << "做出选择: ";
		std::cin >> choose;
		switch (choose)
		{
		case('1'): {
			system("CLS");
			clock_t start = clock();
			dataBase.printAll();
			std::cout << "查询耗时： " << (clock() - start) <<"ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('2'): {
			system("CLS");
			std::cout << "请输入城市的名称: ";
			std::string name;
			std::cin >> name;
			clock_t start = clock();
			City city = dataBase.getCity(name);

			std::cout << "查询耗时： " << (clock() - start) <<"ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('3'): {
			system("CLS");
			std::cout << "请输入要修改城市的名称: ";
			std::string name;
			std::cin >> name;
			std::cout << "请输入修改的城市坐标: ";
			int x, y;
			std::cout << " x坐标为: ";
			std::cin >> x;
			std::cout << " y坐标为: ";
			std::cin >> y;
			City city(name, x, y);
			clock_t start = clock();
			dataBase.updateCity(city);
			std::cout << "修改耗时： " << (clock() - start) << "ms" << std::endl;
			system("pause");
			break;
		}

		case('4'): {
			system("CLS");
			std::cout << "请输入城市的名称: ";
			std::string name;
			std::cin >> name;
			std::cout << "请输入城市的坐标: ";
			int x, y;
			std::cout << " x坐标为: ";
			std::cin >> x;
			std::cout << " y坐标为: ";
			std::cin >> y;

			City city(name, x, y);
			clock_t start = clock();
			dataBase.insert(city);
			std::cout << "插入耗时： " << (clock() - start) <<"ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		
		case('5'): {
			system("CLS");
			std::cout << "请输入城市的名称: ";
			std::string name;
			std::cin >> name;
			std::cout << "请输入城市的名称: 是否确定删除（y / n) ";
			char isDelete;
			std::cin >> isDelete;
			if (isDelete == 'y') {
				clock_t start = clock();
				dataBase.deleteCity(name);
				std::cout << "插入耗时： " << (clock() - start) << "ms" << std::endl;
				
			}
			system("pause");
			system("CLS");
			break;
		}
		case('6'): {
			exit(0);
			break;
		}
		default:
			std::cout << "错误选择" << std::endl;
			break;
		}
	}
	

	//std::cout << dataBase.getCity("ShenZhen").name << std::endl;
	//std::cout << "########################" << std::endl;

	//std::cout << dataBase.getCity("ShangHai").name << std::endl;
	//std::cout << "########################" << std::endl;
	//
	//std::cout << dataBase.getCity("BeiJing").name << std::endl;
	//dataBase.deleteCity("ShangHai");
	/*city.x = 100;
	city.y = 100;
	dataBase.updateCity(city);
	std::cout << "############delete############" << std::endl;
	std::cout << dataBase.getSize() << std::endl;

	std::cout << dataBase.getCity("ShenZhen").x << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << dataBase.getCity("ShangHai").name << std::endl;
	std::cout << "########################" << std::endl;
	std::cout << dataBase.getCity("BeiJing").name << std::endl;*/

	return 0;
}
