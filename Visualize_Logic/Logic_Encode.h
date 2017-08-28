#pragma once
#include "figure.h"
// Logic_Encode command target

class Logic_Encode : public figure
{
public:
	Logic_Encode();
	Logic_Encode(CPoint center, bool _not);
	virtual ~Logic_Encode();

	virtual void Print_Segment(CDC *dc) {}
	virtual void Logic();
};


