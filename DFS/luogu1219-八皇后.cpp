#include<iostream>
using namespace std;
#include<vector>
int n;
vector<vector<int>>mp;
int total_res;
vector<vector<int>>res;
int row[20];
int col[20];
int x1[100];//左斜对角线
int x2[100];//右斜对角线

void dfs(int x) {
	if (x >= n) {   // 成功放置了n个皇后
		
		vector<int> solution;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mp[i][j] == 1) {
					solution.push_back(j + 1); 
				}
			}
		}
		res.push_back(solution);
		total_res++;
		return;
	}
	
		for (int j = 0; j < n; j++) {
			if (!col[j] && !x1[x + j] && !x2[x- j + n]) {//当前位置可以放置象棋
				col[j] = 1;
				x1[x + j] = 1;
				x2[x - j + n] = 1;
				mp[x][j] = 1;

				dfs(x + 1);
				//回溯
				col[j] = 0;
				x1[x + j] = 0;
				x2[x - j + n] = 0;
				mp[x][j] = 0;
			}
		}
		

	
	
}

int main() {
	cin >> n;
	mp.resize(n, vector<int>(n, 0));
	dfs(0);

	for (int i = 0; i <3; i++) {//只输出前三个解
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << total_res;



	return 0;
}