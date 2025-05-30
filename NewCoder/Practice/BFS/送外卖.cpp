/*https://ac.nowcoder.com/acm/problem/13224*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n;
vector<int> a, b;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    a.resize(n);b.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }    
    for(int i = 0;i < n; i++){
        cin >> b[i];
    }

    return 0;
}