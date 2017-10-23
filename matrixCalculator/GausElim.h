#ifndef __GAUSELIM_H__
#define __GAUSELIM_H__

#include <Windows.h>

class CGausElim
{
public:

	CGausElim(HWND _hwnd);
	CGausElim();
	~CGausElim();

	void SetWindow(HWND _hwnd) { m_hwnd = _hwnd; }

	void GetMatrix();
	void SetMatrix();

	void RowMult();
	void RowSwap();
	void MultAdd();

	bool CheckForRowEchelon(); //Message box can either be done inside or out of this with return bool;
	bool CheckForRowEchelonRedux();

private:
	HWND m_hwnd;

	int m_iMatrixA[3][4];
	int m_iMatrixR[3][4];
};

#endif // !__GAUSELIM_H__
