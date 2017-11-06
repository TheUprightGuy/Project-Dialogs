#include "transformation.h"
#include "utils.h"
#include "resource.h"

#include<math.h>

CTrans::~CTrans()
{
}

void CTrans::ReadColMatrix()
{
	m_iMatrixCol[0][0] = ReadFromEditBox(m_hwnd, IDC_EDIT16);
	m_iMatrixCol[0][1] = ReadFromEditBox(m_hwnd, IDC_EDIT18);
	m_iMatrixCol[0][2] = ReadFromEditBox(m_hwnd, IDC_EDIT19);
	m_iMatrixCol[0][3] = ReadFromEditBox(m_hwnd, IDC_EDIT20);

	m_iMatrixCol[1][0] = ReadFromEditBox(m_hwnd, IDC_EDIT21);
	m_iMatrixCol[1][1] = ReadFromEditBox(m_hwnd, IDC_EDIT22);
	m_iMatrixCol[1][2] = ReadFromEditBox(m_hwnd, IDC_EDIT23);
	m_iMatrixCol[1][3] = ReadFromEditBox(m_hwnd, IDC_EDIT8);

	m_iMatrixCol[2][0] = ReadFromEditBox(m_hwnd, IDC_EDIT9);
	m_iMatrixCol[2][1] = ReadFromEditBox(m_hwnd, IDC_EDIT10);
	m_iMatrixCol[2][2] = ReadFromEditBox(m_hwnd, IDC_EDIT11);
	m_iMatrixCol[2][3] = ReadFromEditBox(m_hwnd, IDC_EDIT12);

	m_iMatrixCol[3][0] = ReadFromEditBox(m_hwnd, IDC_EDIT24);
	m_iMatrixCol[3][1] = ReadFromEditBox(m_hwnd, IDC_EDIT25);
	m_iMatrixCol[3][2] = ReadFromEditBox(m_hwnd, IDC_EDIT26);
	m_iMatrixCol[3][3] = ReadFromEditBox(m_hwnd, IDC_EDIT27);
}

