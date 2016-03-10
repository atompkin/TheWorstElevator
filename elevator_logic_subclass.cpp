#include "elevator_logic_subclass.h"
#include <stdlib.h>

int numElevators = 0;
int outsideCall = 0;


ElevatorLogicSubclass::ElevatorLogicSubclass(Elevator **es, int ecount) 
	:ElevatorLogic(es, ecount){
	
	
}

void ElevatorLogicSubclass::call(int floor, ButtonDirection dir) {
	outsideCall = floor;
	Elevator closest = closestElevator(*e, floor);
	if(closest->getCurrentFloor() < floor) {
		closest->setMotorDirection(M_UP);
	} else {
		closest->setMotorDirection(M_DOWN);
	}
}

void ElevatorLogicSubclass::selectFloor(Elevator *e, int floor) {
	if(e->getCurrentFloor < floor) {
		e->setMotorDirection->M_UP;
	} else if(e->getCurrentFloor > floor) {
		e->setMotorDirection->M_DOWN;
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
return false;	
}  

void ElevatorLogicSubclass::optimalElevatorPositions() {

}

Elevator ElevatorLogicSubclass::closestElevator(Elevator *es, ButtonDirection dir) {
	int floors[numElevators];
	for(int i = 0; i < numElevators; i++) {
		if(es[i]->getMotorDirection() == dir) {		
			if(dir == M_UP) {
				if(es[i]->getCurrentFloor < outsideCall) {
					floors[i] = es[i]->getCurrentFloor();
				}
			} else if(dir == M_DOWN) {
				if(es[i]->getCurrentFloor > outsideCall) {
					floors[i] = es[i]->getCurrentFloor();
				}
			} else {
				floors[i] = NULL;	
			} 
		} else if(e->isHalted()) {
			floors[i] = es[i]->getCurrentFloor();
		} else {
			floors[i] = NULL;
		}
	}
	
	Elevator closestElevator = es[0];
	int distance = 2147483646;
	for(int i = 0; i < numElevators; i++) {	
		if((floors[i] != NULL) && (abs(floors[i] - outsideCall) < distance)) {
			closestElevator = es[i];
			distance = abs(floors[i] - outsideCall);
		}
	}

	return closestElevator;
}







