/*https://qoj.ac/contest/1280/problem/6696*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int A,B;cin >> A >> B;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                int r = 0,b = 0;
                if(i == 1 || i == 4) r += i;
                else b += i;
                if(j == 1 || j == 4) r += j;
                else b += j;
                if(k == 1 || k == 4) r += k;
                else b += k;
                if(r == A && b == B){
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}