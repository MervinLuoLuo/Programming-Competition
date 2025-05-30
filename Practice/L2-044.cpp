#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e9 + 5;
using pii = pair<int, int>;

int main() {
	vector<int> male, female;
	int n; cin >> n;
	vector<vector<int>> dis(n + 5);
	for (int i = 0; i < n + 5; i++)dis[i].resize(n + 5, N);

	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		if (c == 'F')female.push_back(i);
		else male.push_back(i);

		int m; cin >> m;
		for (int j = 1; j <= m; j++) {
			int u, dis0;
			scanf("%d:%d", &u, &dis0);
			dis[i][u] = dis0;
			// 是有向的，是 i 单方面觉得和 u 的距离
			//dis[u][i] = dis0;
		}
	}

	// 弗洛伊德
	for (int i = 1; i <= n; i++) { dis[i][i] = 0; }
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}

	// 距离最小，异性缘最大
	// 注意是这个 男/女i 在异性j眼中 的距离
	// 也即 dis[异性j][男/女i]
	vector<pii> ansma, ansfe;
	for (int i = 0; i < male.size(); i++) {
		int maxi = 0;
		for (int j = 0; j < female.size(); j++) {
			maxi = max(maxi, dis[female[j]][male[i]]);
		}
		ansma.push_back({ maxi,male[i] });
	}

	for (int i = 0; i < female.size(); i++) {
		int maxi = 0;
		for (int j = 0; j < male.size(); j++) {
			maxi = max(maxi, dis[male[j]][female[i]]);
		}
		ansfe.push_back({ maxi,female[i] });
	}

	sort(ansma.begin(), ansma.end());
	sort(ansfe.begin(), ansfe.end());

	// 处理结尾空格，tnnd
	int maxi = ansfe[0].first;
	int maxi2 = ansma[0].first;
	while (ansfe.back().first != maxi)ansfe.pop_back();
	while (ansma.back().first != maxi2)ansma.pop_back();

	for (int i = 0; i < ansfe.size(); i++) {
		if (i != 0)cout << " ";
		cout << ansfe[i].second;
	}
	cout << endl;

	for (int i = 0; i < ansma.size(); i++) {
		if (i != 0)cout << " ";
		cout << ansma[i].second;
	}
	cout << endl;

	return 0;
}