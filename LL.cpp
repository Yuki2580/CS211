/**********************************

Name:         Yuki Tagawa
Date:         4/22/2019
Course:       CS211
Assignment:   HW4

Purpose:      The purpose of this program is to make correct linked list by using many kinds of fuctions.

*******************************/

#include "LL.h"
#include "node.h"
#include <string>
#include <cmath>

using namespace std;

/********************************************
Defalut constructor assaigns head to nullptr
********************************************/
LL::LL()
{
  head = nullptr;
  Node * next;
}


/****************************************************
Destructor uses a private function and delete pointers
******************************************************/
LL::~LL()
{
  destroy();
}


/************************************************:
Apend function add a new Node to the last position
***************************************************/
void LL::append(string pName, string phone)
{
  Node* newNode=new Node;
  Node* nodeptr;
  newNode->name=pName;
  newNode->phoneNumber=phone;
  
  if(head==nullptr)
    {
      head=newNode;
    }
  else
    {
      nodeptr=head;
      while(nodeptr->next)
	{
	  nodeptr=nodeptr->next;
	}
      nodeptr->next=newNode;
    }
}


/********************************************************
Print function prints All of te node by using traversing
******************************************************/
void LL::print()
{
  Node* nodeptr; 
  nodeptr=head;
  int count=1;
  if(nodeptr!=nullptr)
    {
      cout<<count<<". "<<nodeptr->name<<" "<<nodeptr->phoneNumber<<endl;
      while(nodeptr->next)
	{
	  nodeptr=nodeptr->next;
	  count++;
	  cout<<count<<". "<<nodeptr->name<<" "<<nodeptr->phoneNumber<<endl;
	}
    }
}


/***********************************************************************
InsertAtBegin function inserts new Node, 
pName and phone to the first node
*************************************************************************/
void LL::insertAtBegin(string pName, string phone)
{
  Node * nodeptr=head;
  Node * newNode=new Node;
  newNode->name=pName;
  newNode->phoneNumber=phone;  
  head=newNode;
  newNode->next=nodeptr;
}


/*********************************************
searchByName function searchs name in a node is pName
then print the position of the node
 *******************************************/
void LL::searchByName(string pName)
{
  bool status=false;
  Node * nodeptr=head;
  int count=1;
  
  if(nodeptr->name==pName)
    {
      cout<<pName<<": Position "<<count<<endl;
      status=true;
    }
  while(nodeptr->next)
    {
      if(nodeptr->name==pName)
	{
	  status=true;
	  break;
	}
      count++;
      nodeptr=nodeptr->next;
    }
  if(nodeptr->name==pName&&nodeptr->next==nullptr)
    {
      cout<<pName<<": Position "<<count++<<endl;
      status=true;
    }
  if(status==false)
    cout<<pName<<": Can't find it"<<endl;
  if(status==true&&nodeptr->next!=nullptr)
    cout<<pName<<": Position "<<count++<<endl;
}


/************************************************
The function does that deep copy of another list
**************************************************/ 
LL::LL(const LL& source)
{
  Node* temp=source.head;
  Node* newNode=new Node;
  Node* nodeptr;
  newNode->name=temp->name;
  newNode->phoneNumber=temp->phoneNumber;
  head=newNode;
 
  temp=temp->next;
  
  nodeptr=head;
  while(temp!=nullptr)
    {
      nodeptr->next= new Node;
      nodeptr=nodeptr->next;
      nodeptr->name=temp->name;
      nodeptr->phoneNumber=temp->phoneNumber;
      
      temp=temp->next;
    }
}


/*********************************************
This function checks whether one list is equal 
to another list or not
*********************************************/
bool LL::operator == (const LL& L1)
{
  bool status=true;
  Node* nodeptr=head;
  Node* nodeptr2=L1.head;
  while(nodeptr2->next!=nullptr)
    {
      if(nodeptr->name==nodeptr2->name && nodeptr->phoneNumber==nodeptr2->phoneNumber)
	{
	  nodeptr=nodeptr->next;
	  nodeptr2=nodeptr2->next;
	}
      else
	{
	  status=false;
	  return status;
	}
    }
  return status;
}


