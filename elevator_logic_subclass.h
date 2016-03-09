#ifndef ELEVATOR_LOGIC_SUBCLASS
#define ELEVATOR_LOGIC_SUBCLASS

#include "elevator_logic.h"

class ElevatorLogicSubclass : public ElevatorLogic {
public:
	void call(int floor, ButtonDirection dir);
	void selectFloor(Elevator *e, int floor);
	void notifyFloorChanged(Elevator *e, int floorBefore, int floorAfter);
};

#endif
