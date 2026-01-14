#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *next;
}LNode,*LinkList;

LinkList Creat_Link(){
    LinkList pf,p,L = NULL;
    p = (LinkList)malloc(sizeof(LNode));
    cin >> p -> data;
    while(p->data == -1){
        if(!L) L = pf = p,p -> next = NULL;
        else pf -> next = p;
        pf = p;
        p = (LinkList)malloc(sizeof(LNode));
        p -> next = NULL;
        cin >> p-> data;
    }
    free(p);
    return L;
}

LinkList Mid(LinkList &L){
    LinkList q = L;
    
    return q;
}

int main(){
    LinkList L,pk;
    int k;
    L = Creat_Link();
    pk = Mid(L);   
    return 0;
}