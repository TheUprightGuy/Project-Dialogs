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
