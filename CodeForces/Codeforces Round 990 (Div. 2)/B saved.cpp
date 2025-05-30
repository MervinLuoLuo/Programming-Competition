#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    if(n == 1) {cout << s << endl;return;}
    vector<int> alpha(26, 0);
    for(int i = 0; i < n; i++){
        alpha[s[i] - 'a']++;
    }
    int maxe = -1, mine = maxn;
    char maxc = 'a', minc = 'a';
    for(int i = 0; i < 26; i++){
        if(alpha[i] > maxe){maxe = alpha[i];maxc = 'a' +i;}
        if(alpha[i] < mine){mine = alpha[i];minc = 'a' + i;}
    }
    int po = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != maxc and alpha[s[i] - 'a'] == mine ) {po = i; break;}
    }
    cout << po;
    /*if(po != -1){
        s[po] = maxc;
        cout << s << endl;return;}
    else {cout << s <<endl;return;}*/
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
长度为 n 的字符串 s 只由英文字母构成
选择两个可以相同的位置 1<= i j <= n
令 s[i] = s[j]
只进行一次操作
求操作后变化成的字符串中的字母的排列情况最少的字符串
Input: 
t cases
n
s
Output: 
能排列出的情况最少的字符串

Idea: 
找原串中数量最多的字母 替换原串中数量最少的字母
*/