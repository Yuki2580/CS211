/*********
Yuki Tagawa
CS211
hw2-restaurant.h
Create Reservations at Reservations
**********/

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include <vector>
#include "reservation.h"

class Restaurant
{
 private: 
  string restaurantName; 
  string restaurantAddress; 
  string restaurantCity; 
  string restaurantType; 
  int availableSeats [4];
  vector <reservation> reservations;
  
 public:
  Restaurant();
  Restaurant(string rN, string rA, string rC, string rT, int rCapa);
  string getRestaurantName();
  string getRestaurantAddress();
  string getRestaurantCity();
  string getRestaurantType();
  int getCapacity();
  int getCapacity2();
  int getCapacity3();
  int getCapacity4();
  void adjustSeats(int, int);
  void addReservation(reservation);
  void deleteReservation(long);
  void checkGroup(int, string);
  void printReservation() const;
  bool checkTime(int, int, string);

};

#endif
