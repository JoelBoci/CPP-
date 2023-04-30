#pragma once
#ifndef REALPLAYER_H
#define REALPLAYER_H

#include "Player.h"

class RealPlayer : public Player {

private:
	std::string name;
	int wins;
	int draws;
	int losses;
	int power;
	std::list<IObserver*> observers;
	Board* board;
	
public:
	RealPlayer();
	~RealPlayer();

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
	Board* getBoard() const override;

	void userPick(std::vector<Card*>&) override;
	virtual void playCard() override;

	// Observer design pattern
	void attach(IObserver*) override;
	void detach(IObserver*) override;
	void notify() override;
	void howManyObservers() override;

};

#endif