//#include <iostream>
//#include <vector>
//#include <queue>
//#include <unordered_map>
//#include <climits>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//
//    // 预处理每个亮度的所有位置
//    unordered_map<int, vector<int>> pos_map;
//    for (int i = 0; i < n; i++) {
//        pos_map[a[i]].push_back(i);
//    }
//
//    // 预处理每个位置的瞬移目标
//    vector<int> teleport(n, -1);
//    for (auto& pair : pos_map) {
//        vector<int>& pos_list = pair.second;
//        int next = -1;
//        for (int i = pos_list.size() - 1; i >= 0; i--) {
//            teleport[pos_list[i]] = next;
//            next = pos_list[i];
//        }
//    }
//
//    // BFS初始化
//    vector<int> cost(n, INT_MAX);
//    vector<bool> vis(n, false);
//    queue<int> q;
//    q.push(0);
//    cost[0] = 0;
//    vis[0] = true;
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//
//        // 到达终点，直接输出结果
//        if (u == n - 1) {
//            cout << cost[u] << endl;
//            return 0;
//        }
//
//        // 处理左右移动
//        for (int dir : {-1, 1}) {
//            int v = u + dir;
//            if (v >= 0 && v < n && !vis[v]) {
//                cost[v] = cost[u] + 1;
//                vis[v] = true;
//                q.push(v);
//            }
//        }
//
//        // 处理瞬移
//        int v = teleport[u];
//        if (v != -1 && !vis[v]) {
//            cost[v] = cost[u] + 1;
//            vis[v] = true;
//            q.push(v);
//        }
//    }
//
//    // 如果无法到达终点（题目保证有解，这里不会执行）
//    cout << -1 << endl;
//    return 0;
//}