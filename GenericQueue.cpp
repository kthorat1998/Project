#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node*next;
};

template<class T>
class Queue
{
	public :
	struct node<T>* head;
	int iCount;
	
    Queue();
	void Enqueue(T);  //insertlast
	void Dequeue();  //Deletefirst
	void Display();
	int CountNode();	
};

template<class T>
Queue<T>::Queue()
{
	head=NULL;
	iCount=0;
}


template<class T>
void Queue<T>::Enqueue(T iNo) //insertLAST 
{
	struct node<T>* newn=new node<T>;
	newn->data=iNo;
	newn->next=NULL;
	if(iCount==0)
	{
		head=newn;
	}
	else
	{
		struct node<T>* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	  
	  iCount++;
}

template<class T>
void Queue<T>::Dequeue()  //delete first
{
	if(iCount==0)
	{
		cout<<"Stack is empty"<<endl;
		return ;
	}
	T no;
	no=head->data;
	struct node<T>* temp=head;
	head=head->next;
	delete temp;
	
	iCount--;
	cout<<"Removed element is:"<<no<<endl;
}

template<class T>
void Queue<T>::Display()
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
int Queue<T>::CountNode()
{
	return iCount;
}

int main()
{
	Queue<int> obj;
	
	obj.Enqueue(101);
	obj.Enqueue(51);
	obj.Enqueue(21);
	obj.Enqueue(11);
	
	obj.Display();
	int iRet=obj.CountNode();
	cout<<"Number of node in Queue are:"<<iRet<<endl;
	
	
	obj.Dequeue();
	obj.Dequeue();
	
	obj.Display();
	iRet=obj.CountNode();
	cout<<"Number of node in Queue are:"<<iRet<<endl;
	
	return 0;
}