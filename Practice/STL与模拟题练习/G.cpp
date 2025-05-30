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
    string s, ss;cin >> ss;
    cin.ignore();
    getline(cin,s);
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    transform(ss.begin(),ss.end(),ss.begin(),::tolower);
    //cout << s << endl << ss << endl;
    ss += ' '; s += ' ';
    s.insert(s.begin(), ' ');
    ss.insert(ss.begin(), ' ');
    int idx = s.find(ss);
    int pos = idx;
    if(idx == -1){
        cout << -1;
        return 0;
    }
    int cnt = 0;
    while(pos != -1){
        cnt++;
        pos = s.find(ss,pos+1);
    }
    cout << cnt << ' ' << idx << endl;
    return 0;
}