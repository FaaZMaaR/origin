#include "counter.h"

Counter::Counter() : number{ 1 } {}

Counter::Counter(int n) : number{ n } {}

void Counter::increase() {
	++number;
}

void Counter::decrease() {
	--number;
}

int Counter::get() const {
	return number;
}