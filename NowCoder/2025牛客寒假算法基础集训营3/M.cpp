#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "happy new year" << endl
#define no cout << "I AK IOI" << endl
#define NS = "nowcoder"
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin >> s;
    map<char, int> freq;
    for(auto it : s) freq[it]++;
    if(freq['n'] != 1 or freq['o'] != 2 or freq['w'] != 1 or freq['c'] != 1 or freq['d'] != 1 or freq['e'] != 1 or freq['r'] != 1) no;
    else yes;
    return 0;
}