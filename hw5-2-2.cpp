/***************************************

Name:        Yuki Tagawa
Date:        5/6/2019
Course:      CS211
Assignment:  HW5-2
File:        hw5-2-2.cpp
Purpose:     This assignment is for using queue and creating permutations

******************************************/

#include "queue3.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

/****************************                                                  
Main function calls a function and get correct outputs                       
******************************/

int main()
{
  string x;
  Queue q;
  cout<<"Enter string: ";
  getline(cin, x);
  
  q.printStrings2(x);
  
  return 0;
}
