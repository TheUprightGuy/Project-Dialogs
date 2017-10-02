#ifndef __MATRIXINPUT_H__
#define __MATRIXINPUT_H__

#include<Windows.h>
//#include <windowsx.h>
//#include "resource.h"

class CMatrix
{
public:
	CMatrix();
	~CMatrix();

	void GetMatrixA(HWND _hwnd);
	void GetMatrixB(HWND _hwnd);

	int Get2DMatrixDet(int i2dMatrix[2][2]) { return ((i2dMatrix[1][1] * i2dMatrix[2][2]) - (i2dMatrix[1][2] * i2dMatrix[2][1])); }
	int Get3DMatrixDet(int i3dMatrix[3][3]);

private:
	int iMatrixA[4][4];
	int iMatrixB[4][4];
};

#endif // __MATRIXINPUT_H__