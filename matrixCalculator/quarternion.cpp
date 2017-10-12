#include <math.h>

#include "quarternion.h"
#include "utils.h"
#include "resource.h"

void CQuarter::GetQuarterA()
{
	QuatA.w = utils::ReadFromEditBox(hwnd, IDC_EDIT1);
	QuatA.x = utils::ReadFromEditBox(hwnd, IDC_EDIT2);
	QuatA.y = utils::ReadFromEditBox(hwnd, IDC_EDIT3);
	QuatA.z = utils::ReadFromEditBox(hwnd, IDC_EDIT4);
}

void CQuarter::GetQuarterB()
{
	QuatB.w = utils::ReadFromEditBox(hwnd, IDC_EDIT5);
	QuatB.x = utils::ReadFromEditBox(hwnd, IDC_EDIT6);
	QuatB.y = utils::ReadFromEditBox(hwnd, IDC_EDIT7);
	QuatB.z = utils::ReadFromEditBox(hwnd, IDC_EDIT8);
}

void CQuarter::SetQuarterR()
{
	utils::WriteToEditBox(hwnd, IDC_EDIT10, QuatR.w);
	utils::WriteToEditBox(hwnd, IDC_EDIT11, QuatR.x);
	utils::WriteToEditBox(hwnd, IDC_EDIT12, QuatR.y);
	utils::WriteToEditBox(hwnd, IDC_EDIT13, QuatR.z);
}

void CQuarter::QMultiAB()
{
	GetQuarterA();
	GetQuarterB();

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

	SetQuarterR();
}

void CQuarter::QMultiBA()
{
	GetQuarterA();
	GetQuarterB();

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

	SetQuarterR();
}

void CQuarter::QMagnitudeA()
{
	int iMagnitude = sqrt(QuatA.w*QuatA.w + QuatA.x*QuatA.x + QuatA.y*QuatA.y + QuatA.z*QuatA.z);
	
	MessageBox(hwnd, utils::ToWideString(iMagnitude).c_str(), L"Magnitude", MB_OK);
}

void CQuarter::QMagnitudeB()
{
	int iMagnitude = sqrt(QuatB.w*QuatB.w + QuatB.x*QuatB.x + QuatB.y*QuatB.y + QuatB.z*QuatB.z);

	MessageBox(hwnd, utils::ToWideString(iMagnitude).c_str(), L"Magnitude", MB_OK);
}

void CQuarter::QDotProduct()
{
	GetQuarterA();
	GetQuarterB();

	int iDotProd =	(QuatA.w * QuatB.w) +
		(QuatA.x * QuatB.x) +
		(QuatA.y * QuatB.y) +
		(QuatA.z * QuatB.z);

	MessageBox(hwnd, utils::ToWideString(iDotProd).c_str(), L"DotProduct", MB_OK);
}

void CQuarter::QConjugateA()
{
	GetQuarterA();
	GetQuarterB();

	QuatR.w = QuatA.w;
	QuatR.x = -QuatA.x;
	QuatR.y = -QuatA.y;
	QuatR.z = -QuatA.z;
	
	SetQuarterR();
}

void CQuarter::QConjugateB()
{
	GetQuarterA();
	GetQuarterB();

	QuatR.w = QuatA.w;
	QuatR.x = -QuatA.x;
	QuatR.y = -QuatA.y;
	QuatR.z = -QuatA.z;

	SetQuarterR();
}
