/********
Yuki Tagawa
CS211
hw2
********/

#ifndef RESTAURANTRESERVATIONS_H
#define RESTAURANTRESERVATIONS_H
#include <iostream>
#include <string>
#include "restaurant.h"
#include <vector>

using namespace std;

class Restaurant;

class restaurantReservations 
{
 
 private:
  vector <Restaurant> restaurants; // list of local restaurants
 
 public:
  friend class Restaurant;
  restaurantReservations();
  void ProcessTransactionFile(string fileName);
  void CreateNewRestaurant(string rName, string rAddress, string rCity, string rType, int rCapacity);
  void PrintAllRestaurant();
  void FindTable(string rCity, string rType, int rGroup, int rTime);
  void FindTableAtRestaurant(string rName, int rGroup);
  void MakeReservation(string rName, string cName, string cPhone, int rGroup, int rTime);
  void CancelReservation(string rName, long rNum);
  void PrintRestaurantReservations(string rName);


};

#endif
