#include"CityDataBase.h"
#include<iomanip>
#include<time.h>
void window() {
	std::cout << "		    	1.查看所有城市  			" << std::endl;
	std::cout << "		    	2.检索城市  			" << std::endl;
	std::cout << "		    	3.修改城市  			" << std::endl;
	std::cout << "		    	4.添加城市  			" << std::endl;
	std::cout << "		    	5.删除城市  			" << std::endl;
	std::cout << "		    	6.添加大数据  			" << std::endl;
	std::cout << "		    	7.查询大量数据的效率  			" << std::endl;
	std::cout << "		    	8.打印出与指定点给定距离在一定范围内的所有记录  			" << std::endl;
	std::cout << "		    	9.退出       			" << std::endl;
}

std::string gernerateString(int seed,int len) {
	std::string name;
	
	int i;
	srand(seed);
	for (i = 0; i < len; i++) {
		switch (rand() % 3)
		{
		default: {
			char apend = 'A' + rand() % 26;
			name.append(1, apend);
			break;
		}
		}
		
		
		
		
	}
	return name;
}
int main() {
	
	CityDataBase dataBase;
	int N = 50000;
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
				std::cout << "删除耗时： " << (clock() - start) << "ms" << std::endl;
				
			}
			system("pause");
			system("CLS");
			break;
		}
		case('6'): {
			system("CLS");
			
			clock_t start = clock();
			srand(time(NULL));
			for (int i = 0; i < N; i++) {
				std::string name = gernerateString(i,8);
				//std::cout << name << "  ";
				City city(name);
				dataBase.insert(city);
			}
			std::cout << std::endl;
			std::cout << "插入"<<N<<"条数据耗时： " << (clock() - start) << "ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('7'): {
			system("CLS");
			clock_t start = clock();
			dataBase.getALL();
			std::cout << "查询"<<N<<"条数据耗时： " << (clock() - start) << "ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('8'): {
			system("CLS");
			system("CLS");
			std::cout << "请输入城市的名称: ";
			std::string name;
			std::cin >> name;
			std::cout << "请输入城市的坐标: " << std::endl;
			int x, y, d;
			std::cout << " x坐标为: ";
			std::cin >> x;
			std::cout << " y坐标为: ";
			std::cin >> y;
			std::cout << "距离： ";
			std::cin >> d;
			clock_t start = clock();
			dataBase.printRecord(x,y,d);
			std::cout << "耗时： " << (clock() - start) << "ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('9'): {
			exit(0);
			break;
		}
		default:
			std::cout << "错误选择" << std::endl;
			break;
		}
	}
	



	return 0;
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