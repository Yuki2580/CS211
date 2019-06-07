/********
Yuki Tagawa 
CS211
hw2-restaurantReservations.cpp
Create Reservations at Restaurants
*********/

#include <iostream>
#include <cmath>
#include "reservation.h"
#include "restaurant.h"
#include "restaurantReservations.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;


//Constructor
restaurantReservations::restaurantReservations()
{
}



void restaurantReservations::ProcessTransactionFile(string fileName)
{
  string command, rName, rAddress, rCity, rType, cName, cPhone;
  int rCapacity, rGroup, rTime;
  long rNum;
  ifstream inputFile;
  inputFile.open(fileName.c_str());   //open file
  while(inputFile>>command)           //In loop, clasify commands
    {
      if(command=="CreateNewRestaurant")
	{
	  inputFile>>rName>>rAddress>>rCity>>rType>>rCapacity;
	  CreateNewRestaurant(rName, rAddress, rCity, rType, rCapacity);  
	}

      else if(command=="PrintAllRestaurants")
	{
	  PrintAllRestaurant();
	}       
      else if(command=="FindTable")
	{
	  inputFile>>rCity>>rType>>rGroup>>rTime;
	  FindTable(rCity, rType, rGroup, rTime);
	}
      else if(command=="MakeReservation")
	{
	  inputFile>>rName>>cName>>cPhone>>rGroup>>rTime;
	  MakeReservation(rName, cName, cPhone, rGroup, rTime);
	}
      else if(command=="CancelReservation")
	{
	  inputFile>>rName>>rNum;
	  CancelReservation(rName, rNum);
	}
      else if(command=="FindTableAtRestaurant")
	{
	  inputFile>>rName>>rGroup;
	  FindTableAtRestaurant(rName, rGroup);
	}
      else if(command=="PrintRestaurantReservations")
	{
	  inputFile>>rName;
	  PrintRestaurantReservations(rName);
	}
    }
  inputFile.close();
}


void restaurantReservations::CreateNewRestaurant(string rName, string rAddress, string rCity, string rType, int rCapacity)
{
  Restaurant rest(rName, rAddress, rCity, rType, rCapacity);  //call constructor
  restaurants.push_back(rest);   //add a restaurant to vector

}


void restaurantReservations::PrintAllRestaurant()
{
  string p, r, s, k;
  int t, h, l;

  cout<<"Restaurant"<<setw(23)<<"Address, City"<<setw(20)<<"Type"<<setw(17)<<"Capacity"<<endl;
  cout<<"----------------------------------------------------------------------"<<endl;

  for(int i=0; i<restaurants.size(); i++)  //Print each element by using loop
    {
      s=restaurants[i].getRestaurantName();
      p=restaurants[i].getRestaurantAddress();
      r=restaurants[i].getRestaurantCity();
      k=restaurants[i].getRestaurantType();
    
      //adjusting table's space
      t=s.size()-10;
      h=(p.size()+r.size())-25;
      l=k.size()-8;
      

      cout<<restaurants[i].getRestaurantName()<<setw(27-t+h)<<restaurants[i].getRestaurantAddress()<<", "<<restaurants[i].getRestaurantCity()<<setw(10-h+l)<<restaurants[i].getRestaurantType()<<setw(11)<<restaurants[i].getCapacity()<<endl;
    }
  cout<<endl;
}


