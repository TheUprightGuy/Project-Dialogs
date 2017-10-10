#ifndef __QUARTERNION_H__
#define __QUARTERNION_H__

#include <windows.h>

class CQuarter
{
public:
	CQuarter(HWND _hwnd);
	~CQuarter();

	void GetQuarterA();
	void GetQuarterB();
	void SetQuarterR();

	void QAdd();
	void QMinusAB();
	void QMinusBA();
	void QMultiAB();
	void QMultiBA();

private:

};

#endif // __QUARTERNION_H__