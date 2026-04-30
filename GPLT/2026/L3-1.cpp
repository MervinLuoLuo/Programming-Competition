/*https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=2045820921833533452&page=2*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct Info{
    int a,b;
    string id;
    int age;
};

void solve(){
    int n;cin >> n;
    queue<int> q;
    vector<Info> normal,old;
    for(int i = 1; i <= n; i++){
        int x,y;cin >> x >>y;
        string id;cin >> id;
        int age;cin >> age;
        if(age >= 80) old.push_back({x,y,id,age});
        else normal.push_back({x,y,id,age});
    }
    
    sort(normal.begin(),normal.end(),[](Info x,Info y){
        
    });
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}