void CTrans::SetColMatrix()
{
	WriteToEditBox(m_hwnd, IDC_EDIT16, m_iMatrixCol[0][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT18, m_iMatrixCol[0][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT19, m_iMatrixCol[0][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT20, m_iMatrixCol[0][3]);

	WriteToEditBox(m_hwnd, IDC_EDIT21, m_iMatrixCol[1][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT22, m_iMatrixCol[1][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT23, m_iMatrixCol[1][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT8, m_iMatrixCol[1][3]);

	WriteToEditBox(m_hwnd, IDC_EDIT9, m_iMatrixCol[2][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT10, m_iMatrixCol[2][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT11, m_iMatrixCol[2][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT12, m_iMatrixCol[2][3]);

	WriteToEditBox(m_hwnd, IDC_EDIT24, m_iMatrixCol[3][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT25, m_iMatrixCol[3][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT26, m_iMatrixCol[3][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT27, m_iMatrixCol[3][3]);
}

void CTrans::ReadRowMatrix()
{
	m_iMatrixRow[0][0] = ReadFromEditBox(m_hwnd, IDC_EDIT47);
	m_iMatrixRow[0][1] = ReadFromEditBox(m_hwnd, IDC_EDIT48);
	m_iMatrixRow[0][2] = ReadFromEditBox(m_hwnd, IDC_EDIT49);
	m_iMatrixRow[0][3] = ReadFromEditBox(m_hwnd, IDC_EDIT50);
			 
	m_iMatrixRow[1][0] = ReadFromEditBox(m_hwnd, IDC_EDIT51);
	m_iMatrixRow[1][1] = ReadFromEditBox(m_hwnd, IDC_EDIT52);
	m_iMatrixRow[1][2] = ReadFromEditBox(m_hwnd, IDC_EDIT53);
	m_iMatrixRow[1][3] = ReadFromEditBox(m_hwnd, IDC_EDIT54);
			 
	m_iMatrixRow[2][0] = ReadFromEditBox(m_hwnd, IDC_EDIT55);
	m_iMatrixRow[2][1] = ReadFromEditBox(m_hwnd, IDC_EDIT56);
	m_iMatrixRow[2][2] = ReadFromEditBox(m_hwnd, IDC_EDIT57);
	m_iMatrixRow[2][3] = ReadFromEditBox(m_hwnd, IDC_EDIT58);

	m_iMatrixRow[3][0] = ReadFromEditBox(m_hwnd, IDC_EDIT59);
	m_iMatrixRow[3][1] = ReadFromEditBox(m_hwnd, IDC_EDIT60);
	m_iMatrixRow[3][2] = ReadFromEditBox(m_hwnd, IDC_EDIT61);
	m_iMatrixRow[3][3] = ReadFromEditBox(m_hwnd, IDC_EDIT62);
}

void CTrans::SetRowMatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_iMatrixRow[i][j] = m_iMatrixCol[j][i];
		}
	}

	WriteToEditBox(m_hwnd, IDC_EDIT47, m_iMatrixRow[0][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT48, m_iMatrixRow[0][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT49, m_iMatrixRow[0][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT50, m_iMatrixRow[0][3]);
												
	WriteToEditBox(m_hwnd, IDC_EDIT51, m_iMatrixRow[1][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT52, m_iMatrixRow[1][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT53, m_iMatrixRow[1][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT54, m_iMatrixRow[1][3]);
												
	WriteToEditBox(m_hwnd, IDC_EDIT55, m_iMatrixRow[2][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT56, m_iMatrixRow[2][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT57, m_iMatrixRow[2][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT58, m_iMatrixRow[2][3]);
												
	WriteToEditBox(m_hwnd, IDC_EDIT59, m_iMatrixRow[3][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT60, m_iMatrixRow[3][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT61, m_iMatrixRow[3][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT62, m_iMatrixRow[3][3]);
}

void CTrans::ReadScaleXYZ()
{
	m_ScaleXYZ.iX = ReadFromEditBox(m_hwnd, IDC_EDIT1);
	m_ScaleXYZ.iY = ReadFromEditBox(m_hwnd, IDC_EDIT2);
	m_ScaleXYZ.iZ = ReadFromEditBox(m_hwnd, IDC_EDIT3);
}

void CTrans::ReadTransXYZ()
{
	m_TransXYZ.iX = ReadFromEditBox(m_hwnd, IDC_EDIT4);
	m_TransXYZ.iY = ReadFromEditBox(m_hwnd, IDC_EDIT5);
	m_TransXYZ.iZ = ReadFromEditBox(m_hwnd, IDC_EDIT6);
}

void CTrans::ReadRotXYZ()
{
	m_RotateXYZ.iX = ReadFromEditBox(m_hwnd, IDC_EDIT7);
	m_RotateXYZ.iY = ReadFromEditBox(m_hwnd, IDC_EDIT28);
	m_RotateXYZ.iZ = ReadFromEditBox(m_hwnd, IDC_EDIT30);

	m_iAngleOfRot = ReadFromEditBox(m_hwnd, IDC_EDIT13);

}

void CTrans::SetIdentity()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				m_iMatrixCol[i][j] = 1;
			}
			else
			{
				m_iMatrixCol[i][j] = 0;
			}
		}
	}
	SetRowMatrix();
	SetColMatrix();
}

void CTrans::SetScaleMatrix()
{
	SetIdentity();
	ReadScaleXYZ();

	m_iMatrixCol[0][0] = m_ScaleXYZ.iX;
	m_iMatrixCol[1][1] = m_ScaleXYZ.iY;
	m_iMatrixCol[2][2] = m_ScaleXYZ.iZ;

	SetRowMatrix();
	SetColMatrix();

}

void CTrans::SetTransMatrix()
{
	SetIdentity();
	ReadTransXYZ();

	m_iMatrixCol[0][3] = m_TransXYZ.iX;
	m_iMatrixCol[1][3] = m_TransXYZ.iY;
	m_iMatrixCol[2][3] = m_TransXYZ.iZ;
						   
	SetRowMatrix();
	SetColMatrix();
}

void CTrans::SetRotateMatrix()
{
	SetIdentity();
	ReadRotXYZ();

	//Normalise
	float Mag = sqrt(pow(m_RotateXYZ.iX, 2.0f) + pow(m_RotateXYZ.iY, 2.0f) + pow(m_RotateXYZ.iY, 2.0f));
	float x = m_RotateXYZ.iX / Mag;
	float y = m_RotateXYZ.iY / Mag;
	float z = m_RotateXYZ.iY / Mag;
	float fDeg = m_iAngleOfRot * 3.141593 / 180.0f;

	//Calculate
	float iTempMatrix[4][4];
	iTempMatrix[0][0] = (x * x * (1.0f - cos(fDeg))) + cos(fDeg);
	iTempMatrix[0][1] = (x * y * (1.0f - cos(fDeg))) - (z * sin(fDeg));
	iTempMatrix[0][2] = ((x * z) * (1.0f - cos(fDeg))) + (y * sin(fDeg));
	iTempMatrix[0][3] = 0.0f;

	iTempMatrix[1][0] = ((x * x) * (1.0f - cos(fDeg))) + (z * sin(fDeg));
	iTempMatrix[1][1] = (y * y * (1.0f - cos(fDeg))) + cos(fDeg);
	iTempMatrix[1][2] = (y * z * (1.0f - cos(fDeg))) - (x * sin(fDeg));
	iTempMatrix[1][3] = 1.0f;

	iTempMatrix[2][0] = ((x * z) * (1.0f - cos(fDeg))) - (y * sin(fDeg));
	iTempMatrix[2][1] = ((y * z) * (1.0f - cos(fDeg))) + (x * sin(fDeg));
	iTempMatrix[2][2] = (z * z * (1.0f - cos(fDeg))) + cos(fDeg);
	iTempMatrix[2][3] = 0.0f;

	iTempMatrix[3][0] = 0;
	iTempMatrix[3][1] = 0;
	iTempMatrix[3][2] = 0;
	iTempMatrix[3][3] = 1.0f;

	//input
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_iMatrixCol[i][j] = iTempMatrix[i][j];
		}
	}

	SetRowMatrix();
	SetColMatrix();
}

void CTrans::SetProjectMatrix()
{
}

void CTrans::ScaleByPrevious()
{

	ReadColMatrix();

	//Get Previous
	int iTempMatrix[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iTempMatrix[i][j] = m_iMatrixCol[i][j];
		}
	}

	//Get Transform Matrix
	SetScaleMatrix();
	int iTempMatrixAfter[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iTempMatrixAfter[i][j] = m_iMatrixCol[i][j];
		}
	}

	//Mult the two
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_iMatrixCol[i][j] = (iTempMatrix[i][0] * iTempMatrixAfter[0][j]) + (iTempMatrix[i][1] * iTempMatrixAfter[1][j]) + (iTempMatrix[i][2] * iTempMatrixAfter[2][j]) + (iTempMatrix[i][3] * iTempMatrixAfter[3][j]);
		}
	}
	SetColMatrix();
	SetRowMatrix();
}

void CTrans::TransByPrevious()
{
	ReadColMatrix();
	//Get Previous
	int iTempMatrix[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iTempMatrix[i][j] = m_iMatrixCol[i][j];
		}
	}

	//Get Transform Matrix
	SetTransMatrix();
	int iTempMatrixAfter[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iTempMatrixAfter[i][j] = m_iMatrixCol[i][j];
		}
	}

	//Mult the two
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_iMatrixCol[i][j] = (iTempMatrix[i][0] * iTempMatrixAfter[0][j]) + (iTempMatrix[i][1] * iTempMatrixAfter[1][j]) + (iTempMatrix[i][2] * iTempMatrixAfter[2][j]) + (iTempMatrix[i][3] * iTempMatrixAfter[3][j]);
		}
	}
	SetColMatrix();
	SetRowMatrix();
}

void CTrans::RotateByPrevious()
{
	ReadColMatrix();
	//Get Previous
	int iTempMatrix[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iTempMatrix[i][j] = m_iMatrixCol[i][j];
		}
	}

	//Get Transform Matrix
	SetRotateMatrix();
	int iTempMatrixAfter[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			iTempMatrixAfter[i][j] = m_iMatrixCol[i][j];
		}
	}

	//Mult the two
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_iMatrixCol[i][j] = (iTempMatrix[i][0] * iTempMatrixAfter[0][j]) + (iTempMatrix[i][1] * iTempMatrixAfter[1][j]) + (iTempMatrix[i][2] * iTempMatrixAfter[2][j]) + (iTempMatrix[i][3] * iTempMatrixAfter[3][j]);
		}
	}
	SetColMatrix();
	SetRowMatrix();
}

void CTrans::ProjectByPrevious()
{
}
