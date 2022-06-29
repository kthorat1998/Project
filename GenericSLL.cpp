#include<iostream>

using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
};

template <class T>
class SinglyLL
{
	
	public:
	struct node<T> * head;
     int iCount;
	
	SinglyLL();
	
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T ,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int CountNode();
	
};

template <class T>
SinglyLL<T>::SinglyLL()
	{
		head=NULL;
        iCount=0;
	}
	
	template <class T>
	void SinglyLL<T>:: InsertFirst(T iNo)
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
		newn->next=head;
		head=newn;
	}
	iCount++;
		
	}
	
	template <class T>
	void SinglyLL<T>::InsertLast(T iNo)
	{
		struct node<T>* newn=new node<T>;
		struct node<T>* temp=head;
		newn->data=iNo;
		newn->next=NULL;
		if(iCount==0)
		{
			head=newn;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
		}
		iCount++;
		
	}
	
	template <class T>
	void SinglyLL<T>::InsertAtPos(T iNo,int iPos)
	{
		if((iPos<1)||(iPos>iCount+1))
		{
			cout<<"Invalid POsition";
			return ;
			
		}
		else if(iPos==1)
		{
			InsertFirst(iNo);
		}
		else if(iPos==iCount+1)
		{
			InsertLast(iNo);
		}
		else
		{
			int  icnt=0;
			struct node<T>* newn=new node<T>;
			struct node<T>* temp=head;
			newn->data=iNo;
			newn->next=NULL;
			for(icnt=1;icnt<(iPos-1);icnt++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
			
			iCount++;
			
		}
	}
	
	template <class T>
	void SinglyLL<T>::DeleteFirst()
	{
		struct node<T>* temp=head;
		if(iCount==0)
		{
			return;
		}
		else
		{
			head=temp->next;
			delete(temp);
		}
		iCount--;
	}
	
	template <class T>
	void SinglyLL<T>::DeleteLast()
	{
		struct node<T>* temp=head;
		if(iCount==0)
		{
			return;
		}
		else if(iCount==1) 
		{
			delete(head);
			head=NULL;
		}
		else
		{
			while(temp->next->next!=0)
			{
				temp=temp->next;
			}
			delete(temp->next);
			temp->next=NULL;
		}
		iCount--;
	}
	
	template <class T>
	void SinglyLL<T>::DeleteAtPos(int iPos)
	{
		if((iPos<1)||(iPos>iCount))
		{
			cout<<"Invalid Position"<<endl;
			return ;
		}
		else if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==iCount)
		{
			DeleteLast();
		}
		else
		{
			struct node<T>* temp=head;
		    struct node<T>* tempDelete=NULL;
			int icnt=0;
			for(icnt=1;icnt<(iPos-1);icnt++)
			{
				temp=temp->next;
			}
			tempDelete=temp->next;
			temp->next=temp->next->next;
			delete(tempDelete);
			
		}
	}
	
	template <class T>
	void SinglyLL<T>::Display()
	{
		struct node<T>* temp=head;
		cout<<"data from linked list is:"<<endl;
		while(temp!=0)
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	template <class T>
	int SinglyLL<T>::CountNode()
	{
		return iCount;
	}
int main()
{
	int iRet=0;
	SinglyLL<int> obj;
	
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertFirst(10);
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	obj.InsertFirst(1);
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	obj.InsertLast(111);
	obj.InsertLast(121);
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;


    obj.InsertAtPos(75,3);
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	
	obj.DeleteFirst();
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	obj.DeleteLast();
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	obj.DeleteAtPos(4);
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	return 0;
}
