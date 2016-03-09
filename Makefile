all: test_elevator

test_elevator: test_elevator.o elevator_logic_simple.o elevator_group_simulator.o passenger.o elevator.o
	g++ -std=c++0x -g -Wall -o test_elevator test_elevator.o elevator_logic_simple.o elevator_group_simulator.o passenger.o elevator.o

test_elevator.o: test_elevator.cpp elevator.h elevator_logic_simple.h elevator_group_simulator.h common_defs.h
	g++ -std=c++0x -g -Wall -c test_elevator.cpp

.PHONY: clean docs
clean:
	rm -f *.o test_elevator

docs:
	doxygen Doxyfile

