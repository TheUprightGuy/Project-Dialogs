#include "quaternion.h"
#include "utils.h"
#include "resource.h"

void CQuater::GetQuaterA()
{
	QuatA.w = utils::ReadFromEditBox(hwnd, IDC_EDIT1);
	QuatA.x = utils::ReadFromEditBox(hwnd, IDC_EDIT2);
	QuatA.y = utils::ReadFromEditBox(hwnd, IDC_EDIT3);
	QuatA.z = utils::ReadFromEditBox(hwnd, IDC_EDIT4);
}

void CQuater::GetQuaterB()
{
	QuatB.w = utils::ReadFromEditBox(hwnd, IDC_EDIT5);
	QuatB.x = utils::ReadFromEditBox(hwnd, IDC_EDIT6);
	QuatB.y = utils::ReadFromEditBox(hwnd, IDC_EDIT7);
	QuatB.z = utils::ReadFromEditBox(hwnd, IDC_EDIT8);
}

void CQuater::SetQuaterR()
{
	utils::WriteToEditBox(hwnd, IDC_EDIT10, QuatR.w);
	utils::WriteToEditBox(hwnd, IDC_EDIT11, QuatR.x);
	utils::WriteToEditBox(hwnd, IDC_EDIT12, QuatR.y);
	utils::WriteToEditBox(hwnd, IDC_EDIT13, QuatR.z);
}

void CQuater::QAdd()
{
	GetQuaterA();
	GetQuaterB();

	QuatR.w = QuatA.w + QuatB.w;
	QuatR.x = QuatA.x + QuatB.x;
	QuatR.y = QuatA.y + QuatB.y;
	QuatR.z = QuatA.z + QuatB.z;

	SetQuaterR();
}

void CQuater::QMinusAB()
{
	GetQuaterA();
	GetQuaterB();

	QuatR.w = QuatA.w - QuatB.w;
	QuatR.x = QuatA.x - QuatB.x;
	QuatR.y = QuatA.y - QuatB.y;
	QuatR.z = QuatA.z - QuatB.z;

	SetQuaterR();
}

void CQuater::QMinusBA()
{
	GetQuaterA();
	GetQuaterB();

	QuatR.w = QuatB.w - QuatA.w;
	QuatR.x = QuatB.x - QuatA.x;
	QuatR.y = QuatB.y - QuatA.y;
	QuatR.z = QuatB.z - QuatA.z;

	SetQuaterR();
}

void CQuater::QMultiAB()
{
	GetQuaterA();
	GetQuaterB();

	QuatR.w = (QuatA.w * QuatB.w) -
		(QuatA.x * QuatB.x) -
		(QuatA.y * QuatB.y) -
		(QuatA.z * QuatB.z);

	QuatR.x = (QuatA.w * QuatB.x) +
		(QuatA.x * QuatB.w) +
		(QuatA.y * QuatB.z) -
		(QuatA.z * QuatB.y);

	QuatR.y = (QuatA.w * QuatB.y) -
		(QuatA.x * QuatB.z) +
		(QuatA.y * QuatB.w) +
		(QuatA.z * QuatB.x);

	QuatR.z = (QuatA.w * QuatB.z) +
		(QuatA.x * QuatB.y) -
		(QuatA.y * QuatB.x) +
		(QuatA.z * QuatB.w);

	SetQuaterR();
}

void CQuater::QMultiBA()
{
	GetQuaterA();
	GetQuaterA();

	QuatR.w = (QuatB.w * QuatA.w) -
		(QuatB.x * QuatA.x) -
		(QuatB.y * QuatA.y) -
		(QuatB.z * QuatA.z);

	QuatR.x = (QuatB.w * QuatA.x) +
		(QuatB.x * QuatA.w) +
		(QuatB.y * QuatA.z) -
		(QuatB.z * QuatA.y);

	QuatR.y = (QuatB.w * QuatA.y) -
		(QuatB.x * QuatA.z) +
		(QuatB.y * QuatA.w) +
		(QuatB.z * QuatA.x);

	QuatR.z = (QuatB.w * QuatA.z) +
		(QuatB.x * QuatA.y) -
		(QuatB.y * QuatA.x) +
		(QuatB.z * QuatA.w);

	SetQuaterR();
}

void CQuater::QMagnitudeA()
{
	int iMagnitude = sqrt(QuatA.w*QuatA.w + QuatA.x*QuatA.x + QuatA.y*QuatA.y + QuatA.z*QuatA.z);

	MessageBox(hwnd, utils::ToWideString(iMagnitude).c_str(), L"Magnitude", MB_OK);
}

void CQuater::QMagnitudeB()
{
	int iMagnitude = sqrt(QuatB.w*QuatB.w + QuatB.x*QuatB.x + QuatB.y*QuatB.y + QuatB.z*QuatB.z);

	MessageBox(hwnd, utils::ToWideString(iMagnitude).c_str(), L"Magnitude", MB_OK);
}

void CQuater::QDotProduct()
{
	GetQuaterA();
	GetQuaterA();

	int iDotProd = (QuatA.w * QuatB.w) +
		(QuatA.x * QuatB.x) +
		(QuatA.y * QuatB.y) +
		(QuatA.z * QuatB.z);

	MessageBox(hwnd, utils::ToWideString(iDotProd).c_str(), L"DotProduct", MB_OK);
}

void CQuater::QConjugateA()
{
	GetQuaterA();
	GetQuaterA();

	QuatR.w = QuatA.w;
	QuatR.x = -QuatA.x;
	QuatR.y = -QuatA.y;
	QuatR.z = -QuatA.z;

	SetQuaterR();
}

void CQuater::QConjugateB()
{
	GetQuaterA();
	GetQuaterA();

	QuatR.w = QuatA.w;
	QuatR.x = -QuatA.x;
	QuatR.y = -QuatA.y;
	QuatR.z = -QuatA.z;

	SetQuaterR();
}

void CQuater::QAInver()
{
	GetQuaterA();

	float QNorm = (QuatA.w * QuatA.w + QuatA.x * QuatA.x + QuatA.y * QuatA.y + QuatA.z * QuatA.z);
	float QInv = (QuatA.z / QNorm - QuatA.w / QNorm - QuatA.x / QNorm - QuatA.y / QNorm);

	MessageBox( hwnd, utils::ToWideString(QInv).c_str(), L"Quaternion A Inverse", MB_OK );
}

void CQuater::QBInver()
{
	GetQuaterB();

	float QNorm = (QuatB.w * QuatB.w + QuatB.x * QuatB.x + QuatB.y * QuatB.y + QuatB.z * QuatB.z);
	float QInv = (QuatB.z / QNorm - QuatB.w / QNorm - QuatB.x / QNorm - QuatB.y / QNorm);

	MessageBox( hwnd, utils::ToWideString(QInv).c_str(), L"Quaternion B Inverse", MB_OK );
}