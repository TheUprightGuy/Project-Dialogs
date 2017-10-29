#ifndef __SLERP_H__
#define __SLERP_H__

class CSlerp
{
public:
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

};

#endif //__SLERP_H__