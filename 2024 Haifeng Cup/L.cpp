#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

int mod(int a,int b){
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;cin >> n >> k;
    set<int> a;
    while(n--){
        int x;cin >> x;
        x = x % k;
        a.insert(x);
    }

    return 0;
}