/***************************************

Name:          Yuki Tagawa
Date:          5/6/2019
Course:        CS211
Assignment:    HW5-1
Purpose:       This assignment is for using Stacks and checking whether delimiters are balanced or not.

*****************************************/

#include "stack2.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/**************************
Main function calls s function and get correct outputs
**************************/
int main()
{
  string element;
  Stack s;
  do
    {
      cout<<"Enter string: ";
      cin >> element;
      if(s.properlyBalanced(element))
	cout << "True, Balanced" << endl;
      else
	cout << "False, Not Balanced"<<endl;
      Stack s;
    }while(element!=" ");


  return 0;
}
