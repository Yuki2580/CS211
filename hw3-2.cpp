/*****************
Name:        Yuki Tagawa
Date:        3/29/19
Course:      CS211
Assignment:  HW3 Problem 2-e

Purpose:    This programs searches permutations of letters by using recursively. 
*****************/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//prototype
void permute(const string, int, vector<string> &);


/********************************************
In main function, intialize each attribute and call recursive function. 
Then, after returing, print it. 
******************************************/
int main()
{
  vector<string> k;
  string str1, str2;
  int x=str1.size();

  cout << "Enter string: ";
  getline(cin, str1);
 
  permute(str1, 1, k);
 
  for(int i=0; i<k.size(); i++)
      cout<<k[i]<<endl;
}




/***************************************
The function is a recursive function. This function inserts a letter inside string.
We start from one letter to the size of the string by recursively calling the function. 
If we finish inserting a letter, it returns to main function.
**************************************/
void permute(const string str1, int a, vector<string> &k)
{
  if(a==1)
    {      
      string u;
      u=str1[0];
      k.push_back(u);
      if(a==str1.size())
        return;
      else
	return permute(str1, a+1, k);
    }
  else if(a>1)
    {
      if(a==str1.size()+1)
	{
	  return; 
	}
      else
	{
	  int s=k.size();
	  string f[s];

	  for(int i=0; i<s; i++)
	    {
	      f[i]=k[i];
	    }

	  for(int i=0; i<s; i++)
	    {
	      string x=f[i];
	      string e=str1;
	      e=str1.substr(a-1, 1);
	    
	      for(int t=0; t<=x.size(); t++)
		{
		  f[i].insert(t, e);
		  k.push_back(f[i]);
		  f[i]=x;
		}
	  
	      k.erase(k.begin());	       
	    }
	  return permute(str1, a+1, k);
	}
    }
}


