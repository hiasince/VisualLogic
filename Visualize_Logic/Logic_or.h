#pragma once

#include"figure.h"
// Logic_or command target

class Logic_or : public figure
{
public:
	Logic_or(CPoint center, bool _not);
	virtual ~Logic_or();
	virtual void Print_Segment(CDC *dc) {}
	virtual void Logic();
};

