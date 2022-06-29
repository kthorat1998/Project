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
class DoublyDLL
{
	
	private:
	struct node<T>* head;
	int iCount;
	
	public:
	DoublyDLL();
	
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
DoublyDLL<T>::DoublyDLL()
	{
		head=NULL;
		iCount=0;
	}
	
	
	template<class T>
	void DoublyDLL<T>:: InsertFirst(T iNo)
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
			head->prev=newn;
			newn->prev=head;
			head=newn;
		}
		iCount++;
	}
	
	template<class T>
	void DoublyDLL<T>::InsertLast(T iNo)
	{
		struct node<T>* temp=head;
		struct node<T>* newn=new node<T>;
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
			newn->prev=temp;
		}
		iCount++;
	}
	
	template<class T>
	void DoublyDLL<T>::InsertAtPos(T iNo,int iPos)
	{
		if((iPos<1)||(iPos>iCount+1))
		{
			cout<<"Invalid position"<<endl;
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
			int icnt=0;
			struct node<T>* temp=head;
		    struct node<T>* newn=new node<T>;
		    newn->data=iNo;
		    newn->next=NULL;
			
			for(icnt=1;icnt<(iPos-1);icnt++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->prev=newn;
			temp->next=newn;
			newn->prev=temp;
			
			iCount++;
		}
		
	}
	
	template<class T>
	void DoublyDLL<T>::DeleteFirst()
	{
		if(iCount==0)
		{
			return ;
		}
		else if(iCount==1)
		{
			
			delete(head);
			head=NULL;
		}
		else
		{
			struct node<T>* temp=head;
			head=head->next;
			delete(temp);
			head->prev=NULL;
			
		}
		iCount--;
	}
	
	template<class T>
	void DoublyDLL<T>::DeleteLast()
	{
		if(iCount==0)
		{
			return ;
		}
		else if(iCount==1)
		{
			
			delete(head);
			head=NULL;
		}
		else
		{
			struct node<T>* temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
				
			}
			delete(temp->next);
				temp->next=NULL;
		}
		iCount--;
	}
	
	template<class T>
	void DoublyDLL<T>::DeleteAtPos(int iPos)
	{
		if((iPos<1)||(iPos>iCount))
		{
			cout<<"Invalid position"<<endl;
			return ;
		}
		else if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==(iCount))
		{
			DeleteLast();
		}
		else
		{
			struct node<T>* tempDelete=NULL;
			struct node<T>* temp=head;
			int icnt=0;
			for(icnt=1;icnt<(iPos-1);icnt++)
			{
				temp=temp->next;
			}
			tempDelete=temp->next;
			temp->next=temp->next->next;
			delete(tempDelete);
			temp->next->prev=temp;
			
			iCount--;
		}
	}
	
	template<class T>
	void DoublyDLL<T>::Display()
	{
		struct node<T>* temp=head;
		while(temp!=NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}
	}
	
	template<class T>
	int DoublyDLL<T>::CountNode()
	{
		return iCount;
	}
	
	
int main()
{
	DoublyDLL<int> obj;
	
	int iRet=0;
	
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
