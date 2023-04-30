#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "Card.h"
#include <string>
#include <vector>

class Board {

private:
	std::vector<Card*> playerCards;
	class Player* player;

public:
	Board();
	~Board();

	void addCards(Card*);
	void printCards();
	void printName();
	void setPlayer(Player*);

	void removeCard();
	void removeCardAtIndex(int);
	Card* getCard(int);

	Player* getCurrentPlayer();

	std::vector<Card*> getPlayerCards();


};

#endif