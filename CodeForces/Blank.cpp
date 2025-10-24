#include <stdio.h>
#include <stdlib.h>
 
// #define DEBUG
#ifdef DEBUG
#define D(x) x
#else 
#define D(x) 
#endif

#define GUARD   -99
#define Status int
 
typedef struct PNode
{
    int coef;     // 系数
    int expn;       // 指数
    struct PNode *next;      
} PNode, *Polynomial;

//输出多项式内容
void printPolyn(Polynomial &p){
    PNode *L = p;
    printf("Polyn [%d]: ", L->expn);//头结点的系数保存多项式的长度 
    L = L->next;
    while(L)
    {
        if (L->next)
        {
            if(L->expn!=0)
                printf("%d*x^%d ",L->coef,L->expn);
            else
                printf("%d ",L->coef);
        } else
        {
            if(L->expn!=0)
                printf("%d*x^%d",L->coef,L->expn);
            else
                printf("%d",L->coef);
        }
        
        L = L->next;
    }

    printf("\n");
}

//在合适的位置插入新结点，使得多项式的指数从高到低排列 
Status InsertPolyNode(Polynomial &p, int coef, int expn){
    
    PNode* pre, * q;
    PNode* s = new PNode;
    s->coef = coef;
    s->expn = expn;
    pre = p; // pre用于保存q的前驱结点, 即头节点p
    q=p->next;
    while(q&&q->expn>s->expn){// 通过比较指数找出第一个小于或等于输入项的指数的项*q
        pre=q;
        q = q->next;
    }
    if (q){
        if (q->expn==s->expn && q->coef+s->coef!=0){//如果指数相等且对应系数和不为0，则更新该结点 
            q->coef=q->coef+s->coef;
        }
        else if (q->expn==s->expn && q->coef+s->coef==0){//如果指数相等且对应系数和为0，则删除该结点 
            pre->next=q->next;
           // q=q->next;
            delete s; 
            delete q; 
            p->expn--;
        }
        else if (q->expn!=s->expn){//如果指数不相等，则删插入新结点
            pre->next=s; 
            s->next=q;
            p->expn++;
        }
    }
    else//如果q为空，则插入新结点 
    {
        pre->next=s; 
        s->next=q;
        p->expn++;
    }
    
    return 1;
 }

//根据键盘输入创建一个多项式
Status CreatePolynomail(Polynomial &p)
{
    p = new PNode;
    p->next = NULL;
    p->coef = 0;
    p->expn = 0;
    int length;
    int ceof[100];
    int expn[100];
    int i=0;
 
    D(printf("输入多项式系数序列，以-99结束: \n"); )
    scanf("%d", &ceof[i]);
    while(ceof[i]!=GUARD)
    {
        i++; 
        scanf("%d", &ceof[i]);  
    }
    
    i=0;
    D(printf("输入多项式指数序列，以-99结束: \n");)
    scanf("%d", &expn[i]);
    
    while(expn[i]!=GUARD)
    {
        i++; 
        scanf("%d", &expn[i]);  
    }
    
    length=i;
    /*根据输入的系数和指数数组创建多项式有序列表*/

    for(i=0; i<length; i++)
        InsertPolyNode(p, ceof[i], expn[i]);
    
    return 1;
}

//多项式加法：pa = pa + pb
Status AddPolyn(Polynomial &pa,Polynomial pb);

//多项式乘法：pc = pa*pb
Status MultiplyPolyn(Polynomial &pc,Polynomial pa,Polynomial pb);

//对多项式pa求一阶导
Status DerivativePolyn(Polynomial& pa);

int main()
{
    int choice, expn;
    int coef;
    Polynomial p,p1,p2,p3; 
    for (;;)
    {
        D(printf("\n           多项式的基本操作  \n");)
        D(printf("             1.创建一个多项式\n");)
        D(printf("             2.插入一项\n");)
        D(printf("             3.多项式求和\n");)
        D(printf("             4.多项式求积\n");)
        D(printf("             5.多项式求导\n");)
        D(printf("             6.退出系统\n");)
        
        D(printf("请选择：");)                                                      
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:  CreatePolynomail(p);
                 printPolyn(p);
                 break;              
        case 2:  D(printf("输入要插入项的系数: ");)
                 scanf("%d", &coef); 
                 D(printf("输入要插入项的指数: ");)
                 scanf("%d", &expn); 
                 InsertPolyNode(p, coef, expn);
                 printPolyn(p);
                 break;
        case 3:  CreatePolynomail(p1);
                 printPolyn(p1);
                 CreatePolynomail(p2);
                 printPolyn(p2);
                 D(printf("多项式求和得: ");)
                 AddPolyn(p1, p2);
                 printPolyn(p1);
                 break;
        case 4:  CreatePolynomail(p1);
                 printPolyn(p1);
                 CreatePolynomail(p2);
                 printPolyn(p2);
                 D(printf("多项式求积得: ");)
                 MultiplyPolyn(p3,p1,p2);
                 printPolyn(p3);
                 break;
        case 5:  D(printf("多项式求导得: ");)
                 DerivativePolyn(p);
                 printPolyn(p);
                 break;
        case 6:  D(printf("请退出系统!\n");) exit(0); break;
        }
    }
    return 1;
}

//多项式加法：pa = pa + pb
Status AddPolyn(Polynomial &pa,Polynomial pb){
    PNode *pre = pa;
    PNode *a = pa->next;
    PNode *b = pb->next;
    while(a && b){
        if(a -> expn > b -> expn){
            pre = a;
            a = a-> next;
            // continue;
        }
        else if(a -> expn < b -> expn){
            PNode* s = new PNode;
            s->coef = b->coef;
            s->expn = b->expn;
            s->next = a;
            pre->next = s;
            pre = s;
            pa->expn++;
            b = b->next;
        }
        else{
            a->coef += b->coef;
            if (abs(a->coef) < 1e-8) {
                pre->next = a->next;
                delete a;
                a = pre->next;
                pa->expn--;
            } 
            else {
                pre = a;
                a = a->next;
            }
            b = b->next;
        }
    }

    while (b) {
        PNode* s = new PNode;
        s->coef = b->coef;
        s->expn = b->expn;
        s->next = NULL;
        pre->next = s;
        pre = s;
        pa->expn++;
        b = b->next;
    }

    return 1;
}

//多项式乘法：pc = pa*pb
Status MultiplyPolyn(Polynomial &pc,Polynomial pa,Polynomial pb){
    pc = new PNode;
    pc->next = NULL;
    pc->coef = 0;
    pc->expn = 0;

    for (PNode* a = pa->next; a != NULL; a = a->next) {
        for (PNode* b = pb->next; b != NULL; b = b->next) {
            int nc = a->coef * b->coef;
            int ne = a->expn + b->expn;
            if (nc != 0) {
                InsertPolyNode(pc, nc, ne);
            }
        }
    }
    // pc->expn = pb->expn;
    return 1;
}

//对多项式pa求一阶导
Status DerivativePolyn(Polynomial& pa){
    PNode *pre = pa, *cur = pa -> next;

    while(cur){

        //常数项
        if(cur -> expn == 0){
            pre -> next = cur -> next;
            delete cur;
            cur = pre -> next;
            pa -> expn--;
            continue;
        }

        else{
            cur->coef = cur->coef * cur->expn;
            cur -> expn = cur -> expn - 1;
            pre = cur;
            cur = cur -> next;
        }
    }

    if(!pa -> next) pa -> expn = 0;
    return 1;
}