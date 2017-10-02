#include "utils.h"
#include "matrix.h"

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

int CMatrix::Get3DMatrixDet(int i3dMatrix[3][3])
{
	int iCurrent = 0;
	int i2dArray[2][2];
	int iTotals[3];

	int iX = 0, iY = 0;
	for (int i = 0; i < 3; i++) 
	{
		iCurrent = i3dMatrix[1][i]; //Getting Current along the top row;
			
		for (int j = 0; j < 3; j++) //Goings through rows
		{
			for (int k = 0; k < 3; k++) //Going along rows
			{
				if ((j != 1) || (k != i)) //If not row 1 or column of current
				{
					i2dArray[iX][iY] = i3dMatrix[j][k]; //Add to 2d
					iY++; //increment 2d
				}
			}

			if (iY == 2) //If gone through a row
			{
				iX++;
				iY = 0;
			}

			if (iX == 2) //If 2dMatrix gotten
			{
				iTotals[i] = iCurrent * (Get2DMatrixDet(i2dArray));
				break;
			}
		}

		
	}
	return 0;
}


