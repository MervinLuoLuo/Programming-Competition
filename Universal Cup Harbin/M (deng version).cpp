#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define int long long
using pii = pair<int, int>;

const int maxn = 1e6;
bool NotPrime[maxn + 5];
vector<int> Prime;

// 埃氏筛，可以优化成欧拉筛
void ini() {
	NotPrime[0] = 1;
	NotPrime[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (NotPrime[i])continue;
		Prime.push_back(i);
		for (int j = 2; i * j < maxn; j++) {
			NotPrime[i * j] = 1;
		}
	}
}

// 质因子分解
vector<pii> solve(int x) {
	unordered_map<int, int> cnt;
	// 枚举所有质因子
	for (int i = 0; i < Prime.size(); i++) {
		while (x % Prime[i] == 0) {
			cnt[Prime[i]]++;
			x /= Prime[i];
		}
		//if (x > maxn && isPrime(x)) { cnt[x]++; break; }
	}

	// 枚举完毕之后如果x还有剩，这个数x必然是质数（可以自己证明）
	if (x > 1)cnt[x]++;
	vector<pii> ans;
	for (auto it : cnt) 
		ans.push_back({ it.first,it.second });
	
	return ans;
}

void get_factor(vector<pii> cnt, vector<int>& ans, int idx, int val) {
	if (idx == cnt.size())return;
	// 质因数 now 有 sum 个
	int now = cnt[idx].first;
	int sum = cnt[idx].second;
	
	int pwr = 1;
	for (int i = 0; i <= sum; i++) {
		val *= pwr;
		ans.push_back(val);
		get_factor(cnt, ans, idx+1, val);
		val /= pwr;
		pwr *= now;
		if (now == 1)break;
	}
}

int func(int a, int b,vector<int> &st) {
	auto it = upper_bound(st.begin(),st.end(),b); it--;
	return (int)(a / (*it));
}

int bino(int L0, int n, vector<int> &st) {
	int L = L0 - 1, R = n + 1;
	int val = func(n, L0, st);
	while (L + 1 != R) {
		int mid = (L + R) / 2;
		int now = func(n, mid, st);
		if (now == val) L = mid;
		else R = mid;
	}
	return L;
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ini();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		auto cnt = solve(n);
		vector<int> st;
		get_factor(cnt, st, 0, 1);
		if (st.empty())st.push_back(1);
		sort(st.begin(), st.end());
		st.erase(unique(st.begin(), st.end()), st.end());

		int sum = 0;
		int L = 1;
		while (L <= n) {
			int R = bino(L, n, st); // 值为 func(n,L) 的区间
			sum += (R - L + 1) * func(n, L, st);
			L = R + 1;
		}
		cout << sum << endl;
	}

	return 0;
}