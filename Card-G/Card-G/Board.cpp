#include "Board.h"
#include <iostream>


Board::Board() {
	player = nullptr;
}

Board::~Board() {
	delete this;
}

void Board::addCards(Card* card) {
	playerCards.push_back(card);
}

void Board::removeCard() {
	playerCards.erase(playerCards.begin());
}

void Board::removeCardAtIndex(int index) {
	if (index >= 0 && index < playerCards.size()) {
		playerCards.erase(playerCards.begin() + index);
	}
}

Card* Board::getCard(int index) {
	return playerCards.at(index);
}

Player* Board::getCurrentPlayer() {
	return player;
}

void Board::printCards() {
	for (const auto& card : playerCards) {
		std::cout << card->toString() << std::endl;
	}
}

void Board::printName() {
	if (player != nullptr) {
		std::cout << player->getName();
	}
	else {
		std::cout << "No player assigned to the board yet.";
	}
}

std::vector<Card*> Board::getPlayerCards() {
	return playerCards;
}

void Board::setPlayer(Player* currentPlayer) {
	this->player = currentPlayer;
}
