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
 
int minvalue()
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
