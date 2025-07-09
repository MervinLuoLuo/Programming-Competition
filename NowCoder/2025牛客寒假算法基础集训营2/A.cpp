#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n = 7;
    while(n--){
        int x;cin >> x;
        if(x != 1 and x != 2 and x != 3 and x != 5 and x !=6){
            no;return 0;
        }
    }
    yes;
    return 0;
}