/******************************************
The destroy function deletes all of nodes
******************************************/
void LL::destroy()
{
  Node * nodeptr;
  Node * nextNode;
  nodeptr=head;
  while(nodeptr!=nullptr)
    {
      nextNode=nodeptr->next;
      delete nodeptr;
      nodeptr=nextNode;
    }

}


/******************************************
The readFromArrays function assigns new node 
from the array of name and phoneNumber
******************************************/
void LL::readFromArrays(string nArr[], string pArr[], int size)
{
  Node * newNode=new Node;
  newNode->name=nArr[0];
  newNode->phoneNumber=pArr[0];
  head=newNode;  

  Node * nodeptr=head;
  for(int i=0; i<size; i++)
   {
     nodeptr->name=nArr[i];
     nodeptr->phoneNumber=pArr[i];
   
     if(i!=size-1)
       {
  	  nodeptr->next=new Node;
  	  nodeptr=nodeptr->next;
       }
     else
       {
	 break;
       }   
   }
}


/*******************************************************
This insert function inserts a node in alphabetical order
*********************************************************/
void LL::insert(string pName, string phone)
{  
  bool status=false;
  string array[26]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  int x=0;
  int y=0;
  int z=0;
  int t=0;
  string a;
  string b;
  string c;
  string d;
  b=pName[0];

  for(int i=0; i<26; i++)
    {
      if(array[i]==b)
	x=i;
    }

  Node * nodeptr;
  Node * temp;
  Node * newNode=new Node;
  newNode->name=pName;
  newNode->phoneNumber=phone;
  
  if(head==nullptr)
    {
      head=newNode; 
      status=true;
    }
  else
    {
      nodeptr=head;
      while(nodeptr->next!=nullptr)
	{
	  temp=nodeptr->next;
	  a=temp->name[0];
	  for(int i=0; i<26; i++)
	    {
	      if(array[i]==a)
		y=i;
	    }
	  c=nodeptr->name[0];
	  for(int i=0; i<26; i++)
            {
	      if(array[i]==c)
		z=i;
            }

	  if(y>x && x>z)
	    {
	      nodeptr->next=newNode;
	      nodeptr=nodeptr->next;
	      nodeptr->next=temp;
	      status=true;
	      break;
	    }
	  else if(z>x)
	    {
	      temp=head;
	      head=newNode;
              head->next=temp;
	      status=true;
	      break;
	    }
	  nodeptr=nodeptr->next;
	}

      if(nodeptr->next==nullptr && status!=true)
	{
	  d=nodeptr->name[0];
          for(int i=0; i<26; i++)
            {
              if(array[i]==d)
                t=i;
            }
	  if(t>x)
	    {
	      temp=nodeptr;
	      head=newNode;
              head->next=temp;
	    }
	  else
	    {
	      nodeptr->next=newNode;
	    }      
	}
    }
}


/**************************************************
The function insetrs new node to the position of pos
****************************************************/
void LL::insertAtPos(string pName, string phone, int pos)
{
  Node * nodeptr;
  Node * previous;
  Node * temp;
  Node * newNode=new Node;
  newNode->name=pName;
  newNode->phoneNumber=phone;
  int count=1;
  nodeptr=head;
  
  if(pos==1)
    {
      temp=head;
      head=newNode;
      head->next=temp;
    }
  else
    {
      while(count!=pos-1)
	{
	  nodeptr=nodeptr->next;
	  count++;
	}

      if(count==pos-1 && nodeptr->next!=nullptr)
	{
	  temp=nodeptr->next;
	  previous=nodeptr;
	  nodeptr->next=newNode;
	  nodeptr=nodeptr->next;
	  nodeptr->next=temp;
	  
	}
      else if(count==pos-1 && nodeptr->next==nullptr)
	{
	  nodeptr->next=newNode;
	}
    }
}
  

