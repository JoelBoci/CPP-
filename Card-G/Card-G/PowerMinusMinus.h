#pragma once
#ifndef POWERMINUSMINUS_H
#define POWERMINUSMINUS_H

#include "Card.h"
#include "Board.h"

class PowerMinusMinus : public Card {

private:
	std::string name;
	int value;

public:
	PowerMinusMinus(std::string name, int value);

	std::string getType();
	void setValue(int);
	int getValue();

	void function(Player*) override;

	std::string toString() const override {
		return name + " " + std::to_string(value);
	}

};

#endif
