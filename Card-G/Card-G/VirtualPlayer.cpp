#include "VirtualPlayer.h"
#include <iostream>

VirtualPlayer::VirtualPlayer() : Player() {
	this->wins = 0;
	this->losses = 0;
	this->draws = 0;
	this->power = 0;
	this->board = nullptr;
}

VirtualPlayer::~VirtualPlayer() {

}

// Observer Methods
void VirtualPlayer::attach(IObserver* observer) {
	//observers.push_back(observer);
	Player::attach(observer);
}

void VirtualPlayer::detach(IObserver* observer) {
	//observers.remove(observer);
	Player::detach(observer);
}

void VirtualPlayer::notify() {
	Player::notify();
}

void VirtualPlayer::howManyObservers() {
	//std::cout << "There are '" << observers.size() << "' observers in the list." << std::endl;
	Player::howManyObservers();
}

// Rest of the methods
void VirtualPlayer::setName() {
	srand(time(NULL));

	std::vector<std::string> names = { "John", "Luna", "Aiden", "Leo", "Specter", "Rose" };

	int random = rand() % names.size();
	this->name = names.at(random);
}

std::string VirtualPlayer::getName() const {
	return name;
}

void VirtualPlayer::increaseWins() {
	this->wins++;
}

void VirtualPlayer::increaseDraws() {
	this->draws++;
}

void VirtualPlayer::increaseLosses() {
	this->losses++;
}

void VirtualPlayer::increasePower(int amount) {
	this->power += amount;
}

void VirtualPlayer::decreasePower(int amount) {
	this->power -= amount;
}

int VirtualPlayer::getPower() {
	return power;
}

void VirtualPlayer::printStats() {
	std::cout << "   Name: " << name << std::endl;
	std::cout << "   Wins: " << wins << std::endl;
	std::cout << "   Draws: " << draws << std::endl;
	std::cout << "   Losses: " << losses << std::endl;

}

void VirtualPlayer::generateBoard(Board* board) {
	this->board = board;
	board->setPlayer(this);
}

void VirtualPlayer::printBoard() {
	std::cout << "------------------------------";
	std::cout << "\n        PLAYER 2 BOARD        " << std::endl;
	std::cout << "------------------------------";
	std::cout << "\n Name >>> " << name << std::endl;

	std::vector<Card*> cards = board->getPlayerCards();
	std::cout << "\n " << name << "'s deck:" << std::endl;

	int count = 1;
	for (const auto& card : cards) {
		std::cout << "    " << count << ") " << card->toString() << std::endl;
		count++;
	}

	std::cout << "\n Power >>> " << power << std::endl;
	std::cout << "------------------------------";
}

Board* VirtualPlayer::getBoard() const {
	return board;
}

void VirtualPlayer::userPick(std::vector<Card*>& deck) {

    // Add the virtual player's cards to the board
    for (int i = 0; i < 5; i++) {
        int cardIndex = rand() % deck.size();
        board->addCards(deck[cardIndex]);
        deck.erase(deck.begin() + cardIndex);
    }
}

void VirtualPlayer::playCard() {
	std::cout << "\n\n" << name << "'s turn to play a card\n";
	int index = rand() % board->getPlayerCards().size();

	Card* card = board->getCard(index);
	card->function(this);

	board->removeCardAtIndex(index);
}