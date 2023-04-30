#include "Player.h"
#include <iostream>

Player::Player() {
	this->wins = 0;
	this->losses = 0;
	this->draws = 0;
	this->power = 0;
	this->board = nullptr;
}

Player::~Player() {

}

// Observer Methods
void Player::attach(IObserver* observer) {
	observers.push_back(observer);
}

void Player::detach(IObserver* observer) {
	observers.remove(observer);
}

void Player::notify() {
	
}

void Player::howManyObservers() {
	std::cout << "There are '" << observers.size() << "' observers in the list." << std::endl;
}

// Rest of the methods
void Player::setName(std::string name) {
	this->name = name;
}

std::string Player::getName() {
	return name;
}

void Player::increaseWins() {
	wins++;
}

void Player::increaseDraws() {
	draws++;
}

void Player::increaseLosses() {
	losses++;
}

void Player::increasePower(int amount) {
	this->power += amount;
}

void Player::decreasePower(int amount) {
	this->power -= amount;
}

int Player::getPower() {
	return power;
}

void Player::printStats() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Wins: " << wins << std::endl;
	std::cout << "Draws: " << draws << std::endl;
	std::cout << "Losses: " << losses << std::endl;
}

void Player::generateBoard(Board* board) {
	this->board = board;
	board->setPlayer(this);
}

Board* Player::getBoard() const {
	return board;
}

void Player::printBoard() {
	std::cout << "\n------------------------------";
	std::cout << "\n        PLAYER BOARD        " << std::endl;
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

void Player::userPick(std::vector<Card*>& deck) {}

void Player::playCard() {}

