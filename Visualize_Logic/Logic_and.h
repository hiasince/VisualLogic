#pragma once

#include"figure.h"
// Logic_and command target

class Logic_and : public figure
{
public:
	Logic_and(CPoint center, bool _not);
	virtual ~Logic_and();

	virtual void Print_Segment(CDC *dc) {}
	virtual void Logic();
};
