/********
Yuki Tagawa
CS211
hw2-reservation.h
Create Reservations at Restaurnats
********/

#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include <vector>

using namespace std;

class reservation
{
 private: 
  long reservationNum;
  string contactName;
  string contactPhone;
  int groupSize;
  int reservationTime;
  static long nextReservationNum;
  
 public:
  reservation();
  reservation(string cName, string cPhone, int rGroup, int rTime);
  long getReservationNum();
  int getGroupSize();
  int getTime();
  void print() const;
  
};



#endif
