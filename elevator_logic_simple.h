#ifndef ELEVATOR_LOGIC_SIMPLE
#define ELEVATOR_LOGIC_SIMPLE

#include "common_defs.h"
#include "elevator_logic.h"

class ElevatorLogicSimple : public ElevatorLogic {
 private:
  int targetFloor;
 public:
  ElevatorLogicSimple(Elevator **es, int ecount);
  void call(int floor, ButtonDirection dir);
  void selectFloor(Elevator *e, int floor);
  void notifyFloorChanged(Elevator *e, int floorBefore, int floorAfter);
};

#endif
