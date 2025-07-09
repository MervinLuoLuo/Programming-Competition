#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool isPrime(int a){
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0) return false;
    }
    return true;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n);
        for(int i = 0;  i< n; i++){
            cin >> a[i];
        }        
        sort(a.begin(),a.end());
        if(a[0] == 1){cout << -1 << endl;continue;}
        for(int x = a[n - 1]; ; x++){
            if(isPrime(x)){
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}
/*

*/