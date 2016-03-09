
#include "common_defs.h"
#include "elevator.h"
#include "elevator_logic_simple.h"
#include "elevator_group_simulator.h"
#include <iostream>
#include <initializer_list>
#include <list>
#include <fstream>
using namespace std;

void printLog(list<int> &log) {
  for(list<int>::iterator it = log.begin(); it != log.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

void logsMatch(Elevator *e, initializer_list<int> floors)
{
  list<int> goal;
  for(const int *it = floors.begin(); it != floors.end(); ++it) {
    goal.push_back(*it);
  }
  cout << "Elevator " << e->getName() << " log:     ";
  printLog(e->getLog());
  cout << "Expected log for " << e->getName() << ": ";
  printLog(goal);
  assert(e->getLog() == goal);
  cout << "Passed test." << endl;
}

void printStats(ElevatorGroupSimulator *esim)
{
  cout << "Step count: " << esim->getStepCount() << endl;
  cout << "Passenger count: " << esim->getPassengerCount() << endl;
  cout << "Satisfied passenger count: " << esim->getSatisfiedPassengerCount() << endl;
  cout << "Average call time: " << esim->getAverageCallTime() << endl;
  cout << "Average in elevator time: " << esim->getAverageInElevatorTime() << endl;
  cout << "Average satisfaction time: " << esim->getAverageSatisfactionTime() << endl;
  cout << endl;
}

void writeStats(ElevatorGroupSimulator *esim, int seed, ofstream &f)
{
  f << seed << ",";
  f << esim->getElevatorCount() << ",";
  f << esim->getStepCount() << ",";
  f << esim->getPassengerCount() << ",";
  f << esim->getSatisfiedPassengerCount() << ",";
  f << esim->getAverageCallTime() << ",";
  f << esim->getAverageInElevatorTime() << ",";
  f << esim->getAverageSatisfactionTime() << endl;
}

int main()
{
  ofstream outcsv("elevatorstats.csv");
  assert(outcsv.is_open());
  outcsv << "Seed,ElevatorCount,StepCount,PassengerCount,SatisfiedPassengerCount,AverageCallTime,AverageInElevatorTime,AverageSatisfactionTime" << endl;
  
  Elevator *e1 = new Elevator("e1");
  Elevator *e2 = new Elevator("e2");
  Elevator **es = new Elevator*[2];
  es[0] = e1;
  es[1] = e2;
  ElevatorLogicSimple *els = new ElevatorLogicSimple(es, 2);
  ElevatorGroupSimulator *esim = new ElevatorGroupSimulator();
  esim->setElevators(es, 2);
  esim->setLogic(els);

  cout << "** Test 1 **" << endl;
  esim->runUntilAllHalted();
  logsMatch(e1, {1});
  logsMatch(e2, {1});
  cout << "Step count: " << esim->getStepCount() << endl;
  cout << endl;

  cout << "** Test 2 **" << endl;
  esim->reset();
  esim->spawnPassenger(5, 1);
  esim->runUntilAllHalted();
  logsMatch(e1, {1, 2, 3, 4, 5, 4, 3, 2, 1});
  printStats(esim);
  
  cout << "** Test 3 **" << endl;
  esim->reset();
  esim->spawnPassenger(5, 1);
  for(int i = 0; i < 5; i++) esim->step();
  esim->spawnPassenger(3, 1);
  esim->runUntilAllHalted();
  printStats(esim);

  delete e1;
  delete e2;
  delete[] es;
  delete els;
  delete esim;

  // randomized tests
  srand(100);
  // pre-generate seeds so cases are repeatable
  int seeds[10];
  for(int i = 0; i < 10; i++) {
    seeds[i] = rand();
  }
  int ecount;
  for(int i = 0; i < 10; i++) {
    srand(seeds[i]);
    ecount = rand() % 5 + 1; // between 1 and 5 elevators
    cout << endl << "** Random test " << (i+1) << " with " << ecount << " elevators **" << endl;
    es = new Elevator*[ecount];
    for(int j = 0; j < ecount; j++) {
      es[j] = new Elevator(to_string((long long int)j));
    }
    els = new ElevatorLogicSimple(es, ecount);
    esim = new ElevatorGroupSimulator();
    esim->setElevators(es, ecount);
    esim->setLogic(els);

    // generate at least 1 passenger
    esim->step();
    esim->spawnPassenger(rand() % MAX_FLOORS + 1, rand() % MAX_FLOORS + 1);
    esim->step();
    for(int step = 0; step < 100; step++) {
      if(step < 10 && rand() % 5 == 0) { // 20% chance of generating a new passenger in first few steps
        esim->spawnPassenger(rand() % MAX_FLOORS + 1, rand() % MAX_FLOORS + 1);
      }
      esim->step();
    }
    printStats(esim);
    writeStats(esim, seeds[i], outcsv);

    for(int j = 0; j < ecount; j++) {
      delete es[j];
    }
    delete[] es;
    delete els;
    delete esim;
  }

  outcsv.close();
  return 0;
}
