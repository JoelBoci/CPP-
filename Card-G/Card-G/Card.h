#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

class Card {

public:
	Card(std::string, int);

	std::string getType();
	void setValue(int);
	int getValue();

	virtual void function(class Player*) = 0;
	virtual std::string toString() const = 0;

private:
	std::string name;
	int value;

};

#endif
