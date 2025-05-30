#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> freq;
    for(int i = 0; i <n ;i++){
        int x;cin >> x;
        freq[x]++;
    }

    for(auto it : freq){
        if(it.second >= 4){yes;return;}
        if(it.second >= 2){
            if(freq[it.first + 1] >= 2){yes;return;}
            int x = 1;
            while(freq[it.first + x]){
                if(freq[it.first + x] >= 2){yes;return;}
                x++;
            }
        }
    }
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}