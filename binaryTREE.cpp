#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include<cstring>
#include<graphics.h>
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
//strcpy(t->data,k);
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

int height(bstnode* t)
{if (t==NULL)
return -1;
else {
	int height_lchild=height(t->lchild);
	int height_rchild=height(t->rchild);

	if (height_lchild>height_rchild)
		return height_lchild+1;
	else return height_rchild+1;
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
{int i=0;
while (A[i]!=t)
{i++;
}
return i*50+15;
}

int ycord(bstnode* T,bstnode* t)
{
int height_tree=height(T);
int height_node=height(t);
int temp=height_tree;
int level=0;
while (temp!=height_node)
{
temp--;
level++;
}
return level*50+50;
}



/*void print (bstnode *t)
{
setbkcolor(BLUE);

int gd = DETECT, gm;
initgraph(&gd,&gm,NULL);
int y=50;
queue q;
q.enQ (t);
inorder (t);
bstnode *l=new bstnode;
q.enQ (l);
bstnode *a;
a=q.deQ();
while (1)
{

	if (a==l)
	{if (!q.isempty())
	    {y+=50; 
	    	q.enQ(l);}

	else {//cout<<endl;
		break;}
	a=q.deQ();
	}


	else if(a!=l)
	 {
		//settextstyle(TRIPLEX_FONT,HORIZ_DIR,1)
		char str[]="t";
		str[0]=a->data;
		outtextxy(xcord(a),y,str);
		circle(xcord(a),y,15);
		//floodfill(xcord(a),ycord(t,a),BLUE);
		if (a->lchild!=NULL)
		{	q.enQ (a->lchild);
			line(xcord(a), y, xcord(a->lchild), y+50);
		}
		if (a->rchild!=NULL)
		{	q.enQ (a->rchild);
			line(xcord(a), y, xcord(a->rchild), y+50);
		}
		a=q.deQ();
	}
 }

delete l;
}
*/

void print(bstnode* t,bstnode* a)
{
if (a!=NULL)
{
print (t,a->lchild);
//cout<<a->data<<" ";
char str[]="t";
str[0]=a->data;
//settextstyle(TRIPLEX_FONT,HORIZ_DIR,1)
outtextxy(xcord(a),ycord(t,a),str);
circle(xcord(a),ycord(t,a),15);
//loodfill(xcord(a),ycord(t,a),12);
int flag=0;
if (a->lchild!=NULL)
{
line(xcord(a), ycord(t,a)+15, xcord(a->lchild), ycord(t,a->lchild)-15);
flag++;}
if (a->rchild!=NULL)
{
flag++;
line(xcord(a), ycord(t,a)+15, xcord(a->rchild), ycord(t,a->rchild)-15);
}

print (t,a->rchild);

}
}
int main ()
{

int gd = DETECT, gm;
initgraph(&gd,&gm,NULL);
//int i,x=10;
//char str[3]="0";
setbkcolor(BLUE);

ifstream fin("file.dat");
bstnode *t=NULL;
char ch;
cout<< "\nEnter datas to form a Binary Tree,Enter -1 to Finish:\n";

cin>>ch;
while (ch!='A')
{
creatbst (t,ch);
cout<< endl;

cin>>ch;
}

cout<< "One Binary Tree with given data has formed!\n\n";
inorder (t);
print(t,t);
cout<< endl;

getch();
closegraph();
return 0;
}
void queue::enQ (bstnode* x)
{	
	rear++;a[rear]=x;

	 if (front==-1)
	front++;
	
}
bstnode*  queue::deQ()
{if (isempty());
//cout<< "already empty!\n";
else	{
	bstnode* temp=a[front];
	if(front==rear)
	{front=-1;rear=-1;}
	else front++;

	return temp;
	}
}

bstnode*  queue::frontele()
{if (isempty());
//cout<< "empty!\n";
else	{
	bstnode* temp=a[front];
	return temp;
	}
}

int queue:: isempty()
{
if (rear==front)
return 1;else return 0;
}
