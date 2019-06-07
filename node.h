/********************************************************************************************************

Name:       Yuki Tagawa
Date:       4/22/2019
Course:     CS211
Assignmet:  HW4

Purpose:    The purpose of this program is to make correct linked list by using many kinds of fuctions.   
   
*********************************************************************************************************/

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


/*****************************
Declaring class Node
*****************************/

class Node
{
  friend class LL;

 private: 
  Node * next;
  string name;
  string phoneNumber;

};

#endif
