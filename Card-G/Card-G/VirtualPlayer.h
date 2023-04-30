#pragma once
#ifndef VIRTUALPLAYER_H
#define VIRTUALPLAYER_H

#include "Player.h"
#include <random>

class VirtualPlayer : public Player {

private:
	std::string name;
	int wins;
	int draws;
	int losses;
	int power;
	std::list<IObserver*> observers;
	Board* board;

public:
	VirtualPlayer();
	~VirtualPlayer();

	void setName();
	std::string getName() const;

	void increaseWins();
	void increaseDraws();
	void increaseLosses();

	void increasePower(int);
	void decreasePower(int);
	int getPower();

	void printStats();

	void generateBoard(Board*);
	void printBoard();
	Board* getBoard() const override;

	void userPick(std::vector<Card*>&) override;
	void playCard() override;

	// Observer design pattern
	void attach(IObserver*) override;
	void detach(IObserver*) override;
	void notify() override;
	void howManyObservers() override;

};

#endif