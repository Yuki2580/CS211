/*********
Yuki Tagawa
CS211
hw2-restaurants.cpp
Create Reservations at Restaurants
*********/

#include "restaurant.h"
#include "reservation.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


//Default Constructor
Restaurant::Restaurant()
{}


//Overloading Constructor
Restaurant::Restaurant(string rN, string rA, string rC, string rT, int rCapa)
{
  restaurantName=rN;
  restaurantAddress=rA;
  restaurantCity=rC;
  restaurantType=rT;
  for(int i=0; i<4; i++)
    {
      availableSeats[i]=rCapa;
    }  
}
  

//Accessors for RestaurantName
string Restaurant::getRestaurantName()
{
  return restaurantName;
}


//Accessors for RestaurantAddress
string Restaurant::getRestaurantAddress()
{
  return restaurantAddress;
}


//Accessors for RestaurantCity
string Restaurant::getRestaurantCity()
{
  return restaurantCity;
}


//Accessors for RestaurantType
string Restaurant::getRestaurantType()
{
  return restaurantType;
}


//Accessors for Available Seats 5pm
int Restaurant::getCapacity()
{
  return availableSeats[0];
}

//Accessors for Available Seats 6pm 
int Restaurant::getCapacity2()
{
  return availableSeats[1];
}

//Accessors for Available Seats 7pm
int Restaurant::getCapacity3()
{
  return availableSeats[2];
}

//Accessors for Available Seats 8pm
int Restaurant::getCapacity4()
{
  return availableSeats[3];
}


//function for adjusting available seats if making a reservation
void Restaurant::adjustSeats(int rGroup, int rTime)
{
  if(rTime==5)
    {
      availableSeats[0]-=rGroup;
    }
  else if(rTime==6)
    {
      availableSeats[1]-=rGroup;
    }
  else if(rTime==7)
    {
      availableSeats[2]-=rGroup;
    }
  else if(rTime==8)
    {
      availableSeats[3]-=rGroup;
    }
}


void Restaurant::addReservation(reservation rs)
{  
  reservations.push_back(rs);   //add a new reservation
}


void Restaurant::deleteReservation(long t)
{
  int x;
  for(int i=0; i<reservations.size(); i++)       //Find Restaurant Number 
    {
      if(reservations[i].getReservationNum()==t)
	{
	  x=reservations[i].getGroupSize();
	  if(reservations[i].getTime()==5)   //5pm reservation seats           
	    {
	      availableSeats[0]+=x;
	    }
	  else if(reservations[i].getTime()==6)  //6pm reservation seats      
	    {
	      availableSeats[1]+=x;
	    }
	  else if(reservations[i].getTime()==7)  //7pm reservation seats      
	    {
	      availableSeats[2]+=x;
	    }
	  else if(reservations[i].getTime()==8)  //8pm reservation seats      
	    {
	      availableSeats[3]+=x;
	    }
	  reservations.erase(reservations.begin()+i); //If we find it, erase 
	}
    }
}


void Restaurant::checkGroup(int s, string p)
{
  //Decrement available seats by new group number
  availableSeats[0]-=s;
  availableSeats[1]-=s;
  availableSeats[2]-=s;
  availableSeats[3]-=s;
    

  //Check whether total seats in each time is over capacity or not
  cout<<"FindTableAtRestaurant "<<p<<" "<<s<<endl;
  if(availableSeats[0]<0&&availableSeats[1]<0&&availableSeats[2]<0&&availableSeats[3]<0)
    cout<<p<<" does not have such availability"<<endl;
  if(availableSeats[0]>=0||availableSeats[1]>=0||availableSeats[2]>=0||availableSeats[3]>=0)
    cout<<"You can reserve a table for "<<s<<" at "<<p<<" at ";
  if(availableSeats[0]>=0)
    cout<<"5:00 pm ";
  if(availableSeats[1]>=0)
    cout<<"6:00 pm ";
  if(availableSeats[2]>=0)
    cout<<"7:00 pm ";
  if(availableSeats[3]>=0)
    cout<<"8:00 pm ";

  //After Checking Fixe the nummber of available seats
  availableSeats[0]+=s;
  availableSeats[1]+=s;
  availableSeats[2]+=s;
  availableSeats[3]+=s;
  cout<<endl;
  cout<<endl;
}

  

void Restaurant::printReservation() const
{
  for(int i=0; i<reservations.size(); i++)
    {
      reservations[i].print();    //call print function in reservation class
    }
}



bool Restaurant::checkTime(int s, int time, string name)
{
  bool p;
  if(reservations.size()==0)  //Check whether there is any reservation
    {
      p=true;
      return p;
    }
  
  else if(reservations.size()>0)  //Case of that there is any reservation
    {
      if(time==5)   //case time 5pm
	{
	  availableSeats[0]-=s;  //decrement available seats by new group   
	  if(availableSeats[0]>=0)
	    {
	      availableSeats[0]+=s;  //fix the number after checking  
	      p=true;
	    }
	  else
	    {
	      availableSeats[0]+=s;  //fix the number after checking  
	      p=false;
	    }
	}
      else if(time==6)  //case time 6pm
	{
	  availableSeats[1]-=s;  //decrement available seats by new group 
	  if(availableSeats[1]>=0)
	    {
	      availableSeats[1]+=s;  //fix the number after checking  
	      p=true;
	    }
	  else
	    {
	      p=false;
	      availableSeats[1]+=s;  //fix the number after checking  
	    }
	}
      else if(time==7) //case time 7pm
	{
	  availableSeats[2]-=s;  //decrement available seats by new group 
	  if(availableSeats[2]>=0)  
	    {
	      p=true;
	      availableSeats[2]+=s;  //fix the number after checking  
	    }
	  else
	    {
	      availableSeats[2]+=s;  //fix the number after checking  
	      p=false;
	    }
	}
      else if(time==8)  //case time 8pm
	{
	  availableSeats[3]-=s;  //decrement available seats by new group
	  if(availableSeats[3]>=0)
	    {
	      availableSeats[3]+=s;  //fix the number after checking
	      p=true;
	    }
	  else
	    {
	      availableSeats[3]+=s;  //fix the number after checking
	      p=false;
	    }
	}
    }
  return p;
}
