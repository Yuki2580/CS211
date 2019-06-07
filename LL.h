/*******************************************************************************************************
Name:         Yuki Tagawa
Date:         4/22/2019
Course:       CS211
Assignment:   HW4

Purpose:      The purpose of this program is to make correct linked list by using many kinds of fuctions.      

********************************************************************************************************/

#ifndef LL_H
#define LL_H
#include "node.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;



/******************************
Declaring class LL
******************************/

class LL
{
  friend class Node;

 private: 
  Node * head;
  Node * next;
 public:
  LL();
  LL(const LL&);
  ~LL();
  void append(string, string);
  void print();
  void insertAtBegin(string, string);
  void searchByName(string);
  bool operator == (const LL&);
  void destroy();
  void readFromArrays(string [], string [], int);
  void insert(string, string);
  void insertAtPos(string, string, int);
  void printReverse();
  void updateNumber(string, string);
  LL& operator=(const LL&);
  void removeRecord(string pName);
  void reverse();
};

#endif
