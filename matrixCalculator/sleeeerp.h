#ifndef __SLERP_H__
#define __SLERP_H__

#include <Windows.h>

typedef struct QUAT
{
	int w;
	int x;
	int y;
	int z;
} Quaternion;


class CSlerp
{
public:
	CSlerp(HWND _hwnd) { hwnd = _hwnd; }
	CSlerp();
	~CSlerp();

	void GetA();
	void GetB();
	void GetT();
	void SetSlerp();

	void SlerpABT();
	void ConvertA();
	void ConvertB();
	void ConvertSlerp();

private:
	HWND hwnd;

	Quaternion QuatA;
	Quaternion QuatB;

	int iMatrixR[4][4];
};

#endif //__SLERP_H__