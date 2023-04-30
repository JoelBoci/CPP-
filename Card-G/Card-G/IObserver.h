#pragma once
#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>
#include <iostream>

class IObserver {

public:
	virtual ~IObserver() {};
	
	virtual void update(const std::string& message) = 0;
};

#endif