/************************************

Name:         Yuki Tagawa
Date:         5/6/2019
Course:       CS211
Assignment:   HW5-1
File:         stack2.cpp
Purpose:      This assignment is for using stack and checking whether delimiters are balanced or not.

**************************************/

#include "stack2.h"
#include <iostream>
#include <cmath>


using namespace std;


/**********************
Destructor
*******************/
Stack::~Stack()
{
  while(top!=nullptr)
    {
      StackNode * temp=top;
      top=top->next;
      delete temp;
    }
}

/**************************
push function does adding new stack
**************************/
void Stack::push(el_t a)
{    
  StackNode * newNode = nullptr; 
  
  newNode = new StackNode;
  newNode->element=a;
  
   if (isEmpty())
     {
       top = newNode;
       newNode->next = nullptr;
     }
   else
     {
       newNode->next = top;
       top = newNode;
     }   
}

/**************************
pop function does deleting a stack
***************************/
void Stack::pop(el_t &b)
{
  StackNode * temp = nullptr;
  
  if(isEmpty())
    {
      cout<<"Overflow"<<endl;
      return;
    }
  else
    {
      b=top->element;
      temp=top->next;
      delete top;
      top=temp;
    }
  
}


/**********************************
This function prints all of the stacks
**********************************/
void Stack::displayAll() const
{
  StackNode * nodeptr= top;
  string x;
  if(isEmpty())
    {
      cout<<"Empty"<<endl;
      return;
    }
  else
    {
      while(nodeptr!=nullptr)
	{
	  cout<<nodeptr->element<<endl;
	  nodeptr=nodeptr->next;
	}
    }
}


/********************************
This function returns situation when Stacks are empty
*******************************/
bool Stack::isEmpty() const
{
  return (top == nullptr);
}

void Stack::getTop(el_t &b) const
{
  StackNode * nodeptr=top;
  b=nodeptr->element;
}


/***************************************
This function does that checking whether delimiters are balanced or not
****************************************/
bool Stack::properlyBalanced(string a)
{
  char c;
  int b=a.size();
  int count=0;
  int count2=0;
  int count3=0;
  bool status=true;
  char x;
  bool check=true;

  for(int i=0; i<b; i++)
    {
      if(a[i]=='[')
	{
	  push(a[i]);
	  count++;
	}
      else if (a[i]==']')
	{
	  if(isEmpty())
	    {
	      count++;
	      status=false;
	    }
	  else
	    {
	      pop(c);
	      count--;
	    }
	}
    }


  for(int i=0; i<b; i++)
    {
      if(a[i]=='{')
        {
          push(a[i]);
	  count2++;
        }
      else if (a[i]=='}')
        {
          if(isEmpty())
            {
	      count2++;
              status=false;
            }
          else
            {
              pop(c);
	      count2--;
            }
        }
    }

  
  for(int i=0; i<b; i++)
    {
      if(a[i]=='(')
	{
	  push(a[i]);
	  count3++;
	}
      else if (a[i]==')')
	{
	  if(isEmpty())
	    {
	      count3++;
	      status=false;
	    }
	  else
	    {
	      pop(c);
	      count3--;
	    }
	}
    }
  
  int total=count+count2+count3;

  if(count==0&&count2==0&&count3==0)
    {
      return true;
    }
  else 
    {
      if(total%2==0)
	cout<<"Mismatch delimiter"<<endl;
      else 
	cout<<"Extra delimiter"<<endl;
    }

  return false;
  
}
  
