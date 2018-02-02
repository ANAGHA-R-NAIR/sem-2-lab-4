#include <iostream>
using namespace std;
struct node// creating a structure node with integer type of data and pointer next
{
int data;
node *next;
};
class stackLL// creating a class for stacks using linked list
{
node *top=new node;// creating a new node
public:
stackLL()// creating a constructor to assign value to node top as NULL
{
top=NULL;
}
void push(int n)// creating a function to insert a new element at the top with data=n
{
node *ptr=new node;
ptr->data=n;
ptr->next=NULL;
if(top!=NULL)
ptr->next=top;
top=ptr;
}
void pop()// creating a function to remove the top element
{
node *temp=new node;
if(top==NULL)
{
cout<<"\nWARNING:Popping out from an empty stack!!!\n";
}
temp=top;
top=top->next;
delete temp;
}
void show()// creating a function to show the elements in the stack
{
node *temp=new node;
temp=top;
while(temp!=NULL)
{
cout<<temp->data<<" ->";
temp=temp->next;
}
cout<<"NULL\n";
}
};
class queueLL
{
node *rear,*front;
public:
queueLL()// creating a constructor to assign value to front and rear pointers as NULL
{
rear=front=NULL;
}
void push(int n)// creating a function to insert a new element
{
node *temp=new node;
temp->data=n;
temp->next=NULL;
if(front==NULL)// for the first element
{
front=temp;
}
else
rear->next=temp;
rear=temp;
}
void pop()// creating a function to remove the last element
{
if(front==NULL)
{
cout<<"\nPopping from an empty queue!!!\n";
return;
}
node *temp=new node;
temp=front;
front=front->next;
delete temp; 
}
void show()// creating a function to show the elements
{
node *temp=new node;
temp=front;
if(front==NULL)
{
cout<<"The Queue is empty";
return;
}
while(temp!=NULL)
{
cout<<temp->data<<" ->";
temp=temp->next;
}
cout<<" NULL";
} 
};

class Stackarray// creating a class for stack with array
{
private:
int A[10];// array A of size 10
int top;
public:
Stackarray()// constructor to assign top as -1 for empty array
{
top = -1;
}
void push(int x)// creating a function to insert the value,here x
{
if(top==9)// if the stack is already full 
{
cout<<"stack overflow\n";
return;
}
A[++top] = x;
}
void pop()// creating a function to remove the top value 
{
if(top == -1) 
{
cout<<"Popping from an empty stack\n";
return;
}
top--;
}
void show()// creating a function to display the elements
{
for(int i = 0;i<=top;i++)
cout<<A[i]<<" ";
cout<<"NULL\n";
}
};
class Queuearray// creating a class for queue with array
{
private:
int B[10];// creating an array A of size 10
int front,rear; 
public:
Queuearray()// constructor to assign front as element 0 and rear as -1
{
front=0;
rear= -1;
}
void push(int x)// creating a function to insert new element
{
if(rear== 9) // if the array is already full
{ 
cout<<"Error: Queue is full\n";
return;
}
B[++rear] = x;
}
void pop()// creating a function to delete last element 
{
if(rear<front) 
{
cout<<"Error: No element to delete\n";
return;
}
front++;
}
void show()// creating a function to display elements 
{
for(int i = front;i<=rear;i++)
cout<<B[i]<<" ";
}
};
int main()
{
stackLL a;
queueLL b;
Stackarray c;
Queuearray d;
int ch;
cout<<"1.Stacks using linked list\n2.Queues using linked list\n3.Stacks using arrays\n4.Queues using arrays";
cin>>ch;
if(ch==1)
{
a.push(4);
a.push(4);
a.push(3);
a.push(2);
a.push(1);
a.show();
a.pop();
a.show();
}
else if(ch==2)
{
b.push(1);
b.push(2);
b.push(3);
b.push(4);
b.show();
b.pop();
b.show();
}
else if(ch==3)
{
c.push(1);
c.push(2);
c.push(3);
c.push(4);
c.show();
c.pop();
c.show();
}
else if(ch==4)
{
d.push(1);
d.push(2);
d.push(3);
d.push(4);
d.show();
d.pop();
d.show();
}
return 0;
}