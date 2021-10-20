#include"CityDataBase.h"
#include<iomanip>
#include<time.h>
void window() {
	std::cout << "		    	1.�鿴���г���  			" << std::endl;
	std::cout << "		    	2.��������  			" << std::endl;
	std::cout << "		    	3.�޸ĳ���  			" << std::endl;
	std::cout << "		    	4.��ӳ���  			" << std::endl;
	std::cout << "		    	5.ɾ������  			" << std::endl;
	std::cout << "		    	6.�˳�       			" << std::endl;
}


int main() {
	
	CityDataBase dataBase;
	
	char choose;
	while (true)
	{
		window();
		std::cout << "����ѡ��: ";
		std::cin >> choose;
		switch (choose)
		{
		case('1'): {
			system("CLS");
			clock_t start = clock();
			dataBase.printAll();
			std::cout << "��ѯ��ʱ�� " << (clock() - start) <<"ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('2'): {
			system("CLS");
			std::cout << "��������е�����: ";
			std::string name;
			std::cin >> name;
			clock_t start = clock();
			City city = dataBase.getCity(name);

			std::cout << "��ѯ��ʱ�� " << (clock() - start) <<"ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('3'): {
			system("CLS");
			std::cout << "������Ҫ�޸ĳ��е�����: ";
			std::string name;
			std::cin >> name;
			std::cout << "�������޸ĵĳ�������: ";
			int x, y;
			std::cout << " x����Ϊ: ";
			std::cin >> x;
			std::cout << " y����Ϊ: ";
			std::cin >> y;
			City city(name, x, y);
			clock_t start = clock();
			dataBase.updateCity(city);
			std::cout << "�޸ĺ�ʱ�� " << (clock() - start) << "ms" << std::endl;
			system("pause");
			break;
		}

		case('4'): {
			system("CLS");
			std::cout << "��������е�����: ";
			std::string name;
			std::cin >> name;
			std::cout << "��������е�����: ";
			int x, y;
			std::cout << " x����Ϊ: ";
			std::cin >> x;
			std::cout << " y����Ϊ: ";
			std::cin >> y;

			City city(name, x, y);
			clock_t start = clock();
			dataBase.insert(city);
			std::cout << "�����ʱ�� " << (clock() - start) <<"ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		
		case('5'): {
			system("CLS");
			std::cout << "��������е�����: ";
			std::string name;
			std::cin >> name;
			std::cout << "��������е�����: �Ƿ�ȷ��ɾ����y / n) ";
			char isDelete;
			std::cin >> isDelete;
			if (isDelete == 'y') {
				clock_t start = clock();
				dataBase.deleteCity(name);
				std::cout << "�����ʱ�� " << (clock() - start) << "ms" << std::endl;
				
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
			std::cout << "����ѡ��" << std::endl;
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
