/*********
Yuki Tagawa
CS211
hw2-reservation.cpp
Create Reservations at Restaurants
*********/

#include "reservation.h"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


//Initialize Static Number
long reservation::nextReservationNum=100;


//Constructor
reservation::reservation()
{
}


//Overloading Constructor
reservation::reservation(string cName, string cPhone, int rGroup, int rTime)
{
  reservationNum=nextReservationNum;
  contactName=cName;
  contactPhone=cPhone;
  groupSize=rGroup;
  reservationTime=rTime;
  nextReservationNum+=10;
}


//Accessors for ReservationNum
long reservation::getReservationNum()
{
  return reservationNum;
}



//Accessors for ReservationGroupSize
int reservation::getGroupSize()
{
  return groupSize;
}


//Accessors for ReservationTime
int reservation::getTime()
{
  return reservationTime;
}



void reservation::print() const
{
  int x=contactName.size();
  int p=x-4;

  if(groupSize>9) //Adjusting tabble
    {
      cout<<reservationNum<<setw(14+p)<<contactName<<setw(21-p)<<contactPhone<<setw(8)<<groupSize<<setw(6)<<reservationTime<<":00"<<endl;
    }
  else
    {
      cout<<reservationNum<<setw(14+p)<<contactName<<setw(21-p)<<contactPhone<<	setw(7)<<groupSize<<setw(7)<<reservationTime<<":00"<<endl;
    }
}
