#include "utils.h"
#include "matrix.h"
#include "resource.h"
CMatrix::CMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixA[i][j];
			iMatrixB[i][j];
		}
	}
}

void CMatrix::GetMatrixA(HWND _hwnd)
{
	
	iMatrixA[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
	iMatrixA[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
	iMatrixA[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
	iMatrixA[1][4] = ReadFromEditBox(_hwnd, IDC_EDIT_A14);

	iMatrixA[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
	iMatrixA[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
	iMatrixA[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
	iMatrixA[2][4] = ReadFromEditBox(_hwnd, IDC_EDIT_A24);

	iMatrixA[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
	iMatrixA[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
	iMatrixA[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
	iMatrixA[3][4] = ReadFromEditBox(_hwnd, IDC_EDIT_A34);

	iMatrixA[4][1] = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
	iMatrixA[4][2] = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
	iMatrixA[4][3] = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
	iMatrixA[4][4] = ReadFromEditBox(_hwnd, IDC_EDIT_A44);
}

void CMatrix::GetMatrixB(HWND _hwnd)
{
	iMatrixB[1][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
	iMatrixB[1][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
	iMatrixB[1][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
	iMatrixB[1][4] = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
		   											 
	iMatrixB[2][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
	iMatrixB[2][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
	iMatrixB[2][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
	iMatrixB[2][4] = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
		   											 
	iMatrixB[3][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
	iMatrixB[3][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
	iMatrixB[3][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
	iMatrixB[3][4] = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
		   											 
	iMatrixB[4][1] = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
	iMatrixB[4][2] = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
	iMatrixB[4][3] = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
	iMatrixB[4][4] = ReadFromEditBox(_hwnd, IDC_EDIT_B44);
}



//int CMatrix::Get3DMatrixDet(int i3dMatrix[3][3])
//{
//	int iCurrent = 0;
//	int i2dArray[2][2];
//	int iTotals[3];
//
//	int iX = 0, iY = 0;
//	for (int i = 0; i < 3; i++) 
//	{
//		iCurrent = i3dMatrix[1][i]; //Getting Current along the top row;
//			
//		for (int j = 0; j < 3; j++) //Goings through rows
//		{
//			for (int k = 0; k < 3; k++) //Going along rows
//			{
//				if ((j != 1) || (k != i)) //If not row 1 or column of current
//				{
//					i2dArray[iX][iY] = i3dMatrix[j][k]; //Add to 2d
//					iY++; //increment 2d
//				}
//			}
//
//			if (iY == 2) //If gone through a row
//			{
//				iX++;
//				iY = 0;
//			}
//
//			if (iX == 2) //If 2dMatrix gotten
//			{
//				iTotals[i] = iCurrent * (Get2DMatrixDet(i2dArray));
//				break;
//			}
//		}
//
//		
//	}
//	return 0;
//}


