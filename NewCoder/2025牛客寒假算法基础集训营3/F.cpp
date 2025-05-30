#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, a, b, c;cin >> a >> b >> c;
        int pa ,pb, pc;pa = pb = pc = n/3;
        int res = 0, less = 0;
        if(pa > a) res += pa - a;
        if(pa < a) less += a - pa;
        if(pb > b) res += pb - b;
        if(pb < b) less += b - pb;
        if(pc > c) res += pc - c;
        if(pc < c) less += c - pc;
        if(res == less) yes;
        else no;
    }
    return 0;
}
/*

*/