#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >>n;
    vector<int> a(n + 5);
    bool flag = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
        if(a[i] != a[i + 1]) {flag = 0;break;}
    }
    if(flag) cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}