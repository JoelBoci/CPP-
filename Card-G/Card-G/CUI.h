#pragma once
#ifndef CUI_H
#define CUI_H

#include "IObserver.h"
#include "Player.h"

class CUI : public IObserver {

private:
	std::string message;
	Player* player;

public:
	CUI(Player* player) {
		this->player = player;
		this->player->attach(this);
	}

	virtual ~CUI();

	virtual void update(const std::string& message);

	void removeMeFromList();

};

#endif
