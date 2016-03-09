#ifndef ELEVATOR_LOGIC_H
#define ELEVATOR_LOGIC_H

#include "common_defs.h"

class Elevator;

class ElevatorLogic {
 protected:
  Elevator **es;
  int ecount;
 public:
  ElevatorLogic(Elevator **es, int ecount) {
    this->es = es;
    this->ecount = ecount;
  }
  
  virtual void call(int floor, ButtonDirection dir) = 0;
  virtual void selectFloor(Elevator *e, int floor) = 0;
  virtual void notifyFloorChanged(Elevator *e, int floorBefore, int floorAfter) = 0;
};

#endif
