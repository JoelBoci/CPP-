#pragma once
#ifndef MATCH_H
#define MATCH_H

#include "Player.h"
#include "RealPlayer.h"
#include "VirtualPlayer.h"
#include <iostream>

class Match {

public:
	Match();

	void startMatch(RealPlayer, VirtualPlayer);
	void rules();
	void winner(RealPlayer p1, VirtualPlayer p2);

};

#endif
