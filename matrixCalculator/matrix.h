#ifndef __MATRIXINPUT_H__
#define __MATRIXINPUT_H__

#include <Windows.h>
//#include "utils.h"
class CMatrix
{
public:
	CMatrix(HWND _hwnd);
	~CMatrix();

	void GetMatrixA();
	void GetMatrixB();

	int Get2DMatrixDet(int i2dMatrix[2][2]) { return ((i2dMatrix[1][1] * i2dMatrix[2][2]) - (i2dMatrix[1][2] * i2dMatrix[2][1])); }
	int Get3DMatrixDet();
	int Get4DMatrixDetA();
	int Get4DMatrixDetB();

	void ScalarMult(bool bAorB);
	void Transpose(bool bAorB);
	void MatrixToI(bool bAorB);
	void MatrixInverse(bool bAorB);

	void MatrixMult(bool bABorBA);
	void MatrixAdd();
	void MatrixSub();
	void WriteToMatrixR();

private:
	int iMatrixA[4][4];
	int iMatrixB[4][4];

	int i3dMatrix[3][3];
	int iMatrixR[4][4];
	
	HWND hwnd;
};

#endif // __MATRIXINPUT_H__