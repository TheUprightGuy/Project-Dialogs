#include <math.h>

#include "sleeeerp.h"

CSlerp::CSlerp()
{
}

CSlerp::~CSlerp()
{
}

void CSlerp::GetA()
{
}

void CSlerp::GetB()
{
}

void CSlerp::GetT()
{
}

void CSlerp::SetSlerp()
{
}

void CSlerp::SlerpABT()
{
	GetA();
	GetB();

	GetT();

	
	float iCosine = ((QuatA.w * QuatB.w) + (QuatA.x * QuatB.x) + (QuatA.y * QuatB.y) + (QuatA.z * QuatB.z));

	if(iCosine < 0.0f)
	{
		QuatB.w = -QuatB.w;
		QuatB.x = -QuatB.x;
		QuatB.y= -QuatB.y;
		QuatB.z = -QuatB.z;
	}

	float f0, f1;
	if (iCosine > 0.99999f)
	{
		f0 = 1.0f - iIntParam;
		f1 = iIntParam;
	}
	else
	{
		float fSin = sqrt(1.0f - iCosine * iCosine);

		float fOmega = atan2(fSin, iCosine);

		float oneOverSinOmega = 1.0f / fSin;

		f0 = sin((1.0f - iIntParam) * fOmega) * oneOverSinOmega;
		f1 = sin(iIntParam * fOmega) * oneOverSinOmega;
	}

	QuatR.w = QuatA.w*f0 + QuatB.w*f1;
	QuatR.x = QuatA.x*f0 + QuatB.x*f1;
	QuatR.y = QuatA.y*f0 + QuatB.y*f1;
	QuatR.z = QuatA.z*f0 + QuatB.z*f1;
}

void CSlerp::ConvertA()
{
}

void CSlerp::ConvertB()
{
}

void CSlerp::ConvertSlerp()
{
}
