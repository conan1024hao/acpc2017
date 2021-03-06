#include <bits/stdc++.h>

using namespace std;

#define int long long

using Pi = pair<int, int>;
using vint = vector<int>;
using Graph = vector<vint>;

int N, M, Q;
vint w;

Graph graph;

int solve(int y, int x) {
  queue<int> que;
  que.push(y);
  vint used(N, 0);
  used[x] = 1;
  used[y] = 1;
  int ans = w[y];
  while(!que.empty()) {
    int u = que.front(); que.pop();
    for(int& v : graph[u]) {
      if(!used[v]) {
	que.push(v);
	used[v] = 1;
	ans += w[v];
      }
    }
  }
  return ans;
}

signed main() {
  cin >> N >> M;
  w.resize(N);
  graph.resize(N);
  int all = 0;
  for(int i = 0; i < N; i++) {
    cin >> w[i];
    all += w[i];
  }
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v; --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int i = 0; i < N; i++) {
    int ans = 0;
    for(int& v : graph[i]) {
      ans = max(ans, solve(v, i));
    }
    cout << ans << endl;
  }

  return 0;
}
