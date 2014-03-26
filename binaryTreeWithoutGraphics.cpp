#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;


struct bstnode
{
bstnode *lchild;
char data;
bstnode *rchild;
};

bstnode *A[100];

class queue
{
public:
bstnode*  a[10000];
int rear;
int front ;
int size;

queue ()
{size=1000;rear =-1;front =-1;}

void enQ (bstnode* x);
bstnode* deQ();
int isempty ();
bstnode* frontele();
void makeempty();
};


void creatbst (bstnode* &t, char k)
{
if (t==NULL)
{t=new bstnode;
t->data=k;
t->lchild =NULL;
t->rchild =NULL;
}
else if (k<t->data)
{
creatbst (t->lchild,k);
}
else
{creatbst (t->rchild,k);
}
}


void inorder (bstnode *t)
{static int a=0;
if (t!=NULL)
{inorder (t->lchild);
A[a++]=t;
inorder (t->rchild);
}
}


int xcord (bstnode *t)
{int i=0;int x=2;
while (A[i]!=t)
{x=x+2;i++;
}
return x;
}


void print (bstnode *t)
{

queue q,q2;

inorder (t);

q.enQ (t);

inorder (t);
bstnode *l=new bstnode;
l->data=-1;
q.enQ (l);
bstnode *a;
a=q.deQ();
while (1)
{

	if (a==l)
	{if (!q.isempty())
	    {cout<<endl; 
	      for (double y=0;y>-5;y--)
		{
		for (double x=0;x<70;x++)
			{int flag=0;bstnode *F=q2.frontele();bstnode *next=NULL;
			while (next!=F)
			{next=q2.deQ();q2.enQ(next);
			double xs=xcord (next);
			if (next->lchild!=NULL)
			{double xl=xcord (next->lchild);double p=(xs-xl)*(y+5)/5.0+xl;
				if (abs(p-x)<=1)
				{cout<<"\033[7;32m"<<"\033[2;32m"<<" "<<"\033[0m";flag++;
				while (q2.frontele()!=F)
				q2.enQ(q2.deQ());
				}}if (flag!=0) break;
			if (next->rchild!=NULL)
			{double xr=xcord (next->rchild);double p=(xs-xr)*(y+5)/5.0+xr;
				if (abs(p-x)<=1)
				{cout<<"\033[7;32m"<<"\033[2;32m"<<" "<<"\033[0m";flag++;
				while (q2.frontele()!=F)
				{q2.enQ(q2.deQ());}
				}}if  (flag!=0) break;
			next=q2.frontele();
			}if (flag==0)
			cout<<" ";
			}cout<<endl; 
		}
	q2.makeempty();
	q.enQ(l);
	}

	else {cout<<endl;break;}
	a=q.deQ();
	}


	else if(a!=l)
	 {
		for (int j=0;j<70;j++)
		{	if (j==xcord(a))
			{cout<<"\033[7;37m"<<"\033[1m"<< a->data<</*"\033[A"<<"\033[D"<<"\033[D"<<"\033[4;32m"<<"  "<<"\033[B"<<*/"\033[0m";
			q2.enQ(a);
			if (a->lchild!=NULL)
			q.enQ (a->lchild);
			if (a->rchild!=NULL)
			q.enQ (a->rchild);
			a=q.deQ();
			if (a==l)
			break;
			}
			else cout<<" ";
		}

	}
   
    

   

}

delete l;
}
int main ()
{

ifstream fin("file.dat");

bstnode *t=NULL;
char x;
cout<< "\nEnter datas to form a Binary Tree,Enter -1 to Finish:\n";

fin>>x;
while (x!='A')
{
creatbst (t,x);
cout<< endl;

fin>>x;
}

cout<< "One Binary Tree with given data has formed!\n\n";

print(t);
cout<< endl;



return 0;
}





void queue::enQ (bstnode* x)
{	
	rear++;a[rear]=x;

	 if (front==-1)
	front++;
	
}



bstnode*  queue::deQ()
{if (isempty())
cout<< "already empty!\n";
else	{
	bstnode* temp=a[front];
	if(front==rear)
	{front=-1;rear=-1;}
	else front++;

	return temp;
	}
}

bstnode*  queue::frontele()
{if (isempty())
cout<< "empty!\n";
else	{
	bstnode* temp=a[front];
	return temp;
	}
}


void queue::makeempty()
{front=-1;rear=-1;}

int queue::isempty()
{if (rear==-1)
return  1;
else return 0;
}

