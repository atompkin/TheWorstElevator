#ifndef PASSENGER_H
#define PASSENGER_H

class Elevator;

class Passenger {
 private:
  int startingFloor;
  int desiredFloor;
  int callTime;
  int selectTime;
  int leaveTime;
  Elevator *e;
  bool satisfied;
 public:
  Passenger(int startingFloor, int desiredFloor, int callTime);
  int getStartingFloor();
  int getDesiredFloor();
  int getCallTime();
  int getSelectTime();
  int getLeaveTime();
  long getId();
  bool isSatisfied();
  Elevator *getElevator();
  void enterElevator(Elevator *e, int selectTime);
  void leaveElevator(int leaveTime);
};

#endif
