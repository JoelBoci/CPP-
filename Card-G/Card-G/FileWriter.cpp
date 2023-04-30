#include "FileWriter.h"
#include <iostream>

FileWriter::~FileWriter() {

}

void FileWriter::openFile(std::fstream myFile) {
	myFile.open("game.txt", std::ios::app);
}

void FileWriter::update(const std::string& message) {
	this->message = message;
}

void FileWriter::removeMeFromList() {
	player->detach(this);
}
