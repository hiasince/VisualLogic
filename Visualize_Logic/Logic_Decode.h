#pragma once
#include "figure.h"
// Logic_Decode command target

class Logic_Decode : public figure
{
public:
	Logic_Decode();
	Logic_Decode(CPoint _center, bool _not);

	void Logic();
	virtual void Print_Segment(CDC *dc) {}
	virtual ~Logic_Decode();
};


