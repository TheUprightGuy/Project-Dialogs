#ifndef __MATRIXINPUT_H__
#define __MATRIXINPUT_H__

#include<Windows.h>
//#include <windowsx.h>
//#include "utils.h"
//#include "resource.h"

class CMatrix
{
public:
	CMatrix();
	~CMatrix();

	void GetMatrixA(HWND _hwnd);
	void GetMatrixB(HWND _hwnd);

private:
	int iMatrixA[4][4];
	int iMatrixB[4][4];
};

#endif // __MATRIXINPUT_H__