#include "utils.h"
#include "resource.h"

#include "matrix.h"

CMatrix::CMatrix(HWND _hwnd)
	:hwnd(_hwnd)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixA[i][j] = 0;
			iMatrixB[i][j] = 0;
			iMatrixR[i][j] = 0;
		}
	}
}

CMatrix::~CMatrix()
{

};

void CMatrix::GetMatrixA()
{
	iMatrixA[0][0] = static_cast<int>(ReadFromEditBox(hwnd, IDC_EDIT_A11));
	iMatrixA[0][1] = static_cast<int>(ReadFromEditBox(hwnd, IDC_EDIT_A12));
	iMatrixA[0][2] = ReadFromEditBox(hwnd, IDC_EDIT_A13);
	iMatrixA[0][3] = ReadFromEditBox(hwnd, IDC_EDIT_A14);
				
	iMatrixA[1][0] = ReadFromEditBox(hwnd, IDC_EDIT_A21);
	iMatrixA[1][1] = ReadFromEditBox(hwnd, IDC_EDIT_A22);
	iMatrixA[1][2] = ReadFromEditBox(hwnd, IDC_EDIT_A23);
	iMatrixA[1][3] = ReadFromEditBox(hwnd, IDC_EDIT_A24);
				
	iMatrixA[2][0] = ReadFromEditBox(hwnd, IDC_EDIT_A31);
	iMatrixA[2][1] = ReadFromEditBox(hwnd, IDC_EDIT_A32);
	iMatrixA[2][2] = ReadFromEditBox(hwnd, IDC_EDIT_A33);
	iMatrixA[2][3] = ReadFromEditBox(hwnd, IDC_EDIT_A34);
					
	iMatrixA[3][0] = ReadFromEditBox(hwnd, IDC_EDIT_A41);
	iMatrixA[3][1] = ReadFromEditBox(hwnd, IDC_EDIT_A42);
	iMatrixA[3][2] = ReadFromEditBox(hwnd, IDC_EDIT_A43);
	iMatrixA[3][3] = ReadFromEditBox(hwnd, IDC_EDIT_A44);
}

void CMatrix::GetMatrixB()
{
	iMatrixB[0][0] = ReadFromEditBox(hwnd, IDC_EDIT_B11);
	iMatrixB[0][1] = ReadFromEditBox(hwnd, IDC_EDIT_B12);
	iMatrixB[0][2] = ReadFromEditBox(hwnd, IDC_EDIT_B13);
	iMatrixB[0][3] = ReadFromEditBox(hwnd, IDC_EDIT_B14);
		   											 
	iMatrixB[1][0] = ReadFromEditBox(hwnd, IDC_EDIT_B21);
	iMatrixB[1][1] = ReadFromEditBox(hwnd, IDC_EDIT_B22);
	iMatrixB[1][2] = ReadFromEditBox(hwnd, IDC_EDIT_B23);
	iMatrixB[1][3] = ReadFromEditBox(hwnd, IDC_EDIT_B24);
		   											 
	iMatrixB[2][0] = ReadFromEditBox(hwnd, IDC_EDIT_B31);
	iMatrixB[2][1] = ReadFromEditBox(hwnd, IDC_EDIT_B32);
	iMatrixB[2][2] = ReadFromEditBox(hwnd, IDC_EDIT_B33);
	iMatrixB[2][3] = ReadFromEditBox(hwnd, IDC_EDIT_B34);
		   											 
	iMatrixB[3][0] = ReadFromEditBox(hwnd, IDC_EDIT_B41);
	iMatrixB[3][1] = ReadFromEditBox(hwnd, IDC_EDIT_B42);
	iMatrixB[3][2] = ReadFromEditBox(hwnd, IDC_EDIT_B43);
	iMatrixB[3][3] = ReadFromEditBox(hwnd, IDC_EDIT_B44);
}

int CMatrix::Get3DMatrixDet()
{
	int iCurrent = 0;
	int i2dArray[2][2];
	int iTotals[3];
	
	int iX = 0, iY = 0;
	for (int i = 0; i < 3; i++)
	{
		iCurrent = i3dMatrix[0][i]; //Getting Current along the top row;
	
		for (int j = 0; j < 3; j++) //Goings through rows
		{
			for (int k = 0; k < 3; k++) //Going along rows
			{
				if ((j != 0) && (k != i)) //If not row 1 or column of current
				{
					i2dArray[iX][iY] = i3dMatrix[j][k]; //Add to 2d
					iY++; //increment 2d
				}
			}
	
			if (iY >= 2) //If gone through a row
			{
				iX++;
				iY = 0;
			}
	
			if (iX == 2) //If 2dMatrix gotten
			{
				iTotals[i] = iCurrent * ((i2dArray[0][0] * i2dArray[1][1]) - (i2dArray[0][1] * i2dArray[1][0]));
				for (int i = 0; i < 2; i++)
				{
					for (int h = 0; h < 2; h++)
					{
						i2dArray[i][h] = 0;
					}
				}
				iX = 0;
				iY = 0;
				break;
			}
		}
	}
	
	int iFinal = (iTotals[0]) - (iTotals[1]) + (iTotals[2]);
	return iFinal;
}

