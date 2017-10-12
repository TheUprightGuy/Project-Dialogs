#ifndef __QUARTERNION_H__
#define __QUARTERNION_H__

#include <windows.h>

typedef struct QUAT
{
	int w;
	int x;
	int y;
	int z;
} Quaternion;

class CQuarter
{
public:
	CQuarter(HWND _hwnd) { _hwnd = hwnd; }
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
	HWND hwnd;

	Quaternion QuatA;
	Quaternion QuatB;
	Quaternion QuatR;
};

#endif // __QUARTERNION_H__