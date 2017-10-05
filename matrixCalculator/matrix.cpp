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

void CMatrix::GetMatrixA()
{
	iMatrixA[0][0] = static_cast<int>(utils::ReadFromEditBox(hwnd, IDC_EDIT_A11));
	iMatrixA[0][1] = static_cast<int>(utils::ReadFromEditBox(hwnd, IDC_EDIT_A12));
	iMatrixA[0][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A13);
	iMatrixA[0][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A14);
				
	iMatrixA[1][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A21);
	iMatrixA[1][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A22);
	iMatrixA[1][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A23);
	iMatrixA[1][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A24);
				
	iMatrixA[2][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A31);
	iMatrixA[2][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A32);
	iMatrixA[2][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A33);
	iMatrixA[2][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A34);
					
	iMatrixA[3][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A41);
	iMatrixA[3][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A42);
	iMatrixA[3][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A43);
	iMatrixA[3][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_A44);
}

void CMatrix::GetMatrixB()
{
	iMatrixB[0][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B11);
	iMatrixB[0][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B12);
	iMatrixB[0][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B13);
	iMatrixB[0][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B14);
		   											 
	iMatrixB[1][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B21);
	iMatrixB[1][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B22);
	iMatrixB[1][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B23);
	iMatrixB[1][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B24);
		   											 
	iMatrixB[2][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B31);
	iMatrixB[2][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B32);
	iMatrixB[2][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B33);
	iMatrixB[2][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B34);
		   											 
	iMatrixB[3][0] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B41);
	iMatrixB[3][1] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B42);
	iMatrixB[3][2] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B43);
	iMatrixB[3][3] = utils::ReadFromEditBox(hwnd, IDC_EDIT_B44);
}

void CMatrix::ScalarMult(bool bAorB)
{
	//std::cin >> _iScaler;
	//AMatrix.GetMatrixA();

	if (bAorB) //Scalar A
	{

		int iScaler = static_cast<int>(utils::ReadFromEditBox(hwnd, IDC_EDIT_AScaled));
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
		int iScaler = utils::ReadFromEditBox(hwnd, IDC_EDIT_BScaled);
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
		utils::WriteToEditBox(hwnd, IDC_EDIT_A11, 1);
		utils::WriteToEditBox(hwnd, IDC_EDIT_A22, 1);
		utils::WriteToEditBox(hwnd, IDC_EDIT_A33, 1);
		utils::WriteToEditBox(hwnd, IDC_EDIT_A44, 1);
	}
	else
	{
		utils::WriteToEditBox(hwnd, IDC_EDIT_B11, 1);
		utils::WriteToEditBox(hwnd, IDC_EDIT_B22, 1);
		utils::WriteToEditBox(hwnd, IDC_EDIT_B33, 1);
		utils::WriteToEditBox(hwnd, IDC_EDIT_B44, 1);
	}
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
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixR[i][j] = iMatrixA[i][j] + iMatrixB[i][j];
		}
	}
}

void CMatrix::MatrixSub()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixR[i][j] = iMatrixA[i][j] - iMatrixB[i][j];
		}
	}
}

void CMatrix::WriteToMatrixR()
{
	utils::WriteToEditBox(hwnd, IDC_EDIT_R11, iMatrixR[0][0]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R12, iMatrixR[0][2]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R13, iMatrixR[0][2]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R14, iMatrixR[0][3]);

	utils::WriteToEditBox(hwnd, IDC_EDIT_R21, iMatrixR[1][0]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R22, iMatrixR[1][1]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R23, iMatrixR[1][2]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R24, iMatrixR[1][3]);

	utils::WriteToEditBox(hwnd, IDC_EDIT_R31, iMatrixR[2][0]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R32, iMatrixR[2][1]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R33, iMatrixR[2][2]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R34, iMatrixR[2][3]);

	utils::WriteToEditBox(hwnd, IDC_EDIT_R41, iMatrixR[3][0]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R42, iMatrixR[3][1]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R43, iMatrixR[3][2]);
	utils::WriteToEditBox(hwnd, IDC_EDIT_R44, iMatrixR[3][3]);
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


