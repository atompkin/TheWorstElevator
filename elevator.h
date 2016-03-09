#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "common_defs.h"

#include <cassert>
#include <list>
#include <iostream>
#include <string>

class Elevator {
 private:
  std::string name;
  int currentFloor;
  MotorDirection motorDirection;
  std::list<int> log;

 public:
  Elevator(std::string name);
  /**
   * Reset currentFloor to 1, set motorDirection to M_HALTED, and clear the log.
   */
  void reset();
  std::string getName();
  std::list<int> &getLog();
  int getCurrentFloor();
  MotorDirection getMotorDirection();
  void setMotorDirection(MotorDirection md);
  bool isHalted();
  void step();
};

#endif
