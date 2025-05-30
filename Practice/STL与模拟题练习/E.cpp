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
    int a, b, c;cin >> a >> b >> c;
    string s; cin >> s;
    vector<int> idx;
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] == '-' and s[i- 1] == s[i + 1]) continue;
        if(s[i] == '-' and s[i + 1] - s[i - 1] == 1){
            s.erase(s.begin() + i);
            continue;
        }
        if(s[i] == '-' and s[i + 1] - s[i - 1] >= 2) idx.push_back(i);
    }
    for(int it = idx.size() - 1; it >= 0; it--){
        int p = idx[it];
        string ss;
        ss.clear();
        if(isalpha(s[p - 1]) and isalpha(s[p + 1])){
            if(a == 1){
                for(char i = s[p - 1] + 1; i < s[p + 1] ;i++){
                    for(int j = 0; j < b; j++){
                        ss += i;
                    }
                }
            }
            if(a == 2){
                for(char i = s[p - 1] + 1; i < s[p + 1]; i++){
                    for(int j = 0; j < b; j++){
                        ss += i;
                    }
                }
                for(int i = 0; i < ss.size();i++){
                    ss[i] -= 32;
                }
            }
            if(a == 3){
                for(int i = 0; i < (s[p  + 1] - s[p - 1]  - 1) * b; i++){
                    ss += '*';
                }
            }
            if(c == 2) reverse(ss.begin(),ss.end());
        }
        else if(isdigit(s[p - 1]) and isdigit(s[p + 1])){
            if(a == 3){
                for(int i = 0; i < (s[p  + 1] - s[p - 1]  - 1) * b; i++){
                    ss += '*';
                }
            }
            else if(a == 1 or a == 2){
                for(char i = s[p - 1] + 1; i < s[p + 1]; i++){
                    for(int j = 0; j < b; j++){
                        ss += i;
                    }
                }
            }
            if(c == 2) reverse(ss.begin(),ss.end());
        }
        else continue;
        s.erase(s.begin() + p);
        s.insert(p ,ss);
        //cout << ss << endl;
    }
    cout << s << endl;
    return 0;
}