#include "Match.h"
#include <iostream>
#include <string.h>
using namespace std;

bool isValidName(string name) {
	if (name.length() < 2) {
		cout << "Name must be longer!" << endl;
		return false;
	}

	if (name.length() > 10) {
		cout << "Name must be shorter!" << endl;
		return false;
	}

	for (char c : name) {
		if (!isalpha(c)) {
			cout << "Name cannot contain digits or special characters!" << endl;
			return false;
		}
	}

	return true;
}

Match::Match() {
	
}

void Match::startMatch(RealPlayer player1, VirtualPlayer player2) {
	// IMPLEMENTATION HERE
	cout << "Welcome to Card-G" << endl;
	cout << "Made by Joel Boci - U2155356" << endl;

	string name = "";

	while (true) {
		std::cout << "\nPlease enter your name: ";
		std::getline(std::cin, name);

		if (isValidName(name)) {
			break;
		}
		else {
			std::cout << "Invalid name, please try again." << std::endl;
		}
	}
	
	// Ask for name

	player1.setName(name);
	cout << "Player 1: " << player1.getName() << "\n\n";

	player2.setName();
	
	cout << "Your opponent will be >>> " << player2.getName() << endl;

	int choice = 0;
	do { 
		cout << "\nPress 1 to start the game, 2 to quit >>> ";
		cin >> choice;







		// STARTING THE GAME

		if (choice == 1) {
			cout << "\nLet's play! We will first show you the rules of the game...\n\n";

			rules();

			cout << "\nNow that you know the rules, lets generate your board and a deck of cards...\n\n";

			// Create an instance of a board and generate for players
			Board* board1 = new Board();
			Board* board2 = new Board();
			player1.generateBoard(board1);
			player2.generateBoard(board2);

			Deck* deck = Deck::getInstance();
			deck->generateDeck();

			// Shuffle the cards and display hidden deck
			deck->shuffle();
			deck->printHiddenDeck();

			cout << "\n";

			// Ask real player to pick their cards
			player1.userPick(deck->getDeck());

			// Display the real player's board
			player1.printBoard();

			cout << "\n\n\n";

			// Ask virtual player to pick their cards
			player2.userPick(deck->getDeck());

			// Display the virtual player's board
			player2.printBoard();

			char input = ' ';
			cout << "\n\nPress any button to start the match >>> ";
			cin >> input;

			cout << "\n\n";
			cout << "Pick cards time\n\n";

			while (player1.getBoard()->getPlayerCards().size() != 0 || player1.getBoard()->getPlayerCards().size() != 0) {
				player1.playCard();
				cout << "\n";
				player1.printBoard();

				player2.playCard();
				cout << "\n\n";
				player2.printBoard();
			}

			cout << "\n\n\n";
			winner(player1, player2);
		}









		// QUITTING THE GAME
		else if (choice == 2) {
			cout << "See you later :(" << endl;
			exit(0);
		}

		// WRONG INPUT
		else {
			cout << "Invalid input" << endl;
		}

	} while (choice < 0 || choice > 3);
}


void Match::rules() {
	cout << "|------------------------------------------------------------------------------|" << endl;
	cout << "|---------------------------- THE RULES OF THE GAME ---------------------------|" << endl;
	cout << "|  The player will have to enter their name and they will play against an AI   |" << endl;
	cout << "|   Once this is done, you will be able to choose 5 cards from a deck of 20    |" << endl;
	cout << "|------------------------------------------------------------------------------|" << endl;
	cout << "|------------------------ The cards and their abilities -----------------------|" << endl;
	cout << "|------------------------------------------------------------------------------|" << endl;
	cout << "|----------------------------------- Power++ ----------------------------------|" << endl;
	cout << "|        The Power++ card will add the value of the card to your power         |" << endl;
	cout << "|                      E.g., P++ 3 = 3 points for you                          |" << endl;
	cout << "|------------------------------------------------------------------------------|" << endl;
	cout << "|----------------------------------- Power-- ----------------------------------|" << endl;
	cout << "|  The Power-- card will deduce the opponents power by the value of the card   |" << endl;
	cout << "|                  However, the power value cannot be below 0                  |" << endl;
	cout << "|  E.g., If opponents points are 3 and you choose P-- 5, the power will be 0   |" << endl;
	cout << "|------------------------------------------------------------------------------|" << endl;
	cout << "|----------------------------------- Steal ------------------------------------|" << endl;
	cout << "|     The steal card allows you to steal one card from the opponents hand      |" << endl;
	cout << "|       If the opponent has no cards, the card is transformed to a P++ 1       |" << endl;
	cout << "|------------------------------------------------------------------------------|" << endl;
	cout << "|           The computer will go first. It's up to you to beat them            |" << endl;
	cout << "|                           Play your cards wisely...                          |" << endl;
	cout << "|------------------------------------------------------------------------------|" << endl;

}

void Match::winner(RealPlayer p1, VirtualPlayer p2) {
	if (p1.getPower() > p2.getPower()) {
		cout << "\n" << p1.getName() << " is the winner with " << p1.getPower() << " power!" << endl;
		cout << p2.getName() << " had " << p2.getPower() << " power\n" << endl;

		p1.increaseWins();
		p2.increaseLosses();
	}

	else if (p2.getPower() > p1.getPower()) {
		cout << "\n" << p2.getName() << " is the winner with " << p2.getPower() << " power!" << endl;
		cout << p1.getName() << " had " << p1.getPower() << " power\n" << endl;
		
		p2.increaseWins();
		p1.increaseLosses();
	}

	else {
		cout << "\nIt's a tie!!!" << endl;
		cout << p1.getName() << " and " << p2.getName() << " both had '" << p1.getPower() << "' power" << "\n" << endl;

		p1.increaseDraws();
		p2.increaseDraws();
	}

	cout << "Player 1: " << endl;
	p1.printStats();

	cout << "\nPlayer 2: " << endl;
	p2.printStats();
}