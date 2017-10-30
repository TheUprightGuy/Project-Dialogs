#include <math.h>
#include "utils.h"
#include "resource.h"

#include "sleeeerp.h"

CSlerp::CSlerp()
{
}

CSlerp::~CSlerp()
{
}

void CSlerp::GetA()
{
	QuatA.w = ReadFromEditBox(hwnd, IDC_EDIT1);
	QuatA.x = ReadFromEditBox(hwnd, IDC_EDIT2);
	QuatA.y = ReadFromEditBox(hwnd, IDC_EDIT3);
	QuatA.z = ReadFromEditBox(hwnd, IDC_EDIT4);
}

void CSlerp::GetB()
{
	QuatB.w = ReadFromEditBox(hwnd, IDC_EDIT5);
	QuatB.x = ReadFromEditBox(hwnd, IDC_EDIT6);
	QuatB.y = ReadFromEditBox(hwnd, IDC_EDIT7);
	QuatB.z = ReadFromEditBox(hwnd, IDC_EDIT8);
}

void CSlerp::GetT()
{
	iIntParam = ReadFromEditBox(hwnd, IDC_EDIT5);
}

void CSlerp::SetSlerp()
{
	WriteToEditBox(hwnd, IDC_EDIT10, QuatR.w);
	WriteToEditBox(hwnd, IDC_EDIT11, QuatR.x);
	WriteToEditBox(hwnd, IDC_EDIT12, QuatR.y);
	WriteToEditBox(hwnd, IDC_EDIT13, QuatR.z);
}

void CSlerp::SlerpABT()
{
	GetA();
	GetB();

	GetT();


	float iCosine = ((QuatA.w * QuatB.w) + (QuatA.x * QuatB.x) + (QuatA.y * QuatB.y) + (QuatA.z * QuatB.z));

	if (iCosine < 0.0f)
	{
		QuatB.w = -QuatB.w;
		QuatB.x = -QuatB.x;
		QuatB.y = -QuatB.y;
		QuatB.z = -QuatB.z;
	}

	float f0, f1;
	if (iCosine > 0.99999f)
	{
		f0 = 1.0f - iIntParam;
		f1 = iIntParam;
	}
	else
	{
		float fSin = sqrt(1.0f - iCosine * iCosine);

		float fOmega = atan2(fSin, iCosine);

		float oneOverSinOmega = 1.0f / fSin;

		f0 = sin((1.0f - iIntParam) * fOmega) * oneOverSinOmega;
		f1 = sin(iIntParam * fOmega) * oneOverSinOmega;
	}

	QuatR.w = QuatA.w*f0 + QuatB.w*f1;
	QuatR.x = QuatA.x*f0 + QuatB.x*f1;
	QuatR.y = QuatA.y*f0 + QuatB.y*f1;
	QuatR.z = QuatA.z*f0 + QuatB.z*f1;

	if (int i = 1)
	{
	SetSlerp();
    }
}

void CSlerp::ConvertA()
{
	GetA();

	int w = QuatA.z;
	int x = QuatA.w;
	int y = QuatA.x;
	int z = QuatA.y;

	iMatrixR[0][0] = 1 - 2 * pow(y, 2) - 2 * pow(z, 2);
	iMatrixR[0][1] = 2 * x * y - 2 * z * w;
	iMatrixR[0][2] = 2 * x * z + 2 * y * w;
	iMatrixR[0][3] = 0;

	iMatrixR[1][0] = 2 * x * y + 2 * z * w;
	iMatrixR[1][1] = 1 - 2 * pow(x, 2) - 2 * pow(z, 2);
	iMatrixR[1][2] = 2 * y * z - 2 * x * w;
	iMatrixR[1][3] = 0;

	iMatrixR[2][0] = 2 * x * z - 2 * y * w;
	iMatrixR[2][1] = 2 * y * z + 2 * x * w;
	iMatrixR[2][2] = 1 - 2 * pow(x, 2) - 2 * pow(y, 2);
	iMatrixR[2][3] = 0;

	iMatrixR[3][0] = 0;
	iMatrixR[3][1] = 0;
	iMatrixR[3][2] = 0;
	iMatrixR[3][3] = 1;

	WriteToEditBox(hwnd, IDC_EDIT34, iMatrixR[0][0]);
	WriteToEditBox(hwnd, IDC_EDIT35, iMatrixR[0][1]);
	WriteToEditBox(hwnd, IDC_EDIT36, iMatrixR[0][2]);
	WriteToEditBox(hwnd, IDC_EDIT37, iMatrixR[0][3]);

	WriteToEditBox(hwnd, IDC_EDIT38, iMatrixR[1][0]);
	WriteToEditBox(hwnd, IDC_EDIT39, iMatrixR[1][1]);
	WriteToEditBox(hwnd, IDC_EDIT40, iMatrixR[1][2]);
	WriteToEditBox(hwnd, IDC_EDIT41, iMatrixR[1][3]);

	WriteToEditBox(hwnd, IDC_EDIT42, iMatrixR[2][0]);
	WriteToEditBox(hwnd, IDC_EDIT43, iMatrixR[2][1]);
	WriteToEditBox(hwnd, IDC_EDIT44, iMatrixR[2][2]);
	WriteToEditBox(hwnd, IDC_EDIT45, iMatrixR[2][3]);

	WriteToEditBox(hwnd, IDC_EDIT46, iMatrixR[3][0]);
	WriteToEditBox(hwnd, IDC_EDIT47, iMatrixR[3][1]);
	WriteToEditBox(hwnd, IDC_EDIT48, iMatrixR[3][2]);
	WriteToEditBox(hwnd, IDC_EDIT49, iMatrixR[3][3]);
}

