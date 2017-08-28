#pragma once
#include "figure.h"
// Input command target

class Input : public figure
{
public:
	Input();
	Input(CPoint _center, bool _not);
	virtual void Logic();

	virtual void Print_Segment(CDC *dc) {}
	virtual ~Input();
};


