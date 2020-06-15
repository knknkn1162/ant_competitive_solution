#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // int64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

int get_int(void) {
  int num;
  scanf("%d", &num);
  return num;
}

int get_int2(int *a1, int *a2) {
  scanf("%d %d", a1, a2);
  return 0;
}

//ここから二分探索木
struct child {
    int rate;
    int label;
};

struct btree {
    int value;
    struct btree *left;
    struct btree *right;
};
 
void insert(struct btree *root, int value)
{
    struct btree *x,*y,*z;
    z = (struct btree *)(malloc(sizeof(struct btree)));//新しい要素のメモリ確保
    z->value=value;
    z->left=NULL;
    z->right=NULL;
    
    x=root; y=NULL;
    while(x!=NULL)
    {
        y=x;
        if(z->value < x->value)x = x->left;
        else x = x->right;
    }
    if(y==NULL)root=z;
    else if(z->value < y->value)y->left=z;
    else y->right=z;
}
 
struct btree *_del(struct btree *dstt, struct btree *t) {
    struct btree *q;
    if(t->right!=NULL)t->right = _del(dstt,t->right);
    else
    {
        dstt->value = t->value; 
        q = t;
        t = t->left;
        free(q);
    }
    return(t);
}
 
void delete(struct btree *root, int value)
{
    struct btree *x,*y,*z,*p;
    x=root;
    while(x!=NULL && x->value!=value)
    {
        p=x;//親になる
        if(value < x->value)x = x->left;
        else x = x->right;
    }
    y=x;//削除されるべき値を持ったノード
    if(y->right==NULL)//右部分木がない
    {
        z = y;
        if(y==root)root =y->left;
        else if(value < p->value)p->left =y->left;
        else p->right = y->left;
        free(z);
    }
    else if(y->left==NULL)//左部分木がない
    {
        z = y;
        if(y==root)root =y->right;
        else if(value < p->value)p->left =y->right;
        else p->right = y->right;
        free(z);
    }
    else
    {
        y->left = _del(y,y->left);//左部分木の最右節点をこの木の根に移動する
    }
}
 
#define INF ((1e+9)+1)
int get_max(struct btree *root)
{
    struct btree *x,*y;
    y = NULL;
    x = root;
    while(x)
    {
        y=x;
        x=x->right;
    }
    if(x==root)return -1;
    else return (y->value == 0) ? INF : y->value;
}
 
//ここまで二分探索木
#define NUM_MAX 200000
#define QUERY_MAX 200000
#define SCHOOLS 200000
#define SCHOOLS2 (2<<18)
#define ROOT_NODE 1

void update(int *seg, int num, int val, int idx) {
    int node = num + idx;
    seg[node] = val;
    while((node = node / 2)) {
        seg[node] = min(seg[node*2], seg[node*2+1]);
    }
    return;
}

int main(void) {
    int num, queries;
    int i;
    get_int2(&num, &queries);
    static struct btree root[SCHOOLS];
    static int rates[NUM_MAX];
    static int map[NUM_MAX];

    for(i = 0; i < num; i++) {
        int rate, school;
        get_int2(&rate, &school);
        // 1-indexed -> 0-indexed
        school--;
        insert(&root[school], rate);
        map[i] = school;
        rates[i] = rate;
    }

    static int seg[SCHOOLS2*2];
    memset(seg, 0x7f, sizeof(int)*(SCHOOLS2*2));
    for(i = 0; i < SCHOOLS; i++) {
        int val = get_max(&root[i]);
        seg[SCHOOLS2+i] = val;
    }
    for(i = SCHOOLS2-1; i >= ROOT_NODE; i--) {
        seg[i] = min(seg[i*2], seg[i*2+1]);
    }
#ifdef DEBUG
    printf("init: %d\n", seg[ROOT_NODE]);
#endif

    static int ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < queries; i++) {
        int child, new_school;
        get_int2(&child, &new_school);
        // 1-indexed -> 0-indexed
        child--; new_school--;
        int old_school = map[child];
        int rate = rates[child];
        delete(&root[old_school], rate);
        update(seg, SCHOOLS2, get_max(&root[old_school]), old_school);

        insert(&root[new_school], rate);
        update(seg, SCHOOLS2, get_max(&root[new_school]), new_school);
#ifdef DEBUG
        printf("%d %d\n", get_max(&root[old_school]), get_max(&root[new_school]));
#endif
        ans[aidx++] = seg[ROOT_NODE];
        map[child] = new_school;
    }

    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
