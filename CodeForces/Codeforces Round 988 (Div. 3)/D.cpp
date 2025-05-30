#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pii pair<int,int>
using namespace std;
const ll INF = 1e17;
const ll maxn = 1e7;

bool cmp(pii a, pii b){
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, m, L; cin >> n >> m >> L;
		vector<pii> pu;
		for (int i = 0; i < n; i++) {
			int l, r; cin >> l >> r;
			pu.push_back({ l,r });
		}

		vector<pii> up;		
		for (int i = 0; i < m; i++) {
			int x, v; cin >> x >> v;
			up.push_back({ x,v });
		}
		int cnt = 0; 
		int jump = 1; 
		bool flag = 1; 

		priority_queue<int> pq;
		int used = 0; 
		for (int i = 0; i < n; i++) {
			int idx = pu[i].first - 1; 
			int len = pu[i].second - pu[i].first + 1;

			if (jump > len) continue;
			while (used < up.size() && up[used].first <= idx)
				pq.push(up[used++].second);
			while (!pq.empty() && jump <= len) {
				int val = pq.top(); pq.pop();
				jump += val;
				cnt++;
			}
			if (jump <= len) { flag = 0; break; }
		}
		if (flag)cout << cnt << endl;
		else cout << -1 << endl;
	}
    return 0;
}
/*
从1到L
x位置有k跳跃能力 >>能跳到在[x, x+k]的位置内任意位置
初始化k = 1
有n个障碍 >> 有n个[l , r]区间 区间内不能跳
有i个增强在xi位置 每个增强有不同值vi 到xi就k += vi
同一位置可能有多个增强 可以拿也可以不拿
保证障碍区间内没有增强
求要到L位置最少要拿几个增强 要是无法到达L位置则输出-1
Input:
t cases
n 障碍数 m 增强数 L 终点
n行包含区间[l , r] 下标就是序号
m行内每行两个整数 x(位置) v(值) 可能一个x内u多个v 
x保证非严格递增输入 障碍内保证没有x
2* 1e5
Output:
要到L位置拿到的最少增益
如果到不了L则直接输出-1
*/