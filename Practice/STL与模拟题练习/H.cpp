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
    int t;cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        map<char,int> freq;
        freq['a'] = freq['e'] = freq['i'] = freq['o'] = freq['u'] = 0; 
        for(auto p : s){
            if(p == 'a' or p == 'e' or p =='i' or p=='o' or p=='u'){
                freq[p]++;
            }
        }
        for(auto p : freq){
            cout << p.first << ':' << p.second << endl;
        }
        cout << endl;
    }
    return 0;
}