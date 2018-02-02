#include<iostream>
using namespace std
class node{// creating a class of node with integer type data and next pointer
	public:
	float data; 
	node* next;
};
class stackll{// class with stack using linkedlist
	public:
	node* bottom, *top; 
	stackll(){// constructor to assign values as NULL
		bottom = NULL;
		top = NULL;
	}
	void push(float data);// function to insert new element
	void pop();// function to delete top element
	void show();// function to display elements
	void mkqu(node* bottom);
	void dlt();// function to
};
class queue{// class for queue using two stacks
	stackll stack1, stack2;// elements of class stackll
	public:
	void push();
	void pop();
	void show();
};
int main(){
	queue one;// an element of class queue	
	one.push();
	one.show();
	one.pop();
	one.show();
	return 0; 
}
 
void stackll::push(float data){
	node* temp =new node;
	temp ->data = data;
	temp->next=NULL;
	if (bottom ==NULL){
		bottom =temp ;
		top =temp;
	}	
	else {
		temp->next=bottom;
		bottom =temp;
	}
}
void stackll::pop(){//function definition
	if (bottom==NULL){
		cout<<"Popping from an empty stack"<<endl;
	}
	else if(bottom==top){
		node* temp =bottom;
		delete temp;
		bottom =NULL;
		top= NULL;
	}
	else {
		node* temp=bottom;
		bottom=bottom->next;
		delete temp;
	}
}
void stackll::show(){// function definition
	node* temp =bottom;
	if(bottom==NULL){
	cout<<"no elements to display"<<endl;
	}
	else {
		while(temp!=top){
		cout<<temp->data<<"->";
		temp=temp->next;	
		}
		cout<<temp->data<<endl;
	}
}
void stackll::mkqu(node* bottom){ 
		node* temp =bottom;
		if(bottom!=NULL){
			while(temp->next!=NULL){
				push(temp->data);
				temp=temp->next;
			}
			push(temp->data);
		}
}	
void stackll::dlt(){
	while(bottom!=NULL){
		pop();
	}	
}


void queue::push(){
	cout<<"Number of data= "<<endl;
	int num,data;
	cin>>num;
	for(int i=0; i<num; i++){
		cout<<"Data"<<i+1<<":";
		cin>>data;
		stack1.push(data);
	}
	stack2.dlt();
	stack2.mkqu(stack1.bottom);
}	
void queue::pop(){
	cout<<"Number of data you want to delete:"<<endl;
	int num;
	cin>>num;
	for(int i=0; i<num; i++){
		stack2.pop();
	}
	stack1.dlt();
	stack1.mkqu(stack2.bottom);
}	
void queue::show(){
	stack1.show();
}