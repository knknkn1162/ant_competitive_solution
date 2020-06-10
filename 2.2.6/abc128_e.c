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

int get_int3(int *a1, int *a2, int *a3) {
  scanf("%d %d %d", a1, a2, a3);
  return 0;
}

//ここから二分探索木
typedef struct bt
{
	int value;
	struct bt *left;
	struct bt *right;
}btree;
 
//int btsize=0;
btree *root;
//root = NULL;
 
void insert(int value)
{
	btree *x,*y,*z;
	z = (btree *)(malloc(sizeof(btree)));//新しい要素のメモリ確保
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
	//printf("inserted %d\n",value);
}
 
btree *del(btree *dstt, btree *t)
{
	btree *q;
	if(t->right!=NULL)t->right = del(dstt,t->right);
	else
	{
		dstt->value = t->value; 
		q = t;
		t = t->left;
		free(q);
	}
	return(t);
}
 
void delete(int value)
{
	btree *x,*y,*z,*p;
	x=root;
	while(x!=NULL && x->value!=value)
	{
		p=x;//親になる
		if(value < x->value)x = x->left;
		else x = x->right;
	}
	//printf("%d %d\n",x->left,x->right);
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
		//printf("%d %d\n",y,*(y));
		free(z);
	}
	else
	{
		y->left = del(y,y->left);//左部分木の最右節点をこの木の根に移動する
	}
	//printf("deleted %d\n",value);
}
 
int peek_min()
{
	btree *x,*y;
	x=root;
	while(x!=NULL)
	{
		y=x;
		x=x->left;
	}
	if(x==root)return -1;
	else return (y->value);
}
 
//ここまで二分探索木

#define NUM_MAX 200000
#define QUERY_MAX 200000

struct event {
    int flag;
    int time;
    int pos;
};

enum flag {
    FLAG_DELETE,
    FLAG_INSERT,
    FLAG_QUERY,
};

int asc_by_time(const void *a1, const void *a2) {
    struct event *e1 = (struct event*)a1;
    struct event *e2 = (struct event*)a2;
    if(e1->time == e2->time) {
        return e1->flag - e2->flag;
    }
    return e1->time - e2->time;
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
#define INF ((1e+9)+1)
int main(void) {
    int num, qs;
    get_int2(&num, &qs);
    int i;
    static struct event events[NUM_MAX*2+QUERY_MAX+2];
    static int eidx = 0;
    events[eidx++] = (struct event){FLAG_INSERT, -INF, INF};
    for(i = 0; i < num; i++) {
        int start, end, pos;
        get_int3(&start, &end, &pos);
        start -= pos;
        end -= pos;
        events[eidx++] = (struct event){FLAG_INSERT, start, pos};
        events[eidx++] = (struct event){FLAG_DELETE, end, pos};
    }
    events[eidx++] = (struct event){FLAG_DELETE, INF, INF};

    for(i = 0; i < qs; i++) {
        int time = get_int();
        events[eidx++] = (struct event){FLAG_QUERY, time, 0};
    }
    qsort(events, eidx, sizeof(struct event), asc_by_time);

    int mmin = INF;
    static int ans[QUERY_MAX];
    int aidx = 0;
    for(i = 0; i < eidx; i++) {
        struct event e = events[i];
        if(e.flag == FLAG_QUERY) {
            ans[aidx++] = mmin;
            continue;
        }
        if(e.flag == FLAG_INSERT) {
            insert(e.pos);
        } else if (e.flag == FLAG_DELETE) {
            delete(e.pos);
        }
        mmin = peek_min();
    }

    // presentation
    for(i = 0; i < aidx; i++) {
        printf("%d\n", ans[i] == INF ? -1 : ans[i]);
    }
    return 0;
}
