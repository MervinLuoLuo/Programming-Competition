#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll INF = 1e17;
const ll maxn = 1e7;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n, a, b;cin >> n >> a >> b;
        if(a * 2 < b) cout << n * a << endl;
        else{cout << (n / 2) * b + (n % 2) * a << endl;}
    }

    return 0;
}