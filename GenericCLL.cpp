#include<iostream>
using namespace std;

template<class T>

struct node
{
	T data;
	struct node *next;

};

template<class T>
class SinglycLL
{
	
	private:
	struct node<T>* head;
	struct node<T>* tail;
    int iCount;
	
	public:
	SinglycLL();
	
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
SinglycLL<T>::SinglycLL()
	{
		head=NULL;
		tail=NULL;
		iCount=0;
	}
	
	
	template<class T>
	void SinglycLL<T>:: InsertFirst(T iNo)
	{
		struct node<T>* newn=new node<T>;
		newn->data=iNo;
		newn->next=NULL;
		
		if(iCount==0)
		{
			head=newn;
			tail=newn;
		}
		else 
		{
			newn->next=head;
			head=newn;
			
		}
		tail->next=head;
		iCount++;
	}
	
	template<class T>
	void SinglycLL<T>::InsertLast(T iNo)
	{
		struct node<T>* newn=new node<T>;
		newn->data=iNo;
		newn->next=NULL;
		
		if(iCount==0)
		{
			head=newn;
			tail=newn;
		}
		else
		{
			
			tail->next=newn;
			tail=newn;
			newn->next=head;
		}
		tail->next=head;
		iCount++;
	}
	
	template<class T>
	void SinglycLL<T>::InsertAtPos(T iNo,int iPos)
	{
		if((iPos<1)||(iPos>iCount+1))
		{
			cout<<"Invalid Position";
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
		tail->next=head;
	}
	
	template<class T>
	void SinglycLL<T>::DeleteFirst()
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
	tail->next=head;
		iCount--;
	}
	
	template<class T>
	void SinglycLL<T>::DeleteLast()
	{
		struct node<T>* temp=head;
		if(iCount==0)
		{
			return;
		}
		else if(iCount==1) 
		{
			delete(head);
			tail=head;
		}
		else
		{
			while(temp->next!=tail)
			{
				temp=temp->next;
			}
			delete(tail);
			tail=temp;
			
		}
		tail->next=head;
		iCount--;
	}
	
	template<class T>
	void SinglycLL<T>::DeleteAtPos(int iPos)
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
	
	template<class T>
	void SinglycLL<T>::Display()
	{
		struct node<T>* temp=head;
		while(temp!=tail)
		{
			cout<<"|"<<temp->data<<"|->";
			temp=temp->next;
		}
		 cout<<"|"<<temp->data<<"|-> ";
		cout<<endl;
	}
	
	template<class T>
	int SinglycLL<T>::CountNode()
	{
		return iCount;
	}
int main()
{ int iRet=0;
	SinglycLL<int> obj;
	
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
