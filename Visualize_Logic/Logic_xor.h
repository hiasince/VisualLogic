#pragma once

#include"figure.h"
// Logic_xor command target

class Logic_xor : public figure
{
public:
	Logic_xor(CPoint center, bool _not);
	virtual ~Logic_xor();
	virtual void Print_Segment(CDC *dc) {}
	virtual void Logic();
};
