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
    string s;
    while(cin >> s){
        cin.ignore();
        char maxc = '1';
        for(int i = 0; i < s.size(); i++){
            if(s[i] > maxc) maxc = s[i];
        }
        string maxx = "(max)";
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == maxc){
                s.insert(i + 1, maxx);
            }
        }
        cout << s << endl;
    }
    return 0;
}