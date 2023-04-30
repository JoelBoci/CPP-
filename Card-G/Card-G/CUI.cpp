#include "CUI.h"
#include <iostream>

CUI::~CUI() {
	std::cout << "Goodbye, I was the observer";
}

void CUI::update(const std::string& message) {
	this->message = message;
}

void CUI::removeMeFromList() {
	player->detach(this);
}