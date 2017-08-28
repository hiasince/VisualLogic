#pragma once
// figure command target
class CChildView;

class figure : public CObject
{
protected:
	int type;
	bool not;

	// 값
	int m_InData1;
	int m_InData2;
	int m_InData3;
	int m_InData4;
	int m_InData5;
	int m_InData6;

	int m_OutData1;
	int m_OutData2;
	int m_OutData3;
	int m_OutData4;
	
	// 각 지점
	CPoint center;
	CPoint input1;
	CPoint input2;
	CPoint input3;
	CPoint input4;
	CPoint input5;
	CPoint input6;

	CPoint output;
	CPoint output2;
	CPoint output3;
	CPoint output4;

	figure* prev1;
	figure* prev2;
	figure* prev3;
	figure* prev4;
	figure* prev5;
	figure* prev6;

	figure* next;
	figure* next2;
	figure* next3;
	figure* next4;

public:
	figure() {};
	figure(CPoint center, bool _not);
	virtual ~figure();

	CPoint Get_input1()		{return input1;}
	CPoint Get_input2()		{return input2;}
	CPoint Get_input3()		{return input3;}
	CPoint Get_input4()		{return input4;}
	CPoint Get_input5()		{return input5;}
	CPoint Get_input6()		{return input6;}
	CPoint Get_output()		{return output;}
	CPoint Get_output2()	{return output2;}
	CPoint Get_output3()	{return output3;}
	CPoint Get_output4()	{return output4;}

	int Get_Data1() {return m_InData1;}
	int Get_Data2() {return m_InData2;}
	int Get_Data3() {return m_InData3;}
	int Get_Data4() {return m_InData4;}
	int Get_Data5() {return m_InData5;}
	int Get_Data6() {return m_InData6;}

	int Get_outData1() {return m_OutData1;}
	int Get_outData2() {return m_OutData2;}
	int Get_outData3() {return m_OutData3;}
	int Get_outData4() {return m_OutData4;}
	
	figure* Get_prev1()	{return prev1;}
	figure* Get_prev2()	{return prev2;}
	figure* Get_prev3()	{return prev3;}
	figure* Get_prev4()	{return prev4;}
	figure* Get_prev5()	{return prev5;}
	figure* Get_prev6()	{return prev6;}

	figure* Get_next()	{return next;}
	figure* Get_next2()	{return next2;}
	figure* Get_next3()	{return next3;}
	figure* Get_next4()	{return next4;}

	void Set_next(figure* temp)		{next = temp;}
	void Set_next2(figure* temp)	{next2 = temp;}
	void Set_next3(figure* temp)	{next3 = temp;}
	void Set_next4(figure* temp)	{next4 = temp;}

	void Set_prev1(figure* temp)	{prev1 = temp;}
	void Set_prev2(figure* temp)	{prev2 = temp;}
	void Set_prev3(figure* temp)	{prev3 = temp;}
	void Set_prev4(figure* temp)	{prev4 = temp;}
	void Set_prev5(figure* temp)	{prev5 = temp;}
	void Set_prev6(figure* temp)	{prev6 = temp;}

	void Set_Data1(int temp)		{m_InData1 = temp;}
	void Set_Data2(int temp)		{m_InData2 = temp;}
	void Set_Data3(int temp)		{m_InData3 = temp;}
	void Set_Data4(int temp)		{m_InData4 = temp;}
	void Set_Data5(int temp)		{m_InData5 = temp;}
	void Set_Data6(int temp)		{m_InData6 = temp;}

	void Set_Center(CPoint temp)	{center = temp;}
	CPoint Get_Center()				{return center;}
	void Set_not(bool temp)			{not = temp;}

	int Get_Type()	{return type;}
	bool Get_not()	{return not;}

	virtual void Print_Segment(CDC *dc)=0;
	void draw(CDC *dc);
	void drawline(CDC *dc);
	int Check_On(CPoint point, CDC *dc);
	int Check_Data();
	virtual void Logic()=0;
};