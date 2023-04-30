#pragma once
#ifndef FILEWRITER_H
#define FILEWRTIER_H

#include "IObserver.h"
#include "Player.h"
#include <fstream>

class FileWriter : public IObserver {

private:
	std::string message;
	Player* player;

public:
	FileWriter(Player* player) {
		this->player = player;
		this->player->attach(this);
	}

	virtual ~FileWriter();

	void openFile(std::fstream myFile);

	virtual void update(const std::string& message);

	void removeMeFromList();

};

#endif
