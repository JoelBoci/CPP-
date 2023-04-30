#include "PowerPlusPlus.h"
#include "RealPlayer.h"
#include "VirtualPlayer.h"

PowerPlusPlus::PowerPlusPlus(std::string name, int value)
	: Card(name, value)
{
	this->name = name;
	this->value = value;
}

std::string PowerPlusPlus::getType() {
	return name;
}

void PowerPlusPlus::setValue(int value) {
	this->value = value;
}

int PowerPlusPlus::getValue() {
	return value;
}

void PowerPlusPlus::function(Player* p) {
	RealPlayer* rp = dynamic_cast<RealPlayer*>(p);
	VirtualPlayer* vp = dynamic_cast<VirtualPlayer*>(p);

	if (rp != nullptr) {
		rp->increasePower(value);
		std::cout << "Adding " << value << " to player's power." << std::endl;
	}

	else {
		vp->increasePower(value);
		std::cout << "Adding " << value << " to player's power." << std::endl;
	}
}