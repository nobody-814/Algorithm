#include<iostream>
using namespace std;
#include<vector>
#include<queue>
int n;
vector<vector<char>>mp;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>>vis;
int total_island;
int submerge_island;

//首先得判断他是不是一个单独的岛，然后判断这个岛是否会被淹没


void init() {
	cin >> n;
	mp.resize(n, vector<char>(n));
	vis.resize(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}

}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mp[i][j] == '#'&&!vis[i][j]) {
				total_island++;
				queue<pair<int, int>>q;
				vector<pair<int, int>>island;
				island.clear();
				q.push({ i,j });
				vis[i][j] = 1;
				island.push_back({ i,j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (mp[nx][ny] == '#' && !vis[nx][ny]) {
							q.push({ nx,ny });
							vis[nx][ny] = 1;
							island.push_back({ nx,ny });
						}
					}
				}
				//每次统计完一个岛屿，判断它是否会被淹没，遍历island，判断有没有一个点四周都是#
				bool is_submerged = true;
				for (auto it : island) {
					bool flag = false;//假设当前陆地周围没有海洋
					int x = it.first;
					int y = it.second;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (mp[nx][ny] == '.') {
							flag = true;//有海洋
							break;
						}
					}
					if (flag == false) {//当前陆地四周全是陆地，该岛不可能被淹没
						is_submerged = false;
						break;
					}

				
				}
				if (is_submerged == true) {//到这来就说明没有一块陆地周围全是陆地，这个岛屿就会被淹没
					submerge_island++;
				}



			}
		}
	}



	cout << submerge_island << endl;



}

int main() {
	init();
	solution();




	return 0;
}