/*https://www.luogu.com.cn/problem/P2678*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int l,m,n;
vector<int> a;

bool check(int x) {
	int p = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - p < x) cnt++;
		else p = a[i];
	}
	return cnt<=m;
}

void solve(){
    cin >> l >> n >> m;
    a.resize(n);
    for(int &x :a) cin >> x;
    int r = l;l = 0;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    if(!check(l)) l--;
    cout << l << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}