#pragma once
#include "figure.h"
// Logic_Mux command target

class Logic_Mux : public figure
{
public:
	Logic_Mux();
	Logic_Mux(CPoint point, bool _not);

	virtual void Print_Segment(CDC *dc) {}
	void Logic();
	virtual ~Logic_Mux();
};


