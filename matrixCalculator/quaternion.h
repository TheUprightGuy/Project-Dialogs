#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include <windows.h>

typedef struct QUAT
{
	int w;
	int x;
	int y;
	int z;
} Quaternion;

class CQuater
{
public:
	CQuater(HWND _hwnd) { _hwnd = hwnd; }
	~CQuater();

	void GetQuaterA();
	void GetQuaterB();
	void SetQuaterR();

	void QAdd();
	void QMinusAB();
	void QMinusBA();
	void QMultiAB();
	void QMultiBA();
	void QADotB();

//	void QAExpo();
//	void QBExpo();
//	void QADeter();
//	void QBDeter();

	void QMagnitudeA();
	void QMagnitudeB();

	void QDotProduct();

	void QConjugateA();
	void QConjugateB()

	void QAInver();
	void QBInver();

	void QAScal();
	void QBScal();

private:
	HWND hwnd;

	Quaternion QuatA;
	Quaternion QuatB;
	Quaternion QuatR;
};

#endif // __QUATERNION_H__