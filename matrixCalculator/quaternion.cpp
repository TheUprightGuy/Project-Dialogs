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

void CQuater::QADotB()
{
	GetQuaterA();
	GetQuaterB();

	QuatR.w = QuatA.w * QuatB.w;
	QuatR.x = QuatA.x * QuatB.x;
	QuatR.y = QuatA.y * QuatB.y;
	QuatR.z = QuatA.z * QuatB.z;

	SetQuaterR();
}