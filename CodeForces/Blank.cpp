// #include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
// using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

typedef struct { 
    int  key;                                             
} ElemType;  
typedef struct {
    ElemType  *R; 
    int  length;
} SSTable; 

void reverseSSTable(SSTable &T){
    int n = T.length;
    for(int i = 0; i < (n >> 1); i++){
        int tmp = T.R[i].key;
        T.R[i].key = T.R[n - i - 1].key;
        T.R[n - i - 1].key = tmp;
    }
}
 
void createSSTable(SSTable &T){
    T.R = (ElemType*)malloc(T.length * sizeof(ElemType));
    for(int i = 0; i < T.length; i++){
        scanf("%d",&T.R[i].key);
    }
}

void printSSTable(SSTable T){
    for(int i = 0; i < T.length; i++) printf("%d ",T.R[i].key);
}

void solve(){
    SSTable st;
    st.length = 5;
    int n = 5;
    st.R = (ElemType*)malloc(st.length * sizeof(ElemType));
    for(int i = 0; i < n; i++){
        scanf("%d",&st.R[i].key);
    }

    reverseSSTable(st);
    for(int i = 0; i < n; i++) printf("%d ",st.R[i].key);
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}