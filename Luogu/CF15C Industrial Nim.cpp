/*https://www.luogu.com.cn/problem/CF15C*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void SG(){
    vector<int> arr = {24,35,21,42};
    int maxx = *max_element(arr.begin(),arr.end());
    vector<int> sg(maxx + 1);
    sg[0] = 0;
    vector<int> vis;
    for(int i = 1; i <= maxx; i++){
        vis.assign(maxx + 1,0);
        for(int j = 0; j < i; j++) vis[j] = 1;
        for(int s = 0;s <= maxx; s++){
            if(!vis[s]){
                sg[i] = s;
                break;
            }
        }
    }
    
    for(int i = 0; i <= maxx; i++) cout << "sg[" << i << "]: " << sg[i] << endl;
}

void solve(){
    int n;cin >> n;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    SG();
    solve();
    return 0;
}