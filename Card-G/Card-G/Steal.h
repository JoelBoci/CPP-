#pragma once
#ifndef STEAL_H
#define STEAL_H

#include "Card.h"
#include "Board.h"

class Steal : public Card {

private:
	std::string name;
	int value;

public:
	Steal(std::string name, int value);

	std::string getType();
	void setValue(int);
	int getValue();

	void function(Player*) override;

	std::string toString() const override {
		return name + " " + std::to_string(value);
	}
};

#endif
