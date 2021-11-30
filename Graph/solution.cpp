#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;

// N个城市
constexpr auto N = 6;
constexpr auto INTEGER_MAX = 0x3f3f3f3f;
// 路程权重邻接矩阵
int  lengthMap[N][N] = {
				{0,1,12,INTEGER_MAX,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX,0,9,3,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 0, INTEGER_MAX,5,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 4, 0,13,15},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0, 4},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0} 
				};
// 时间权重
int  timeMap[N][N] = {
				{0,2,1,INTEGER_MAX,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX,0,3,4,INTEGER_MAX,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 0, INTEGER_MAX,4,INTEGER_MAX},
				{INTEGER_MAX, INTEGER_MAX, 2, 0,5,7},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0, 4},
				{INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, INTEGER_MAX, 0}
};
// 是否访问这个点
bool isvisted[N];
// 每个结点的最短长度
int len[N];
int pre[N];

/**
* 初始权重矩阵
*/
void initMap() {

	for (int i = 0; i < N; i++) {
		/*for (int j = i; j < N; j++) {
			int weight = 0;
			cout << i << "城市和" << j << "城市的权重是: ";
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
* Dijkstra算法
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
* 打印权重矩阵
*/
void printMap(int map[N][N]) {

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{

			if (map[i][j] == INTEGER_MAX) {
				cout << setw(5) << "∞";
			}
			else {
				cout << setw(5) << map[i][j];
			}
			
		}
		cout << endl;
	}

}
/*
* 打印路径
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
	cout << "路程矩阵： " << endl;
	printMap(lengthMap);
	cout << "时间矩阵： " << endl;
	printMap(timeMap);
	initMap();
	int start;
	int end;
	cout << "输入两个城市的代码(1-6): " << endl;
	cout << "起始点: ";
	cin >> start;
	start--;
	cout << "终止点: ";
	cin >> end;
	end--;
	cout << "推荐的最短里程路径:" << endl;
	Dijkstra(lengthMap, end,start,end);
	printPath();
	initMap();
	cout << "最短用时路径:" << endl;
	Dijkstra(timeMap, end, start, end);
	printPath();
	cout << "输入中间城市的代码(1-6)： " << endl;
	int mid;
	cin >> mid;
	mid--;
	initMap();
	cout << "推荐的最短里程路径:" << endl;
	target(lengthMap,mid,start,end);
	initMap();
	cout << "最短用时路径:" << endl;
	target(timeMap, end, start, end);
	
}