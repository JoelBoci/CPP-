#pragma once
#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Deck {

private:
	std::vector<Card*> deck;

	Deck() {};

	static Deck* instance;

public:
	~Deck();
	static Deck* getInstance();
	void generateDeck();
	void printDeck();
	void printHiddenDeck();
	void shuffle();
	Card* getCard(int);
	int size();

	std::vector<Card*>& getDeck() {
		return deck;
	}
};

#endif