#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    ll n;cin >> n;
    char a;cin >> a;
    if(a == '+') {cout << 1 << ' ' << n - 1 << endl;return;}
    if(a == '-') {cout << n + 1 << ' ' << 1 << endl;return;}
    if(a == '*') {cout << 1 << ' ' << n << endl;return;}
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}