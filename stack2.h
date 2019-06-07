/************************************

Name:        Yuki Tagawa
Date:        5/6/2019
Course:      CS211
Assignment:  HW5-1
Purpose:     This assignment is for using stack and checking whether delimiters are balanced or not.

***************************************/


#ifndef STACK2_H
#define STACK2_H
#include <iostream>
#include <cmath>

using namespace std;

typedef char el_t;

/****************************
Declaring class Stack
**************************/
class Stack
{
 private:
  struct StackNode
  {
    el_t element;
    StackNode *next;
  };

  StackNode *top;

 public:
  Stack() { top = nullptr; }
  ~Stack();
  void push(el_t);
  void pop(el_t &);
  void displayAll() const;
  bool isEmpty() const;
  void getTop(el_t &) const;
  bool properlyBalanced(string);
};

#endif
