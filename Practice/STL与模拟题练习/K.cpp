#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(int a, int b){
    return abs(a) > abs(b);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin >> n){
        if(n == 0) return 0;
        vector<int> a(n);
        int min =  maxn;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end(),cmp);
        for(auto p : a){
            cout << p << ' ';
        }
        cout << endl;
    }
    return 0;
}