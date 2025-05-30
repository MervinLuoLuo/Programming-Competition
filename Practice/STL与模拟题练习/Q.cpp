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
    int n, m;
    while(cin >> n >> m){
        if(n == 0 and m == 0) return 0;
        int cnt = 0;
        for(int i = n; i <= m; i++){
            string num = to_string(i);
            bool flag = 1;
            if(num.find('4') != string::npos) flag = 0;
            if(num.find("62") != string::npos) flag = 0;
            if(flag) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}