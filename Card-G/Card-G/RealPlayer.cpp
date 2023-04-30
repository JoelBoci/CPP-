#include "RealPlayer.h"
#include <iostream>
#include "PowerPlusPlus.h"

RealPlayer::RealPlayer() : Player() {
	this->wins = 0;
	this->losses = 0;
	this->draws = 0;
	this->power = 0;
	this->board = nullptr;
}

RealPlayer::~RealPlayer() {
	
}

// Observer Methods
void RealPlayer::attach(IObserver* observer) {
	//observers.push_back(observer);
	Player::attach(observer);
}

void RealPlayer::detach(IObserver* observer) {
	/*observers.remove(observer);*/
	Player::detach(observer);
}

void RealPlayer::notify() {
	Player::notify();
}

void RealPlayer::howManyObservers() {
	//std::cout << "There are '" << observers.size() << "' observers in the list." << std::endl;
	Player::howManyObservers();
}



// Rest of the methods

void RealPlayer::setName(std::string name) {
	this->name = name;
}

std::string RealPlayer::getName() {
	return name;
}

void RealPlayer::increaseWins() {
	this->wins++;
}

void RealPlayer::increaseDraws() {
	this->draws++;
}

void RealPlayer::increaseLosses() {
	this->losses++;
}

void RealPlayer::increasePower(int amount) {
	this->power += amount;
}

void RealPlayer::decreasePower(int amount) {
	this->power -= amount;
}

int RealPlayer::getPower() {
	return power;
}

void RealPlayer::printStats() {
	std::cout << "   Name: " << name << std::endl;
	std::cout << "   Wins: " << wins << std::endl;
	std::cout << "   Draws: " << draws << std::endl;
	std::cout << "   Losses: " << losses << std::endl;
}

void RealPlayer::generateBoard(Board* board) {
	this->board = board;
	board->setPlayer(this);
}

void RealPlayer::printBoard() {
	std::cout << "\n------------------------------";
	std::cout << "\n        PLAYER 1 BOARD        " << std::endl;
	std::cout << "------------------------------";
	std::cout << "\n Name >>> " << name << std::endl;

	std::vector<Card*> cards = board->getPlayerCards();
	std::cout << "\n Your deck:" << std::endl;

	int count = 1;
	for (const auto& card : cards) {
		std::cout << "    " << count << ") " << card->toString() << std::endl;
		count++;
	}

	std::cout << "\n Power >>> " << power << std::endl;
	std::cout << "------------------------------";
}

Board* RealPlayer::getBoard() const {
	return board;
}

void RealPlayer::userPick(std::vector<Card*>& deck) {
	int cardIndex = 0;

	for (int i = 0; i < 5; i++) {
		std::cout << "Select a card to add to your hand >>> ";
		int cardIndex;
		do {
			try {
				std::cin >> cardIndex;
				if (cardIndex < 0 || cardIndex >= deck.size()) {
					throw std::out_of_range("Invalid card index");
				}

				// add the selected card to the player's hand
				board->addCards(deck[cardIndex]);

				// remove the selected card from the deck
				deck.erase(deck.begin() + cardIndex);
			}
			catch (const std::out_of_range& e) {
				std::cout << "Error: " << e.what() << "\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		} while (cardIndex < 0 || cardIndex >= deck.size());
	}
}

void RealPlayer::playCard() {
	int index = 0;

	std::cout << "\n\nChoose a card to play >>> ";
	std::cin >> index;

	Card* card = board->getCard(index);
	card->function(this);

	board->removeCardAtIndex(index);
}
