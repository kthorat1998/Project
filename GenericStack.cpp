#include<iostream>
using namespace std;

template<class T>
struct node
{
	int data;
	struct node*next;
};

template<class T>
class Stack
{
	public :
	struct node<T>* head;
	int iCount;
	
    Stack();
	void push(T);  //insertFirst
	void pop();  //DeleteLast
	void Display();
	int CountNode();	
};

template<class T>
Stack<T>::Stack()
{
	head=NULL;
	iCount=0;
}

template<class T>
void Stack<T>::push(T iNo)  //InsertFirst(int)=insertfirst
{
	struct node<T>* newn=new node<T>;
	newn->data=iNo;
	newn->next=NULL;
	
	  newn->next=head;
	  head=newn;
	  iCount++;
}

template<class T>
void Stack<T>::pop()//delete first=delete last
{
	if(iCount==0)
	{
		cout<<"Stack is empty"<<endl;
		return ;
	}
	int no;
	no=head->data;
	struct node<T>* temp=head;
	head=head->next;
	delete temp;
	
	iCount--;
	cout<<"Removed element is:"<<no<<endl;
}


template<class T>
void Stack<T>::Display()
{
	struct node<T>* temp=head;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<endl;
}


template<class T>
int Stack<T>::CountNode()
{
	return iCount;
}

int main()
{
	Stack<int> obj;
	
	obj.push(101);
	obj.push(51);
	obj.push(21);
	obj.push(11);
	
	obj.Display();
	int iRet=obj.CountNode();
	cout<<"Number of node in Stack are:"<<iRet<<endl;
	
	
	obj.pop();
	obj.pop();
	
	obj.Display();
	iRet=obj.CountNode();
	cout<<"Number of node in Stack are:"<<iRet<<endl;
	
	
	
	return 0;
}