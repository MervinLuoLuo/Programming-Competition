/*https://www.luogu.com.cn/problem/P1223*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(pii a, pii b){
    return a.first < b.first;
}
void solve(){
    int n;cin >> n;
    vector<pii> t(n);
    for(int i = 0; i <n ;i++) {
        int x;cin >> x;
        t[i] = {x,i + 1};
    }
    sort(t.begin(),t.end(),cmp);
    vector<int> w(n);
    w[0] = 0;
    cout << t[0].second <<  " ";
    for(int i = 1; i < n; i++){
        w[i] = w[i - 1] + t[i - 1].first;
        cout << t[i].second <<  " "; 
    }
    cout << endl;
    int sum = accumulate(w.begin(),w.end(),0LL);
    double ans = (double)sum / n;
    printf("%.2lf",ans * 1.0);
}
signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}