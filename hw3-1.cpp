/***********************************
Name:        Yuki Tagawa
Date:        3/4/19
Course:      CS211
Assignment:  HW3 Problem 1-c

Purpose:     The purpose of the program is to search that the matching the index is an index whose value equals that of the array at that index. 
**********************************/

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

//prototype
int matchIndex(const vector<int> , int, int);


/******************************************
In the main function, intitializing vector, then call function recursively
*************************************/
int main()
{
  vector<int> x={-20, -15, -10, -8, -7, -6, -5, -3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 16};
  vector<int> y={-40, -20, -1, 1, 2, 3, 5, 7, 9, 12};
  vector<int> z={-5, -3, 2, 5, 6, 7, 8, 9, 15, 16, 20};
  vector<int> t={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
                     
  cout<<matchIndex(x, 0, x.size()-1)<<endl;
  cout<<matchIndex(y, 0, y.size()-1)<<endl;
  cout<<matchIndex(z, 0, z.size()-1)<<endl;
  cout<<matchIndex(t, 0, t.size()-1)<<endl;  

  return 0;
}


/*****************************************
In this function, we do binary search for identifying that the matching the index is an index whose value equals that of the
array at that index.                                            
*****************************************/
int matchIndex(const vector<int> a, int first, int size)
{
  int y;
  int middle=(first+size)/2;
  if(a[middle]==middle)
    {
      return middle;
    }
  else if(middle>size || middle<first)
    {
      return -1;
    }
  else if(a[middle]<middle)
    {	  
      y=matchIndex(a, middle+1, size);
      return y;
    }
  else if(a[middle]>middle)
    {
      y=matchIndex(a, first, middle-1);
      return y;
    }
  
  else 
    return -1;
  
}
