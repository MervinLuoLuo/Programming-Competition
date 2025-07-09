#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(const pair<char,int> &a, const pair<char,int> &b){
    return a.second > b.second;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    string s;cin >> s;
    map<char, int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
    }
    vector<pair<char,int>> a(freq.begin(),freq.end());
    sort(a.begin(),a.end(),cmp);
    cout << a[0].first << endl;
    return 0;
}