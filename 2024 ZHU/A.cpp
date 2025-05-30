#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<int> a(n + 5);
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){cout << a[1] + 1 << endl;return 0;}
    sort(a.begin() + 1,a.begin() + n);
    /*for(auto p : a){
        cout << p << ' ';
    }*/
    int max = -1;
    for(int i = n ; i > 0; i--){
        if(i == n){
            int mid = a[i];
            int now = mid+1;
            if(now > max) max = now;
            continue;
        }
        int cnt = n - i  + 1;
        int mid = a[(cnt + 1) / 2];
        int now = mid + cnt;
        if(now > max) max = now;
    }
    cout << max << endl;
    return 0;
}