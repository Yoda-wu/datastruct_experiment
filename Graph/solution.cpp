#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;

// N������
constexpr auto N = 6;
constexpr auto INTEGER_MAX = 0x3f3f3f3f;
// ·��Ȩ���ڽӾ���
int  lengthMap[N][N] = {
				{0,1,12,INTEGER_MAX,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX,0,9,3,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 0, INTEGER_MAX,5,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 4, 0,13,15},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0, 4},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0} 
				};
// ʱ��Ȩ��
int  timeMap[N][N] = {
				{0,2,1,INTEGER_MAX,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX,0,3,4,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 0, INTEGER_MAX,4,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 2, 0,5,7},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0, 4},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0}
};
// �Ƿ���������
bool isvisted[N];
// ÿ��������̳���
int len[N];
int pre[N];

/**
* ��ʼȨ�ؾ���
*/
void initMap() {

	for (int i = 0; i < N; i++) {
		/*for (int j = i; j < N; j++) {
			int weight = 0;
			cout << i << "���к�" << j << "���е�Ȩ����: ";
			cin >> weight;
			if (weight == 0) {
				weight = INTEGER_MAX;
			}
			map[i][j] = weight;
			map[j][i] = weight;
		}*/
		len[i] = INTEGER_MAX;
		isvisted[i] = false;
		pre[i] = 0;
	}

}
/*
* Dijkstra�㷨
*/
void Dijkstra(int map[N][N], int midCity,int start=0, int end= N-1) {
	queue<int> que;
	que.push(start);
	isvisted[start] = true;
	if (len[start] == INTEGER_MAX) {
		len[start] = 0;
	}
	
	//cout << start<<" "<<end << endl;
	while (!que.empty()) {
		auto city = que.front();
		int length = len[city];
		que.pop();
		isvisted[city] = true;
		if (city == midCity) {
			return;
		}
		for (int i = start; i < N; i++) {
			if (( map[city][i] < INTEGER_MAX) && !isvisted[i]) {
				//cout << "len = " << len[i] << endl;
				if (len[i] > (map[city][i]+ length) ){
					pre[i] = city+1;
					len[i] = (map[city][i] + length);
					que.push(i);

				}
			}
		}
		
		
	}

}



/*
* ��ӡȨ�ؾ���
*/
void printMap(int map[N][N]) {

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{

			if (map[i][j] == INTEGER_MAX) {
				cout << setw(5) << "��";
			}
			else {
				cout << setw(5) << map[i][j];
			}
			
		}
		cout << endl;
	}

}
/*
* ��ӡ·��
*/
void printPath() {
	cout <<setw(9)<< "city:";
	for (size_t i = 0; i < N; i++)
	{
		cout << setw(2) << i+1 << " ";
	}
	cout << endl;
	cout << "previous:";
	for (size_t i = 0; i < N; i++)
	{
		cout << setw(2) << pre[i] << " ";
	}
	cout << endl;
	cout<< setw(9) << "len:";
	for (size_t i = 0; i < N; i++)
	{
		cout << setw(2) << len[i] << " ";
	}
	cout << endl;
	vector<int> node;
	for (int i = N -1; i >= 0; i = pre[i]-1) {
		node.push_back(i + 1);
	}
	for (int i = 0; i < node.size(); i++) {
		if (i + 1 != node.size()) {
			cout << node[node.size() - i -1] << "->";

		}
		else {
			cout << node[0];
		}

	}
	cout << endl;
}

void target(int map[N][N],  int target,int start,int end) {
	Dijkstra(map, target,start);
	/*printPath();*/
	Dijkstra(map, end, target,end );
	printPath();
}
int main() {
	cout << "·�̾��� " << endl;
	printMap(lengthMap);
	cout << "ʱ����� " << endl;
	printMap(timeMap);
	initMap();
	int start;
	int end;
	cout << "�����������еĴ���(1-6): " << endl;
	cout << "��ʼ��: ";
	cin >> start;
	start--;
	cout << "��ֹ��: ";
	cin >> end;
	end--;
	cout << "�Ƽ���������·��:" << endl;
	Dijkstra(lengthMap, end,start,end);
	printPath();
	initMap();
	cout << "�����ʱ·��:" << endl;
	Dijkstra(timeMap, end, start, end);
	printPath();
	cout << "�����м���еĴ���(1-6)�� " << endl;
	int mid;
	cin >> mid;
	mid--;
	initMap();
	cout << "�Ƽ���������·��:" << endl;
	target(lengthMap,mid,start,end);
	initMap();
	cout << "�����ʱ·��:" << endl;
	target(timeMap, end, start, end);
	
}