/*https://vjudge.net/contest/685207#problem/B*/
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
    int n;
    int m;
    while(cin >> n >> m){
        if(n == 0){cout << "0.00" << endl;continue;}
        double cur = static_cast<double>(n);
        double sum = cur;
        for(int i = 0; i < m - 1; i++){
            cur = sqrt(cur);
            sum += cur;
        }
        printf("%.2f\n", sum);
    }
    return 0;
}