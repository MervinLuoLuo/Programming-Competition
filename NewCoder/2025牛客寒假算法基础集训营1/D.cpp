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
    int t; cin >> t;
    while(t--){
        map<int,int> freq;
        int n;cin >> n;
        for(int i = 0; i < n; i++){
            int x;cin >> x;
            freq[x]++;
        }
        if(n % 2 != 0){no;continue;}
        if(freq.size() != 2){no;continue;}
        int cnt = freq.begin()->second;
        bool flag = 1;
        for(auto it : freq){
            if(it.second != cnt) flag = 0;
        }
        if(flag) yes;
        else no;
    }
    return 0;
}
/*

*/