void CSlerp::ConvertB()
{
	GetB();

	int w = QuatB.z;
	int x = QuatB.w;
	int y = QuatB.x;
	int z = QuatB.y;

	iMatrixR[0][0] = 1 - 2 * pow(y, 2) - 2 * pow(z, 2);
	iMatrixR[0][1] = 2 * x * y - 2 * z * w;
	iMatrixR[0][2] = 2 * x * z + 2 * y * w;
	iMatrixR[0][3] = 0;

	iMatrixR[1][0] = 2 * x * y + 2 * z * w;
	iMatrixR[1][1] = 1 - 2 * pow(x, 2) - 2 * pow(z, 2);
	iMatrixR[1][2] = 2 * y * z - 2 * x * w;
	iMatrixR[1][3] = 0;

	iMatrixR[2][0] = 2 * x * z - 2 * y * w;
	iMatrixR[2][1] = 2 * y * z + 2 * x * w;
	iMatrixR[2][2] = 1 - 2 * pow(x, 2) - 2 * pow(y, 2);
	iMatrixR[2][3] = 0;

	iMatrixR[3][0] = 0;
	iMatrixR[3][1] = 0;
	iMatrixR[3][2] = 0;
	iMatrixR[3][3] = 1;

	WriteToEditBox(hwnd, IDC_EDIT34, iMatrixR[0][0]);
	WriteToEditBox(hwnd, IDC_EDIT35, iMatrixR[0][1]);
	WriteToEditBox(hwnd, IDC_EDIT36, iMatrixR[0][2]);
	WriteToEditBox(hwnd, IDC_EDIT37, iMatrixR[0][3]);

	WriteToEditBox(hwnd, IDC_EDIT38, iMatrixR[1][0]);
	WriteToEditBox(hwnd, IDC_EDIT39, iMatrixR[1][1]);
	WriteToEditBox(hwnd, IDC_EDIT40, iMatrixR[1][2]);
	WriteToEditBox(hwnd, IDC_EDIT41, iMatrixR[1][3]);

	WriteToEditBox(hwnd, IDC_EDIT42, iMatrixR[2][0]);
	WriteToEditBox(hwnd, IDC_EDIT43, iMatrixR[2][1]);
	WriteToEditBox(hwnd, IDC_EDIT44, iMatrixR[2][2]);
	WriteToEditBox(hwnd, IDC_EDIT45, iMatrixR[2][3]);

	WriteToEditBox(hwnd, IDC_EDIT46, iMatrixR[3][0]);
	WriteToEditBox(hwnd, IDC_EDIT47, iMatrixR[3][1]);
	WriteToEditBox(hwnd, IDC_EDIT48, iMatrixR[3][2]);
	WriteToEditBox(hwnd, IDC_EDIT49, iMatrixR[3][3]);
}

void CSlerp::ConvertSlerp()
{
	int i = 1;

	SlerpABT();

	int w = QuatR.z;
	int x = QuatR.w;
	int y = QuatR.x;
	int z = QuatR.y;

	iMatrixR[0][0] = 1 - 2 * pow(y, 2) - 2 * pow(z, 2);
	iMatrixR[0][1] = 2 * x * y - 2 * z * w;
	iMatrixR[0][2] = 2 * x * z + 2 * y * w;
	iMatrixR[0][3] = 0;

	iMatrixR[1][0] = 2 * x * y + 2 * z * w;
	iMatrixR[1][1] = 1 - 2 * pow(x, 2) - 2 * pow(z, 2);
	iMatrixR[1][2] = 2 * y * z - 2 * x * w;
	iMatrixR[1][3] = 0;

	iMatrixR[2][0] = 2 * x * z - 2 * y * w;
	iMatrixR[2][1] = 2 * y * z + 2 * x * w;
	iMatrixR[2][2] = 1 - 2 * pow(x, 2) - 2 * pow(y, 2);
	iMatrixR[2][3] = 0;

	iMatrixR[3][0] = 0;
	iMatrixR[3][1] = 0;
	iMatrixR[3][2] = 0;
	iMatrixR[3][3] = 1;

	WriteToEditBox(hwnd, IDC_EDIT34, iMatrixR[0][0]);
	WriteToEditBox(hwnd, IDC_EDIT35, iMatrixR[0][1]);
	WriteToEditBox(hwnd, IDC_EDIT36, iMatrixR[0][2]);
	WriteToEditBox(hwnd, IDC_EDIT37, iMatrixR[0][3]);

	WriteToEditBox(hwnd, IDC_EDIT38, iMatrixR[1][0]);
	WriteToEditBox(hwnd, IDC_EDIT39, iMatrixR[1][1]);
	WriteToEditBox(hwnd, IDC_EDIT40, iMatrixR[1][2]);
	WriteToEditBox(hwnd, IDC_EDIT41, iMatrixR[1][3]);

	WriteToEditBox(hwnd, IDC_EDIT42, iMatrixR[2][0]);
	WriteToEditBox(hwnd, IDC_EDIT43, iMatrixR[2][1]);
	WriteToEditBox(hwnd, IDC_EDIT44, iMatrixR[2][2]);
	WriteToEditBox(hwnd, IDC_EDIT45, iMatrixR[2][3]);

	WriteToEditBox(hwnd, IDC_EDIT46, iMatrixR[3][0]);
	WriteToEditBox(hwnd, IDC_EDIT47, iMatrixR[3][1]);
	WriteToEditBox(hwnd, IDC_EDIT48, iMatrixR[3][2]);
	WriteToEditBox(hwnd, IDC_EDIT49, iMatrixR[3][3]);
}
