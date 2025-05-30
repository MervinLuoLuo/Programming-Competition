#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e8 + 7;

signed main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int t, m;
	cin >> t >> m;
	vector<int> dp(1005);
	vector<int> time(m + 5), val(m + 5);
	for (int i = 1; i <= m; i++) {	
		cin >> time[i] >> val[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= time[i]; j--) {
				dp[j] = max(dp[j - time[i]] + val[i], dp[j]);
		}
	}
	cout << dp[t];
	return 0;
}
/*
https://www.luogu.com.cn/problem/P1048
*/