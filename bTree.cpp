#include <iostream>
#include <cstdlib>
#include<iomanip>
using namespace std;

const int d=2;
struct btnode
{
int key[2*d+1];
btnode *ptrs[2*d+2];
btnode *parent;
int counter;
int tag;
btnode (int x)
{
counter =0;
tag=x;
for (int i=0;i<2*d+2;i++)
ptrs[i]=NULL;
parent=NULL;
}
};



void sort (btnode* &t);

void insert (btnode* &T,btnode* &t,int k)
{
 if (k!=-1)
	{if (t->tag==1)
		{
			t->key[t->counter++]=k;
			sort (t);
			if(t->counter==2*d+1)
			insert (T,t,-1);
			
		}
	 else 	
		{
		int i=0;
		while (i<t->counter&&k>t->key [i])
		i++;
		insert (T,t->ptrs[i],k);
		}
	}
	
else
 	{
	btnode *n=new btnode(t->tag);
	n->ptrs [0]=t->ptrs[d+1];
	t->ptrs[d+1]=NULL;
	if (n->ptrs[0]!=NULL)                             
	{
	n->ptrs[0]->parent=n;
	}
	
	
	
		for (int i=0;i<d;i++)
		{
		n->key[i]=t->key[i+d+1];
		n->ptrs[i+1]=t->ptrs[i+d+2];
		t->ptrs[i+d+2]=NULL;
		if (n->ptrs[i+1]!=NULL)
		n->ptrs[i+1]->parent=n;
		}
	int x=t->key[d];
	t->counter=d;
	n->counter=d;
		if (t->parent==NULL)
		{
		btnode *a=new btnode(0);
		
		a->ptrs [0]=t;
		a->ptrs[1]=n;
		n->parent=a;
		t->parent=a;
		a->key[a->counter++]=x;//here (t->counter++)is actually equal to 0!!
		T=a;
		}
		else 	
		{
			n->parent=t->parent;
			t->parent->key[t->parent->counter++]=x;
			t->parent->ptrs[t->parent->counter]=n;
			sort(t->parent);
				
			if (t->parent->counter==2*d+1)
			{
			btnode *s=t->parent;
			insert(T,s,-1);
			}
		}	
	}
}

void sort (btnode* &t)
{
int  i=0, k=t->key[t->counter-1];

btnode *k2 = t->ptrs [t->counter];

while (i<t->counter&&t->key[i]<k)
i++;

while  (i<t->counter)
{
int temp =t->key[i];
t->key[i]=k;
k=temp;

btnode *temp2=t->ptrs [i+1];
t->ptrs[i+1]=k2;
k2=temp2;
i++;
}
}
//below declairations and functions are for BTREE As it is printing for any order :P
int A[100];
class queue
{
public:
btnode*  a[10000];
int rear;
int front ;
int size;
queue ()
{size=100;rear =-1;front =-1;}
void enQ (btnode* x);
btnode* deQ();
int isempty ();
};
//following function is different from usual inorder ,I m storing inorder sequence of pointer in an array A  
void inorder (btnode* t) 
{
static int h=0;
	if (t!=NULL)  
	{
		for (int i=0; i<t->counter;i++)
		{
		inorder (t->ptrs[i]);
		A[h++]=t->key[i];
		}
		inorder (t->ptrs[t->counter]);
	}
}
int xcord (int key)
{int i=0;int x=2;
while (A[i]!=key)
{x=x+2;i++;
}
return x;
}

void print (btnode *t)
{

queue q;

inorder (t);

q.enQ (t);

inorder (t);
btnode *l=new btnode(0);
l->key[0]=-1;
q.enQ (l);
btnode *a;
a=q.deQ();
while (1)
{

	if (a==l)
	{if (!q.isempty())
	    {cout<<endl<<endl;
	    q.enQ(l);
		}

	else {cout<<endl;break;}
	a=q.deQ();
	}


	else if(a!=l)
	 {int k=0;int flag=0;
		for (int j=0;j<100;j++)
		{	
			
			
			
			if (j==xcord(a->key[k]))
			{flag=1;
			cout<<"\033[7;37m"<<"\033[1m"<< setw(2)<<a->key[k]<<"\033[0m";
				if (a->ptrs[k]!=NULL)
				q.enQ (a->ptrs[k]);
			k++;
				if (k==a->counter)
				{	if (a->ptrs[a->counter]!=NULL)
					q.enQ(a->ptrs[a->counter]);	
					a=q.deQ();k=0;flag=0;
					if (a==l)
					break;
				}			
			}
			else {if (flag==0)
				cout<<"  ";
				else cout<<"\033[7;37m"<<"\033[1m"<<"  ";
				}
		}
	}
}

}
int main ()
{
btnode *t;
t=new btnode(1);
cout<< "enter datas to create the B TREE,enter 0 to finish\n";
int k=0;
cin>>k;
while (k!=0)
{
insert(t,t,k);
cin>>k;
}
print (t);
return 0;
}

void queue::enQ (btnode* x)
{	
	rear++;a[rear]=x;

	 if (front==-1)
	front++;
	
}
btnode*  queue::deQ()
{if (isempty())
cout<< "already empty!\n";
else	{
	btnode* temp=a[front];
	if(front==rear)
	{front=-1;rear=-1;}
	else front++;

	return temp;
	}
}
int queue::isempty()
{
if (rear==-1)
return  1;
else return 0;
}