int CMatrix::Get4DMatrixDetA()
{
	GetMatrixA();

	int iCurrent = 0;
	int iTotals[4];
	int iX = 0, iY = 0;

	for (int i = 0; i < 4; i++)
	{
		iCurrent = iMatrixA[0][i]; //Getting Current along the top row;

		for (int j = 0; j < 4; j++) //Goings through rows
		{
			for (int k = 0; k < 4; k++) //Going along rows
			{
				if ((j != 0) && (k != i)) //If not row 1 or column of current
				{
					i3dMatrix[iX][iY] = iMatrixA[j][k]; //Add to 3d
					iY++; //increment 3d
				}
			}

			if (iY >= 3) //If gone through a row
			{
				iX++;
				iY = 0;
			}

			if (iX == 3) //If 3dMatrix gotten
			{
				iTotals[i] = iCurrent * (Get3DMatrixDet());
				for (int i = 0; i < 2; i++)
				{
					for (int h = 0; h < 2; h++)
					{
						i3dMatrix[i][h] = 0;
					}
				}
				iX = 0;
				iY = 0;
				break;
			}
		}
	}

	int iFinal = (iTotals[0]) - (iTotals[1]) + (iTotals[2]) - (iTotals[3]);
	return (iFinal);
	WriteToEditBox(hwnd, IDC_EDIT_DetA, iFinal);
}

int CMatrix::Get4DMatrixDetB()
{
	GetMatrixB();

	int iCurrent = 0;
	int iTotals[4];
	int iX = 0, iY = 0;

	for (int i = 0; i < 4; i++)
	{
		iCurrent = iMatrixB[0][i]; //Getting Current along the top row;

		for (int j = 0; j < 4; j++) //Goings through rows
		{
			for (int k = 0; k < 4; k++) //Going along rows
			{
				if ((j != 0) && (k != i)) //If not row 1 or column of current
				{
					i3dMatrix[iX][iY] = iMatrixB[j][k]; //Add to 3d
					iY++; //increment 3d
				}
			}

			if (iY >= 3) //If gone through a row
			{
				iX++;
				iY = 0;
			}

			if (iX == 3) //If 3dMatrix gotten
			{
				iTotals[i] = iCurrent * (Get3DMatrixDet());
				for (int i = 0; i < 2; i++)
				{
					for (int h = 0; h < 2; h++)
					{
						i3dMatrix[i][h] = 0;
					}
				}
				iX = 0;
				iY = 0;
				break;
			}
		}
	}

	int iFinal = (iTotals[0]) - (iTotals[1]) + (iTotals[2]) - (iTotals[3]);

	return (iFinal);
	WriteToEditBox(hwnd, IDC_EDIT_DetB, iFinal);
}

void CMatrix::ScalarMult(bool bAorB)
{
	//std::cin >> _iScaler;
	//AMatrix.GetMatrixA();

	if (bAorB) //Scalar A
	{

		int iScaler = static_cast<int>(ReadFromEditBox(hwnd, IDC_EDIT_AScaled));
		GetMatrixA();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				iMatrixR[i][j] = iMatrixA[i][j] * iScaler;
			}
		}
	}
	else  //Scalar B
	{
		int iScaler = ReadFromEditBox(hwnd, IDC_EDIT_BScaled);
		GetMatrixB();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				iMatrixR[i][j] = iMatrixB[i][j] * iScaler;
			}
		}
	}

	WriteToMatrixR();

	//SMatrix.SetMatrixA();
}

void CMatrix::Transpose(bool bABorBA)
{
	if (bABorBA)
	{
		GetMatrixA();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				iMatrixR[j][i] = iMatrixA[i][j];
			}
		}
	}
	
	else
	{
		GetMatrixB();

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				iMatrixR[j][i] = iMatrixB[i][j];
			}
		}
	}
	WriteToMatrixR();
}

void CMatrix::MatrixToI(bool bAorB)
{
	if (bAorB)
	{
		WriteToEditBox(hwnd, IDC_EDIT_A11, 1);
		WriteToEditBox(hwnd, IDC_EDIT_A22, 1);
		WriteToEditBox(hwnd, IDC_EDIT_A33, 1);
		WriteToEditBox(hwnd, IDC_EDIT_A44, 1);
	}
	else
	{
		WriteToEditBox(hwnd, IDC_EDIT_B11, 1);
		WriteToEditBox(hwnd, IDC_EDIT_B22, 1);
		WriteToEditBox(hwnd, IDC_EDIT_B33, 1);
		WriteToEditBox(hwnd, IDC_EDIT_B44, 1);
	}
}

