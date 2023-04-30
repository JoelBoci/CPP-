#pragma once
#ifndef POWERPLUSPLUS_H
#define POWERPLUSPLUS_H

#include "Card.h"
#include "Board.h"

class PowerPlusPlus : public Card {

private:
	std::string name;
	int value;

public:
	PowerPlusPlus(std::string name, int value);

	std::string getType();
	void setValue(int);
	int getValue();

	void function(Player*) override;

	std::string toString() const override {
		return name + " " + std::to_string(value);
	}

};

#endif
