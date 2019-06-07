/************************************

Name:        Yuki Tagawa
Date:        5/6/2019
Course:      CS211
Assignment:  HW5-2
File:        queue3.cpp
Purpose:     This assignment is for using queue and creating permutations.

************************************/

#include "queue3.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


/******************************                                                
Defining Default Constructor                                                  
****************************/

Queue::Queue()
{
  count=-1;
  front=nullptr;
  rear=nullptr;
}


/*****************************                                                 
Defining Destructor                                                            
****************************/
Queue::~Queue()
{
  QueueNode * temp=nullptr;
  QueueNode  * nodeptr=front;
  while(nodeptr!=rear)
    {
      temp=nodeptr;
      nodeptr=nodeptr->next;
      delete temp;
    }
}


/******************************                                                
enqueue Functions Adds New Queue                                               
*****************************/
void Queue::enqueue(el_t element)
{
  QueueNode * newNode=new QueueNode;
  newNode->letter=element;

  if(isEmpty())
    {
      front=newNode;
      rear=newNode;
    }
  else
    {
      rear->next=newNode;
      rear=rear->next;
    }
  count++;
}

/**********************************                                           
dequeue Function Deletes A Queue                                              
**********************************/
void Queue::dequeue(el_t &element)
{
  QueueNode * temp = nullptr;
  if(isEmpty())
    {
      cout<<element<<" can't dequeue"<<endl;
      return;
    }
  else
    {
      element=front->letter;
      temp=front;
      front=front->next;
      delete temp;
      count--;
    }
}


/********************************                                             
Display Function does print all of the Queues                                  
********************************/
void Queue::displayAll() const
{
  QueueNode * nodeptr=nullptr;
  if(isEmpty())
    {
      cout<<" Nothing"<<endl;
      return;
    }
  else
    {
      if(rear==front)
        {
          cout<<rear->letter<<endl;
        }
      else if(rear>front)
        {
          nodeptr=front;
          while(nodeptr!=rear)
            {
              cout<<nodeptr->letter<<endl;
              nodeptr=nodeptr->next;
            }
          cout<<nodeptr->letter<<endl;
        }

    }
}

/******************************                                                
isEmpty Function returns the empty situation conunt == -1                     
******************************/
bool Queue::isEmpty() const
{
  return count==-1;
}


/********************************                                             
This Function does creating permutations of strings                          
*******************************/
void Queue::printStrings2(string &x)
{
  Queue e;
  int size=x.size();
  int count=0;
  int o=pow(size, size);
  for(int i=0; i<size; i++)
    {
      string p="";
      p+=x[i];
      e.enqueue(p);
      cout<<p<<endl;
    }

  while(o!=count)
    { 
      string box;
      e.dequeue(box);
      if(box.length()<x.length())
	{
	  if(box.size()==x.size()-1)
	    {
	      for(int i=0; i<x.size(); i++)
		{
		  count++;
		  e.enqueue(box+x[i]);
		}
	    }
	  else
	    {
              for(int i=0; i<x.size(); i++)
                {
                  e.enqueue(box+x[i]);
		  cout<<box+x[i]<<endl;
                }
            }	  
	} 
    }    
  e.displayAll();
}



