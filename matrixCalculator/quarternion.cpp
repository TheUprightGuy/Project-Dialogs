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
