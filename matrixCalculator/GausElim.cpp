#include "utils.h"
#include "resource.h"

#include "GausElim.h"

CGausElim::CGausElim(HWND _hwnd)
	:m_hwnd(_hwnd)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_iMatrixA[i][j] = 0;
			m_iMatrixR[i][j] = 0;
		}
	}
}

CGausElim::CGausElim()
{
	
}

void CGausElim::GetMatrix()
{
	m_iMatrixA[0][0] = ReadFromEditBox(m_hwnd, IDC_EDIT1);
	m_iMatrixA[0][1] = ReadFromEditBox(m_hwnd, IDC_EDIT4);
	m_iMatrixA[0][2] = ReadFromEditBox(m_hwnd, IDC_EDIT2);
	m_iMatrixA[0][3] = ReadFromEditBox(m_hwnd, IDC_EDIT3);

	m_iMatrixA[1][0] = ReadFromEditBox(m_hwnd, IDC_EDIT5);
	m_iMatrixA[1][1] = ReadFromEditBox(m_hwnd, IDC_EDIT8);
	m_iMatrixA[1][2] = ReadFromEditBox(m_hwnd, IDC_EDIT6);
	m_iMatrixA[1][3] = ReadFromEditBox(m_hwnd, IDC_EDIT7);

	m_iMatrixA[2][0] = ReadFromEditBox(m_hwnd, IDC_EDIT9);
	m_iMatrixA[2][1] = ReadFromEditBox(m_hwnd, IDC_EDIT12);
	m_iMatrixA[2][2] = ReadFromEditBox(m_hwnd, IDC_EDIT10);
	m_iMatrixA[2][3] = ReadFromEditBox(m_hwnd, IDC_EDIT11);
}

void CGausElim::SetMatrix()
{
	WriteToEditBox(m_hwnd, IDC_EDIT1, m_iMatrixR[0][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT4, m_iMatrixR[0][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT2, m_iMatrixR[0][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT3, m_iMatrixR[0][3]);

	WriteToEditBox(m_hwnd, IDC_EDIT5, m_iMatrixR[1][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT8, m_iMatrixR[1][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT6, m_iMatrixR[1][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT7, m_iMatrixR[1][3]);

	WriteToEditBox(m_hwnd, IDC_EDIT9, m_iMatrixR[2][0]);
	WriteToEditBox(m_hwnd, IDC_EDIT12, m_iMatrixR[2][1]);
	WriteToEditBox(m_hwnd, IDC_EDIT10, m_iMatrixR[2][2]);
	WriteToEditBox(m_hwnd, IDC_EDIT11, m_iMatrixR[2][3]);

}

void CGausElim::RowMult()
{
	GetMatrix();

	m_iMatrixR[0][0] = m_iMatrixA[0][0];
	m_iMatrixR[0][1] = m_iMatrixA[0][1];
	m_iMatrixR[0][2] = m_iMatrixA[0][2];
	m_iMatrixR[0][3] = m_iMatrixA[0][3];

	m_iMatrixR[1][0] = m_iMatrixA[1][0];
	m_iMatrixR[1][1] = m_iMatrixA[1][1];
	m_iMatrixR[1][2] = m_iMatrixA[1][2];
	m_iMatrixR[1][3] = m_iMatrixA[1][3];

	m_iMatrixR[2][0] = m_iMatrixA[2][0];
	m_iMatrixR[2][1] = m_iMatrixA[2][1];
	m_iMatrixR[2][2] = m_iMatrixA[2][2];
	m_iMatrixR[2][3] = m_iMatrixA[2][3];

	int i = ReadFromEditBox(m_hwnd, );
	int j = ReadFromEditBox(m_hwnd, );

	m_iMatrixR[j][0] = m_iMatrixA[j][0] * i;
	m_iMatrixR[j][1] = m_iMatrixA[j][1] * i;
	m_iMatrixR[j][2] = m_iMatrixA[j][2] * i;
	m_iMatrixR[j][3] = m_iMatrixA[j][3] * i;

	SetMatrix();
}

void CGausElim::RowSwap()
{
	GetMatrix();

	m_iMatrixR[0][0] = m_iMatrixA[0][0];
	m_iMatrixR[0][1] = m_iMatrixA[0][1];
	m_iMatrixR[0][2] = m_iMatrixA[0][2];
	m_iMatrixR[0][3] = m_iMatrixA[0][3];

	m_iMatrixR[1][0] = m_iMatrixA[1][0];
	m_iMatrixR[1][1] = m_iMatrixA[1][1];
	m_iMatrixR[1][2] = m_iMatrixA[1][2];
	m_iMatrixR[1][3] = m_iMatrixA[1][3];

	m_iMatrixR[2][0] = m_iMatrixA[2][0];
	m_iMatrixR[2][1] = m_iMatrixA[2][1];
	m_iMatrixR[2][2] = m_iMatrixA[2][2];
	m_iMatrixR[2][3] = m_iMatrixA[2][3];

	int i = ReadFromEditBox(m_hwnd, );
	int j = ReadFromEditBox(m_hwnd, );

	m_iMatrixR[i][0] = m_iMatrixA[j][0];
	m_iMatrixR[i][1] = m_iMatrixA[j][1];
	m_iMatrixR[i][2] = m_iMatrixA[j][2];
	m_iMatrixR[i][3] = m_iMatrixA[j][3];

	m_iMatrixR[j][0] = m_iMatrixA[i][0];
	m_iMatrixR[j][1] = m_iMatrixA[i][1];
	m_iMatrixR[j][2] = m_iMatrixA[i][2];
	m_iMatrixR[j][3] = m_iMatrixA[i][3];

	SetMatrix();
}

void CGausElim::MultAdd()
{
	GetMatrix();

	m_iMatrixR[0][0] = m_iMatrixA[0][0];
	m_iMatrixR[0][1] = m_iMatrixA[0][1];
	m_iMatrixR[0][2] = m_iMatrixA[0][2];
	m_iMatrixR[0][3] = m_iMatrixA[0][3];

	m_iMatrixR[1][0] = m_iMatrixA[1][0];
	m_iMatrixR[1][1] = m_iMatrixA[1][1];
	m_iMatrixR[1][2] = m_iMatrixA[1][2];
	m_iMatrixR[1][3] = m_iMatrixA[1][3];

	m_iMatrixR[2][0] = m_iMatrixA[2][0];
	m_iMatrixR[2][1] = m_iMatrixA[2][1];
	m_iMatrixR[2][2] = m_iMatrixA[2][2];
	m_iMatrixR[2][3] = m_iMatrixA[2][3];

	int i = ReadFromEditBox(m_hwnd, );
	int j = ReadFromEditBox(m_hwnd, );
	int k = ReadFromEditBox(m_hwnd, );
	int m_iMatrixM[1][4];

	m_iMatrixM[0][0] = m_iMatrixA[j][0] * i;
	m_iMatrixM[0][1] = m_iMatrixA[j][1] * i;
	m_iMatrixM[0][2] = m_iMatrixA[j][2] * i;
	m_iMatrixM[0][3] = m_iMatrixA[j][3] * i;

	m_iMatrixR[j][0] = m_iMatrixM[0][0] + m_iMatrixA[k][0];
	m_iMatrixR[j][1] = m_iMatrixM[0][1] + m_iMatrixA[k][1];
	m_iMatrixR[j][2] = m_iMatrixM[0][2] + m_iMatrixA[k][2];
	m_iMatrixR[j][3] = m_iMatrixM[0][3] + m_iMatrixA[k][3];

	SetMatrix();
}
