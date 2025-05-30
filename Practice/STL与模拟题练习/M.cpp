#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n, r;
vector<int> a;

void dfs(int m, vector<int> &a){
    if(m > r){
        for(int i = 1; i <= r; i++){
            cout << setw(3) << a[i];
        }
        cout << endl;
        return;
    }
    for(int i = a[m - 1] + 1; i <= n; i++){
        a[m] = i;
        dfs(m + 1, a);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> r;
    a.assign(n + 5,0);
    dfs(1, a);
    return 0;
}