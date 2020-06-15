#include <stdlib.h>
//ここから二分探索木
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
