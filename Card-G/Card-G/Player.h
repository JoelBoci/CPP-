#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "IObserver.h"
#include "Deck.h"
#include <string>
#include <list>

class Player {

private:
	std::string name;
	int wins;
	int draws;
	int losses;
	int power;
	class Board* board;

	// For the observer pattern
	std::list<IObserver*> observers;
	
public:

	Player();

	~Player();

	void setName(std::string);
	std::string getName();

	void increaseWins();
	void increaseDraws();
	void increaseLosses();

	void increasePower(int);
	void decreasePower(int);
	int getPower();

	void printStats();

	void generateBoard(Board*);
	void printBoard();

	virtual Board* getBoard() const = 0;

	virtual void userPick(std::vector<Card*>&) = 0;
	virtual void playCard() = 0;

	// Observer design pattern
	virtual void attach(IObserver*) = 0;
	virtual void detach(IObserver*) = 0;
	virtual void notify() = 0;
	virtual void howManyObservers() = 0;

};

#endif
