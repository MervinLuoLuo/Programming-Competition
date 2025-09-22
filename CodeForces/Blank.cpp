#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool isValid(vector<int>& a, vector<int>& b) {
    stack<int> st;
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        st.push(a[i]);
        while (!st.empty() && st.top() == b[j]) {
            st.pop();
            j++;
        }
    }
    return j == b.size();
}

void solve(){
	int n = 6;
	vector<int> a(n),b(n);
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;
	cout << isValid(a,b) <<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
	return 0;
}