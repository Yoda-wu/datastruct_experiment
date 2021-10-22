#include"CityDataBase.h"
#include<iomanip>
#include<time.h>
void window() {
	std::cout << "		    	1.�鿴���г���  			" << std::endl;
	std::cout << "		    	2.��������  			" << std::endl;
	std::cout << "		    	3.�޸ĳ���  			" << std::endl;
	std::cout << "		    	4.��ӳ���  			" << std::endl;
	std::cout << "		    	5.ɾ������  			" << std::endl;
	std::cout << "		    	6.��Ӵ�����  			" << std::endl;
	std::cout << "		    	7.��ѯ�������ݵ�Ч��  			" << std::endl;
	std::cout << "		    	8.��ӡ����ָ�������������һ����Χ�ڵ����м�¼  			" << std::endl;
	std::cout << "		    	9.�˳�       			" << std::endl;
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
				std::cout << "ɾ����ʱ�� " << (clock() - start) << "ms" << std::endl;
				
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
			std::cout << "����"<<N<<"�����ݺ�ʱ�� " << (clock() - start) << "ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('7'): {
			system("CLS");
			clock_t start = clock();
			dataBase.getALL();
			std::cout << "��ѯ"<<N<<"�����ݺ�ʱ�� " << (clock() - start) << "ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('8'): {
			system("CLS");
			system("CLS");
			std::cout << "��������е�����: ";
			std::string name;
			std::cin >> name;
			std::cout << "��������е�����: " << std::endl;
			int x, y, d;
			std::cout << " x����Ϊ: ";
			std::cin >> x;
			std::cout << " y����Ϊ: ";
			std::cin >> y;
			std::cout << "���룺 ";
			std::cin >> d;
			clock_t start = clock();
			dataBase.printRecord(x,y,d);
			std::cout << "��ʱ�� " << (clock() - start) << "ms" << std::endl;
			system("pause");
			system("CLS");
			break;
		}
		case('9'): {
			exit(0);
			break;
		}
		default:
			std::cout << "����ѡ��" << std::endl;
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