/*********************************************
The function prints the list in reverse order
*********************************************/
void LL::printReverse()  
{    
  Node * nodeptr=head;
  Node * nodeptr2=head;
  int count2 = 1;
  int count = 1;
  int count3 = 1;
  if (head == NULL)  
    return;
  else
    {
      while(nodeptr->next!=nullptr)
	{
	  count++;
	  nodeptr=nodeptr->next;
	}
      while(count!=0)
	{
	  while(count2!=count)
	    {
	      count2++;
	      nodeptr2=nodeptr2->next;
	    }
	  if(count2==count)
	    {
	      
	      cout<<count3<<". "<<nodeptr2->name<<" "<<nodeptr2->phoneNumber<<endl;
	      nodeptr2=head;
	      count2=1;
	      count3++;
	      count--;
	    }
	}
    }
}



/*******************************************************************************
The function changes the phoneNumber by searchinng the name of the node is pName
*******************************************************************************/ 
void LL::updateNumber(string pName, string newPhone)
{
  bool status=false;
  Node * nodeptr=head;

  if(nodeptr->name==pName)
    {
      nodeptr->phoneNumber=newPhone;
      status=true;
    }
  while(nodeptr->next)
    {
      if(nodeptr->name==pName)
        {
          status=true;
	  nodeptr->phoneNumber=newPhone;
          break;
        }
      nodeptr=nodeptr->next;
    }
  if(nodeptr->name==pName&&nodeptr->next==nullptr)
    {
      nodeptr->phoneNumber=newPhone;
      status=true;
    }
  if(status==false)
    cout<<pName<<" "<<"Can't find it"<<endl<<endl;
}


/************************************************
The operator does deep copy
***********************************************/
LL& LL::operator=(const LL& source)
{
  destroy();
  Node* temp=source.head;
  Node* newNode=new Node;
  Node* nodeptr;
  newNode->name=temp->name;
  newNode->phoneNumber=temp->phoneNumber;
  head=newNode;

  temp=temp->next;

  nodeptr=head;
  while(temp!=nullptr)
    {
      nodeptr->next= new Node;
      nodeptr=nodeptr->next;
      nodeptr->name=temp->name;
      nodeptr->phoneNumber=temp->phoneNumber;

      temp=temp->next;
    }
}


/***********************************************
The function deletes a node which name is pName
***********************************************/
void LL::removeRecord(string pName)
{
  bool status=false;
  Node * nodeptr=head;
  Node * temp;
  Node * previous;

  if(nodeptr->name==pName)
    {
      temp=nodeptr->next;
      delete nodeptr;
      head=temp;
      status=true;
    }
  else
    {
      while(nodeptr->next!=nullptr) 
	{      
	  if(nodeptr->next->name==pName && nodeptr->next->next!=nullptr)
	    {
	      if(nodeptr->next->next==nullptr)
		{
		  delete nodeptr->next;
		  nodeptr->next=nullptr;
		  status=true;
		  break;
		}
	      else
		{
		  previous=nodeptr;
		  temp=nodeptr->next->next;
		  delete nodeptr->next;
		  previous->next=temp;
		  status=true;  
		  break;
		}
	    }
	  else if(nodeptr->next->name==pName && nodeptr->next->next==nullptr)
	    {
	      temp=nodeptr;
	      delete nodeptr->next;
	      temp->next=nullptr;
	      status=true;
	      break;
	    }
	  nodeptr=nodeptr->next;
	}
    }
  if(status==false)
    cout<<pName<<" "<<"Can't delete it"<<endl<<endl;
}


/*********************************************
The function changes the order to reverse order
**********************************************/
void LL::reverse()
{ 
  Node * nodeptr = head; 
  Node * previous = nullptr;
  Node * nextNode = nullptr; 
  
  
  while(nodeptr!=nullptr) 
    {
      nextNode = nodeptr->next; 
      nodeptr->next = previous; 
      previous = nodeptr; 
      nodeptr = nextNode; 
    } 

  head = previous; 
} 
