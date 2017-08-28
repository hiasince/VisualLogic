#pragma once
#include "figure.h"
// Logic_Seg command target

class Logic_Seg : public figure
{
private:
	int segout1;
	int segout2;
	int segout3;
	int segout4;
	int segout5;
	int segout6;
	int segout7;

public:
	Logic_Seg();
	Logic_Seg(CPoint center, bool _not);

	virtual void Print_Segment(CDC* dc);
	virtual void Logic();
	virtual ~Logic_Seg();
};


