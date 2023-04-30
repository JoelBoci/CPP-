#include "Deck.h"
#include <random>
#include <vector>
#include "PowerPlusPlus.h"
#include "PowerMinusMinus.h"
#include "Steal.h"

Deck* Deck::instance = nullptr;

Deck::~Deck() {
	for (Card* card : deck) {
		delete card;
	}
	deck.clear();
}

Deck* Deck::getInstance() {
	if (instance == nullptr) {
		instance = new Deck();
	}

	return instance;
}

void Deck::generateDeck() {

	// Default deck of 20
	int power_plus = 8;
	int power_minus = 8;
	int steal = 4;

	for (int i = 1; i <= power_plus; i++) {
		deck.push_back(new PowerPlusPlus("P++ ", i));
	}

	for (int i = 1; i <= power_minus; i++) {
		deck.push_back(new PowerMinusMinus("P-- ", i));
	}

	for (int i = 1; i <= steal; i++) {
		deck.push_back(new Steal("S ", 0));
	}
}

Card* Deck::getCard(int position) {
	Card* c = deck[0];

	for (int i = 0; i < deck.size(); i++) {
		if (position == i) {
			c = deck[i];
		}
	}
	
	return c;
}

void Deck::printDeck() {
	int count = 1;
	for (const auto& card : deck) {
		std::cout << count << ") " << card->toString() << std::endl;
		count++;
	}
}

void Deck::printHiddenDeck() {
	int count = 1;
	for (const auto& card : deck) {
		std::cout << count << ") " << "XXXXX" << std::endl;
		count++;
	}
}

void Deck::shuffle() {
	/*std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(deck.begin(), deck.end(), g);*/

	std::random_shuffle(deck.begin(), deck.end());
}

int Deck::size() {
	return deck.size();
}