#include "elevator_logic_subclass.h"
#include "elevator_group_simulator.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int numElevators = 0;
int maxFloors = MAX_FLOORS;
int middleFloor = MAX_FLOORS/2;
int floorCounter = 0;

ElevatorLogicSubclass::ElevatorLogicSubclass(Elevator **es, int ecount) 
	:ElevatorLogic(es, ecount){


}

void ElevatorLogicSubclass::getToMiddle(Elevator *e) {
	floorCounter = 0;
	if(e->getCurrentFloor() != middleFloor) {
		if(e->getCurrentFloor() < middleFloor) {
			e->setMotorDirection(M_UP);
		} else {
			e->setMotorDirection(M_DOWN);
		}	
	} else if(e->getCurrentFloor() == middleFloor) {
		e->setMotorDirection(M_UP);
	}
}

void ElevatorLogicSubclass::call(int floor, ButtonDirection dir) {
	for(int i = 0; i < ecount; i++) {
		getToMiddle(es[i]);
	}
}

void ElevatorLogicSubclass::selectFloor(Elevator *e, int floor) {
	getToMiddle(e);		
}

void ElevatorLogicSubclass::notifyFloorChanged(Elevator *e, int floorBefore, int floorAfter) {
	for(int i = 0; i < ecount; i++) {
		if(es[i]->getCurrentFloor() == MAX_FLOORS) {
			es[i]->setMotorDirection(M_DOWN);
		} else if(es[i]->getCurrentFloor() == 1) {
			es[i]->setMotorDirection(M_HALTED); 
		}		
	}
}


















/**void ElevatorLogicSubclass::call(int floor, ButtonDirection dir) {
	outsideCall = floor;
	Elevator *closest = closestElevator(dir);
	if(closest->getCurrentFloor() < floor) {
		closest->setMotorDirection(M_UP);
	} else {
		closest->setMotorDirection(M_DOWN);
	}
}

void ElevatorLogicSubclass::selectFloor(Elevator *e, int floor) {
	if(e->getCurrentFloor() < floor) {
		e->setMotorDirection(M_UP);
	} else if(e->getCurrentFloor() > floor) {
		e->setMotorDirection(M_DOWN);
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

void ElevatorLogicSubclass::optimalElevatorPositions(){
}

Elevator* ElevatorLogicSubclass::closestElevator(ButtonDirection dir) {
	int floors[numElevators];
	for(int i = 0; i < numElevators; i++) {
		if(es[i]->getMotorDirection() == M_UP && dir == B_UP) {
			if(es[i]->getCurrentFloor() < outsideCall) {
				floors[i] = es[i]->getCurrentFloor();
			} else {
				floors[i] = 2147283646;
			}	

		} else if(es[i]->getMotorDirection() == M_DOWN && dir == B_DOWN) {
			if(es[i]->getCurrentFloor() > outsideCall) {
				floors[i] = es[i]->getCurrentFloor();
			} else {
				floors[i] = 2147283646;
			}	
		} else if(es[i]->isHalted()) {
			floors[i] = es[i]->getCurrentFloor();
		} else {
			floors[i] = 2147283646;
		}

	}

	Elevator *closestElevator = es[0];
	int distance = 2147483646;
	for(int i = 0; i < numElevators; i++) {	
		if((floors[i] != distance) && (abs(floors[i] - outsideCall) < distance)) {
			closestElevator = es[i];
			distance = abs(floors[i] - outsideCall);
		}
	}

	return closestElevator;
}**/







