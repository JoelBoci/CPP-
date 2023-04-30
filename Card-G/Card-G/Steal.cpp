#include "Steal.h"
#include "RealPlayer.h"
#include "VirtualPlayer.h"

Steal::Steal(std::string name, int value)
	: Card(name, value)
{
	this->name = name;
	this->value = value;
}

std::string Steal::getType() {
	return name;
}

void Steal::setValue(int value) {
	this->value = value;
}

int Steal::getValue() {
	return value;
}

void Steal::function(Player* p) {
	
}