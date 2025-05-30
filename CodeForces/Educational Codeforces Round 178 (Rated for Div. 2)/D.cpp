/*https://codeforces.com/contest/2104/problem/D*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

//质数筛
vector<int> prime,isprime(6e6,1);
void selectp(){
    for(int i = 2; i < 6e6; i++){
        if(!isprime[i]) continue;
        prime.push_back(i);
        for(int j = i; j < 6e6; j += i){
            isprime[j] = 0;
        }
    }
}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end(),greater<int>());
    int cnt = 0;
    int suma = 0, sump = 0;
    for(int i = 0; i < n ;i++){
        suma += a[i];
        sump += prime[i];
        if(suma >= sump) cnt = i + 1;
    }
    cout << n - cnt << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;selectp();
    while(t--){
       solve();
    }
    return 0;
}