void restaurantReservations::FindTable(string rCity, string rType, int rGroup, int rTime)
{
  bool target=false;   //By using bool, print true statement or false statement

  cout<<"FindTable "<<rCity<<" "<<rType<<" "<<rGroup<<" "<<rTime<<endl;

  //By using loop, check restaurants
  for(int i=0, p=0; i<restaurants.size(); i++)
    {
      if(restaurants[i].getRestaurantCity()==rCity)  //check city
	{

	  if(restaurants[i].getRestaurantType()==rType&&p==0 )  //check type
	    {
	      if(restaurants[i].checkTime(rGroup, rTime, restaurants[i].getRestaurantName()))  //using function type bool then check available seat
		{
		cout<<"You may reserve a table for "<<rGroup<<" at "<<rTime<<" pm at:"<<endl;		
		cout<<restaurants[i].getRestaurantName()<<endl;
		p++;
		target=true;
	      }
	    } 

	  else if(restaurants[i].getRestaurantType()==rType&&p>0 )  //check type and not first restraunt
	    {
	      if(restaurants[i].checkTime(rGroup, rTime, restaurants[i].getRestaurantName())){
		cout<<restaurants[i].getRestaurantName()<<endl;
		target=true;
	      }
	    }
	}	  
	
      else if(target==false&&i==restaurants.size()-1) //case of not finding it
	{
	  cout<<"No restaurant can accommodate such a group at this time, check another time"<<endl;
	}
    }
      cout<<endl;
}


void restaurantReservations::FindTableAtRestaurant(string rName, int rGroup)
{
  for(int i=0; i<restaurants.size(); i++)
    {
      if(restaurants[i].getRestaurantName()==rName) //check name
	{	 
	  restaurants[i].checkGroup(rGroup, restaurants[i].getRestaurantName());  //call function
	}
    }  
}


void restaurantReservations::MakeReservation(string rName, string cName, string cPhone, int rGroup, int rTime)
{
  for(int i=0; i<restaurants.size(); i++)
    {
      if(restaurants[i].getRestaurantName()==rName)
	{
	  if(rTime==5) //check capacity 
	    {
	      if(restaurants[i].getCapacity()>=0)
		{
		  reservation rS(cName, cPhone, rGroup, rTime);  //make reservation
		  restaurants[i].adjustSeats(rGroup, rTime);
		  restaurants[i].addReservation(rS);   //call function
		}
	         
	    }
	  else if(rTime==6) //check capacity
            {
              if(restaurants[i].getCapacity2()>=0)
                {
                  reservation rS(cName, cPhone, rGroup, rTime);  //make reservation                                                                           
		  restaurants[i].adjustSeats(rGroup, rTime);
		  restaurants[i].addReservation(rS);   //call function         
                }	      
            }
	  else if(rTime==7) //check capacity
            {
              if(restaurants[i].getCapacity3()>=0)
                {
                  reservation rS(cName, cPhone, rGroup, rTime);  //make reservation                                                                           
		  restaurants[i].adjustSeats(rGroup, rTime);
		  restaurants[i].addReservation(rS);   //call function         
                }
            }
	  else if(rTime==8) //check capacity
            {
              if(restaurants[i].getCapacity4()>=0)
                {
                  reservation rS(cName, cPhone, rGroup, rTime);  //make reservation                                                                           
		  restaurants[i].adjustSeats(rGroup, rTime);
		  restaurants[i].addReservation(rS);   //call function         
                }
            }
	} 	  
    }
}



void restaurantReservations::CancelReservation(string rName, long rNum)
{
  for(int i=0; i<restaurants.size(); i++)
    {
      if(restaurants[i].getRestaurantName()==rName)
	{
	  restaurants[i].deleteReservation(rNum);   //call function
	}
    }
}

void restaurantReservations::PrintRestaurantReservations(string rName)
{
  cout<<"PrintRestaurantReservations "<<rName<<endl;

  //check whether the name of the restaurant exists
  for(int i=0; i<restaurants.size(); i++)
    {
      if(restaurants[i].getRestaurantName()==rName)
        {
	  cout<<"Reservation"<<setw(9)<<"Contact"<<setw(11)<<"Phone"<<setw(18)<<"Group"<<setw(6)<<"Time"<<endl;
	  cout<<"-----------------------------------------------------------"<<endl;
	  restaurants[i].printReservation();
	  break;
	}
      else if(i==restaurants.size()-1&&restaurants[i].getRestaurantName()!=rName)
	{
	  cout<<"Not exist"<<endl;
	}
    }
  cout<<endl;
}

