#pragma once

class IDice {
public:
	virtual int Roll() = 0;
	virtual ~IDice() {};
};