void CMatrix::MatrixInverse(bool bAorB)
{
	if (bAorB)//If getting inverse of A
	{
		{
			int i, j, k, n;
			float a[10][10] = { 0 }, d;
			n = 4;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					a[i][j] = iMatrixA[i][j];

			for (i = 1; i <= n; i++)
				for (j = 1; j <= 2 * n; j++)
					if (j == (i + n))
						a[i][j] = 1;

			/************** partial pivoting **************/
			for (i = n; i > 1; i--)
			{
				if (a[i - 1][1] < a[i][1])
					for (j = 1; j <= n * 2; j++)
					{
						d = a[i][j];
						a[i][j] = a[i - 1][j];
						a[i - 1][j] = d;
					}
			}
			/********** reducing to diagonal  matrix ***********/

			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n * 2; j++)
					if (j != i)
					{
						d = a[j][i] / a[i][i];
						for (k = 1; k <= n * 2; k++)
							a[j][k] -= a[i][k] * d;
					}
			}
			/************** reducing to unit matrix *************/
			for (i = 1; i <= n; i++)
			{
				d = a[i][i];
				for (j = 1; j <= n * 2; j++)
					a[i][j] = a[i][j] / d;
			}

			for (i = 1; i <= n; i++)
			{
				for (j = n + 1; j <= n * 2; j++)
					a[i][j] = iMatrixR[i][j];
			}
		}
	}
	else //If getting inverse of b
	{
		{
			int i, j, k, n;
			float a[10][10] = { 0 }, d;
			n = 4;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					a[i][j] = iMatrixB[i][j];

			for (i = 1; i <= n; i++)
				for (j = 1; j <= 2 * n; j++)
					if (j == (i + n))
						a[i][j] = 1;

			/************** partial pivoting **************/
			for (i = n; i > 1; i--)
			{
				if (a[i - 1][1] < a[i][1])
					for (j = 1; j <= n * 2; j++)
					{
						d = a[i][j];
						a[i][j] = a[i - 1][j];
						a[i - 1][j] = d;
					}
			}
			/********** reducing to diagonal  matrix ***********/

			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n * 2; j++)
					if (j != i)
					{
						d = a[j][i] / a[i][i];
						for (k = 1; k <= n * 2; k++)
							a[j][k] -= a[i][k] * d;
					}
			}
			/************** reducing to unit matrix *************/
			for (i = 1; i <= n; i++)
			{
				d = a[i][i];
				for (j = 1; j <= n * 2; j++)
					a[i][j] = a[i][j] / d;
			}

			for (i = 1; i <= n; i++)
			{
				for (j = n + 1; j <= n * 2; j++)
					a[i][j] = iMatrixR[i][j];
			}
		}
	}
	WriteToMatrixR();
}

void CMatrix::MatrixMult(bool bAorB)
{
	if (bAorB)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				iMatrixR[i][j] = (iMatrixA[i][1] * iMatrixB[1][j]) + (iMatrixA[i][2] * iMatrixB[2][j]) + (iMatrixA[i][3] * iMatrixB[3][j]) + (iMatrixA[i][4] * iMatrixB[4][j]);
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				iMatrixR[i][j] = (iMatrixB[i][1] * iMatrixA[1][j]) + (iMatrixB[i][2] * iMatrixA[2][j]) + (iMatrixB[i][3] * iMatrixA[3][j]) + (iMatrixB[i][4] * iMatrixA[4][j]);
			}
		}
	}

	WriteToMatrixR();
}

void CMatrix::MatrixAdd()
{
	GetMatrixA();
	GetMatrixB();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixR[i][j] = iMatrixA[i][j] + iMatrixB[i][j];
		}
	}
	WriteToMatrixR();
}

void CMatrix::MatrixSub()
{
	GetMatrixA();
	GetMatrixB();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixR[i][j] = iMatrixA[i][j] - iMatrixB[i][j];
		}
	}
	WriteToMatrixR();
}

void CMatrix::WriteToMatrixR()
{
	WriteToEditBox(hwnd, IDC_EDIT_R11, iMatrixR[0][0]);
	WriteToEditBox(hwnd, IDC_EDIT_R12, iMatrixR[0][1]);
	WriteToEditBox(hwnd, IDC_EDIT_R13, iMatrixR[0][2]);
	WriteToEditBox(hwnd, IDC_EDIT_R14, iMatrixR[0][3]);

	WriteToEditBox(hwnd, IDC_EDIT_R21, iMatrixR[1][0]);
	WriteToEditBox(hwnd, IDC_EDIT_R22, iMatrixR[1][1]);
	WriteToEditBox(hwnd, IDC_EDIT_R23, iMatrixR[1][2]);
	WriteToEditBox(hwnd, IDC_EDIT_R24, iMatrixR[1][3]);

	WriteToEditBox(hwnd, IDC_EDIT_R31, iMatrixR[2][0]);
	WriteToEditBox(hwnd, IDC_EDIT_R32, iMatrixR[2][1]);
	WriteToEditBox(hwnd, IDC_EDIT_R33, iMatrixR[2][2]);
	WriteToEditBox(hwnd, IDC_EDIT_R34, iMatrixR[2][3]);

	WriteToEditBox(hwnd, IDC_EDIT_R41, iMatrixR[3][0]);
	WriteToEditBox(hwnd, IDC_EDIT_R42, iMatrixR[3][1]);
	WriteToEditBox(hwnd, IDC_EDIT_R43, iMatrixR[3][2]);
	WriteToEditBox(hwnd, IDC_EDIT_R44, iMatrixR[3][3]);
}									




