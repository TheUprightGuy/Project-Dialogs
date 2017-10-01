#include "matrix.h"

CMatrix::CMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iMatrixA[i][j] = 0;
			iMatrixB[i][j] = 0;
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
