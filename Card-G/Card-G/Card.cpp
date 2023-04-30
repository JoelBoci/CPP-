#include "Card.h"
#include <iostream>
#include "PowerMinusMinus.h"
#include "PowerPlusPlus.h"
#include "Steal.h"

Card::Card(std::string name, int value) {
	this->name = name;
	this->value = value;
}

std::string Card::getType() {
	return name;
}

void Card::setValue(int value) {
	this->value = value;
}

int Card::getValue() {
	return value;
}

void Card::function(Player* p) {} // Defined in subclasses

std::string Card::toString() const {
	return name + " " + std::to_string(value);
};
