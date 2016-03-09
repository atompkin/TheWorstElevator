#ifndef ELEVATOR_GROUP_SIMULATOR_H
#define ELEVATOR_GROUP_SIMULATOR_H

#include "common_defs.h"

#include <set>

class Elevator;
class ElevatorLogic;
class Passenger;

class ElevatorGroupSimulator {
 private:
  Elevator **es;
  int ecount;
  ElevatorLogic *el;
  int stepCount;
  std::set<Passenger*> passengers;
 public:
  ElevatorGroupSimulator();
  void setElevators(Elevator **es, int ecount);
  int getElevatorCount();
  void setLogic(ElevatorLogic *el);
  void spawnPassenger(int startingFloor, int desiredFloor);
  int getPassengerCountInElevator(Elevator *e);
  void step();
  void runUntilAllHalted();
  void runUntilHalted(Elevator *e);
  void reset();
  int getStepCount();
  int getPassengerCount();
  int getSatisfiedPassengerCount();
  double getAverageCallTime();
  double getAverageInElevatorTime();
  double getAverageSatisfactionTime();
  ~ElevatorGroupSimulator();
};

#endif
