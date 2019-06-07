/*****************************************

Name:          Yuki Tagawa
Date:          5/6/2019
Course:        CS211
Assignment:    HW5-2 
File:          queue3.h
Purpose:       This assignment is for using queue and creating permutaions

*******************************************/

#ifndef QUEUE3_H
#define QUEUE3_H
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

typedef string el_t;


/************************                                                      
Declaring class Queue                                                         
***********************/
class Queue
{
 private:
  struct QueueNode
  {
    el_t letter;
    QueueNode * next;
  };

  QueueNode * front;
  QueueNode * rear;
  int count;

 public:
  Queue();
  ~Queue();
  void enqueue(el_t);
  void dequeue(el_t &);
  void displayAll() const;
  bool isEmpty() const;
  void printStrings2(string &);
};

#endif
