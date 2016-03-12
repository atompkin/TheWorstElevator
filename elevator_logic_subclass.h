#ifndef ELEVATOR_LOGIC_SUBCLASS
#define ELEVATOR_LOGIC_SUBCLASS

#include "common_defs.h"
#include "elevator_logic.h"
#include "elevator.h"

class ElevatorLogicSubclass : public ElevatorLogic {
public:
	ElevatorLogicSubclass(Elevator **es, int ecount);
	void call(int floor, ButtonDirection dir);
	void selectFloor(Elevator *e, int floor);
	void notifyFloorChanged(Elevator *e, int floorBefore, int floorAfter);
	void getToMiddle(Elevator *e);
	MotorDirection elevatorDirection(Elevator *e);
	Elevator* closestElevator(ButtonDirection dir);
	bool checkFloorStatus(Elevator *e);
	void optimalElevatorPositions();

};

#endif
