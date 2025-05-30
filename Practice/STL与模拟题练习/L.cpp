#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool Keyword(const string& s) {
    static unordered_set<string> keywords = {
        "if","else","while","signed","throw","union","this","int","char","double","unsigned","const","goto","virtual","for","float","break","auto","class","operator","case","do","long","typedef","static","friend","template","default","new","void","refister","extern","return","enum","inline","try","short","continue","sizeof","switch","private","protected","asm","while","catch","delete","public","volatile","struct","extern","next_permutation","char","long long","unsigned char","double","float","short","do"
    };
    return keywords.count(s);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        cin.ignore();
        string s;
        getline(cin, s);
        bool flag = 1;
        if(!isalpha(s[0]) and s[0] != '_') flag = 0;
        for(auto p : s){
            if (!isalnum(p) and p != '_') {
                flag = 0;
            break;
            }
        }
        if (Keyword(s)) flag = 0;
        if(flag) yes;
        else no;
    }
    return 0;
}