/*********
Yuki Tagawa
CS211
hw2-main file
Create Reservations at Restaurants
*********/

#include "restaurant.h"
#include "reservation.h"
#include "restaurantReservations.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  restaurantReservations openTable;
  string fileName="TransactionFile.txt";
  openTable.ProcessTransactionFile(fileName);
  return 0;
}
