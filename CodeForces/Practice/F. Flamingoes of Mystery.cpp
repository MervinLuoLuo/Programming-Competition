/*https://codeforces.com/problemset/problem/1425/F*/
#include <bits/stdc++.h>
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    int n;cin >> n;
    vector<int> a(n + 2) ,pre(n + 2, 0);
    for(int i = n; i >= 2; i--){
        cout << "? 1 " << i << endl;
        fflush(stdout);
        cin >> pre[i];
    }

    for(int i = n; i >= 3; i--){
        a[i] = pre[i] - pre[i - 1];
    }
    cout << "? 2 3" << endl;
    fflush(stdout);
    int tmp;cin  >> tmp;
    a[2] = tmp - a[3];
    a[1] = pre[2] - a[2];
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}