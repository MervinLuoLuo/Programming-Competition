#include<bits/stdc++.h>
using namespace std;
#define yes cout<<"0"<<endl
#define no cout<<"NO"<<endl
#define int long long
using ll = long long;
using db = double;
using pii = pair<int, int>;
const int N = 314159;
const int INF = 1e9;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> x(n + 5), a(n + 5);
		for (int i = 2; i <= n; i++)cin >> x[i];
		a[1] = N;
		for (int i = 2; i <= n; i++) {
			a[i] = a[i - 1] + x[i];
			if (a[i] > INF)a[i] = x[i];
		}

		//cout << "========";
		//for (int i = 2; i <= n; i++) {
		//	cout << a[i] % a[i - 1] << " ";
		//}
		//cout << endl;
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		
		cout << endl;
	}

	return 0;
}