#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include <windows.h>

class CQuater
{
public:
	CQuater(HWND _hwnd);
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

	void QAExpo();
	void QBExpo();
	void QADeter();
	void QBDeter();
	void QAInver();
	void QBInver();

	void QAScal();
	void QBScal();

private:

};

#endif // __QUATERNION_H__