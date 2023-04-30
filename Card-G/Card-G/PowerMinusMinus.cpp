#include "PowerMinusMinus.h"
#include "RealPlayer.h"
#include "VirtualPlayer.h"

PowerMinusMinus::PowerMinusMinus(std::string name, int value)
	: Card(name, value)
{
	this->name = name;
	this->value = value;
}

std::string PowerMinusMinus::getType() {
	return name;
}

void PowerMinusMinus::setValue(int value) {
	this->value = value;
}

int PowerMinusMinus::getValue() {
	return value;
}

void PowerMinusMinus::function(Player* p) {
	RealPlayer* rp = dynamic_cast<RealPlayer*>(p);
	VirtualPlayer* vp = dynamic_cast<VirtualPlayer*>(p);

	if (rp != nullptr) {
		vp->decreasePower(value);
		std::cout << "Removing " << value << " from opponents power." << std::endl;
	}

	else {
		rp->decreasePower(value);
		std::cout << "Removing " << value << " from opponents power." << std::endl;
	}
}