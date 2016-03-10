#include "elevator_logic_subclass.h"
#include <stdlib.h>

int numElevators = 0;
int outsideCall = 0;


ElevatorLogicSubclass::ElevatorLogicSubclass(Elevator **es, int ecount) {
	numElevators = ecount;
	
}

void ElevatorLogicSubclass::call(int floor, ButtonDirection dir) {
	outsideCall = floor;
	Elevator closest = closestElevator(*e, floor);
	if(closest->getCurrentFloor() < floor) {
		closest->setMotorDirection(UP);
	} else {
		closest->setMotorDirection(DOWN);
	}
}

void ElevatorLogicSubclass::selectFloor(Elevator *e, int floor) {
	if(e->getCurrentFloor < floor) {
		e->setMotorDirection->UP;
	} else if(e->getCurrentFloor > floor) {
		e->set<MotorDirection->DOWN;
	} 
}

void ElevatorLogicSubclass::notifyFloorChanged(Elevator *e, int floorBefore, int floorAfter) {
	
}

MotorDirection ElevatorLogicSubclass::elevatorDirection(Elevator *e) {
	return e->getMotorDirection();
}

bool ElevatorLogicSubclass::checkFloorStatus(Elevator *e){
	MotorDirection direction = e->getMotorDirection();	
	int floor = e->getCurrentFloor();

	if(	);
return false;	
}  

void ElevatorLogicSubclass::optimalElevatorPositions() {

}

Elevator ElevatorLogicSubclass::closestElevator(Elevator *e, ButtonDirection dir) {
	int floors[] = int[numElevators];
	for(int i = 0; i < numElevators; i++) {
		if(e[i]->getMotorDirection() == dir) {		
			if(dir == UP) {
				if(e[i]->getCurrentFloor < outsideCall) {
					floors[i] = e[i]->getCurrentFloor();
				}
			} else if(dir == DOWN) {
				if(e[i]->getCurrentFloor > outsideCall) {
					floors[i] = e[i]->getCurrentFloor();
				}
			} else {
				floors[i] = NULL;	
			} 
		} else if(e->isHalted()) {
			floors[i] = e[i]->getCurrentFloor();
		} else {
			floors[i] = NULL;
		}
	}
	
	int closestElevator = e[0];
	int distance = 2147483646;
	for(int i = 0; i < numElevators; i++) {	
		if(floors[i] != NULL && abs(floors[i] - outsideCall) < distance) {
			closestElevator = e[i];
			distance = abs(floors[i] - outsideCall);
		}
	}

	return closestElevator;
}















