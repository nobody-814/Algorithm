#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<cstring>
//本题要求两个城市的最大花费，就是求树的直径
//树的直径：一个任意一个点，距离它最远的一个点一定是直径的一个点，
// 再从该点出发，距离它最远的点就是直径的另一个点，他们的距离就是解
const int inf = 1e5 + 5;
int vis[inf];
long long dist[inf];
vector<vector<pair<int,int>>>graph(inf);
int n;
int bfs(int start) {
	memset(vis, 0, sizeof(vis));
	memset(dist, 0, sizeof(dist));
	queue<int>q;
	q.push(start);
	vis[start] = 1;
	dist[start] = 0;

	int farestV = start;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto& u : graph[v]) {
			if (vis[u.first]==0) {
				vis[u.first] = 1;
				dist[u.first] = dist[v] + u.second;
				q.push(u.first);
			}
			if (dist[u.first] > dist[farestV])farestV = u.first;
		}
	}
	return farestV;
	
}


int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y, val;
		cin >> x >> y >> val;
		graph[x].push_back({ y,val });
		graph[y].push_back({ x,val });
	}
	int farestV = bfs(1);
	int secondV = bfs(farestV);

	long long cost = dist[secondV] * (dist[secondV] + 21) / 2;

	cout << cost << endl;
	return 0;



	return 0;
}