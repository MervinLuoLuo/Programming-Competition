/*https://www.luogu.com.cn/problem/P1102*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,c;cin >> n >> c;
    vector<int> a(n);
    for(int &x :a) cin >> x;
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cur = a[i] + c;
        if(cur > a[n - 1]) break;
        int add = 0;
        int l= -1, r = n;
        while(l + 1 != r){
            int mid = l + r >> 1;
            if(a[mid] < cur) l = mid;
            else r = mid;
        }
        int be = r;
        if(a[r] != cur)continue;
        l = -1, r = n;
        while(l + 1 != r){
            int mid = l + r >> 1;
            if(a[mid] > cur)r = mid;
            else l = mid;
        }
        int ed = l;
        if(a[l] != cur) add = 1;
        else add = ed - be + 1;
        ans += add;
    }
    cout << ans << endl;
}

void solve1(){
    int n,c;cin >> n >> c;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 0, j = 0; i < n;i++){
        while(a[i] - a[j] >= c && j <= i) {
            if(a[i] - a[j] == c) ans++;
            j++;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
        //solve();//二分做法 会卡一个 task
        solve1();//双指针做法
    }
    return 0;
}