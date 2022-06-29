#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node *next;
	struct node *prev;
};

template<class T>
class DoublyCLL
{
	
	private:
	struct node<T>* head;
	struct node<T>* tail;
	int iCount;
	
	public:
	DoublyCLL();
	
	void InsertFirst(T iNo);
	void InsertLast(T iNo);
	void InsertAtPos(T iNo,int iPos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int iPos);
	void Display();
	int CountNode();
	
};

template<class T>
DoublyCLL<T>::DoublyCLL()
	{
		head=NULL;
		tail=NULL;
		iCount=0;
	}
	
	
	template<class T>
	void DoublyCLL<T>:: InsertFirst(T iNo)
	{
		struct node<T>* newn=new node<T>;
		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;
		
		if(iCount==0)
		{
			head=newn;
			tail=newn;
		}
		else
		{
			newn->next=head;
			head->prev=newn;
			head=newn;
		}
		head->prev=tail;
		tail->next=head;
		
		iCount++;
	}
	
	template<class T>
	void DoublyCLL<T>::InsertLast(T iNo)
	{
		struct node<T>* newn=new node<T>;
		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;
		
		if(iCount==0)
		{
			head=newn;
			tail=newn;
		}
		else
		{
			tail->next=newn;
			newn->prev=tail;
			tail=newn;
		}
		head->prev=tail;
		tail->next=head;
		
		iCount++;
	}
	
	template<class T>
	void DoublyCLL<T>::InsertAtPos(T iNo,int iPos)
	{
		if((iPos<1)||(iPos>(iCount+1)))
		{
			cout<<"Invalid Position";
			return ;
		}
		else if(iPos==1)
		{
			InsertFirst(iNo);
		}
		else if(iPos==(iCount+1))
		{
			InsertLast(iNo);
		}
		else
		{
			struct node<T>* newn=new node<T>;
		    newn->data=iNo;
		    newn->next=NULL;
		    newn->prev=NULL;
			struct node<T>* temp=head;
	
			for(int icnt=1;icnt<(iPos-1);icnt++)
			{
				temp=temp->next;
			}
			newn->next=temp->next->next;
			temp->next->prev=newn;
			temp->next=newn;
			newn->prev=temp;
			
			iCount++;
		}
		tail->next=head;
		head->prev=tail;
	}
	
	template<class T>
	void DoublyCLL<T>::DeleteFirst()
	{
		if(iCount==0)
		{
			return ;
		}
		else if(iCount==1)
		{
			delete(head);
			head=NULL;
			tail=NULL;
		}
		else
		{
			struct node<T>* temp=head;
			head=head->next;
			delete(temp);
			
		}
		head->prev=tail;
		tail->next=head;
		
		iCount--;
	}
	
	template<class T>
	void DoublyCLL<T>::DeleteLast()
	{
		if(iCount==0)
		{
			return ;
		}
		else if(iCount==1)
		{
			delete(head);
			head=NULL;
			tail=NULL;
		}
		else
		{
			struct node<T>* temp=head;
			while(temp->next!=tail)
			{
				temp=temp->next;
				
			}
			  delete(tail);
				tail=temp;
				tail->next=head;
				head->prev=tail;
		}
		iCount--;
	}
	
	template<class T>
	void DoublyCLL<T>::DeleteAtPos(int iPos)
	{
		if((iPos<1)||(iPos>iCount))
		{
			cout<<"Invalid Position";
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
			for(int icnt=1;icnt<(iPos-1);icnt++)
			{
				temp=temp->next;
			}
			tempDelete=temp->next;
			temp->next=temp->next->next;
			delete(tempDelete);
			temp->next->prev=temp;
				
			iCount--;
		}
		        tail->next=head;
				head->prev=tail;
	}
	
	template<class T>
	void DoublyCLL<T>::Display()
	{
		struct node<T>* temp=head;
		while(temp!=tail)
		{
			cout<<"|"<<temp->data<<"|<=>";
			temp=temp->next;
		}
		cout<<"|"<<temp->data<<"|<=>";
	}
	
	template<class T>
	int DoublyCLL<T>::CountNode()
	{
		return iCount;
	}
int main()
{
	DoublyCLL<int> obj;
	int iRet=0;
	
	obj.InsertFirst(111);
	obj.InsertFirst(101);
	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	obj.InsertFirst(1);
	obj.Display();
	 iRet=obj.CountNode();
	cout<<"Number of nodes are:"<<iRet<<endl;
	
	obj.InsertLast(111);
	obj.InsertLast(121);
	obj.InsertLast(151);
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