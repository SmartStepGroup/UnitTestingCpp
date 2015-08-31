#pragma once
#include "IDice.h"

class Dice : public IDice
{
public:
	Dice();
	int Roll() override;
	virtual ~Dice();
};

