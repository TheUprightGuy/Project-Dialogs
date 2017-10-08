//#include <iostream>
//#include <windows.h>
//
//#include "matrix.h"
//
//using namespace std;
//
//int _ADeterminant = 0;
//
//int test()
//{
//	if (_ADeterminant == 0)
//	{
//		MessageBox(nullptr, TEXT("Matrix has no inverse."), TEXT( "Message" ), MB_OK );
//	}
//	else
//	{
//		int i, j, k, n;
//		float a[10][10] = { 0 }, d;
//		n = 4;
//		for (i = 1; i <= n; i++)
//			for (j = 1; j <= n; j++)
//				a[i][j] = iMatrixA[i][j];
//
//		for (i = 1; i <= n; i++)
//			for (j = 1; j <= 2 * n; j++)
//				if (j == (i + n))
//					a[i][j] = 1;
//
//		/************** partial pivoting **************/
//		for (i = n; i > 1; i--)
//		{
//			if (a[i - 1][1] < a[i][1])
//				for (j = 1; j <= n * 2; j++)
//				{
//					d = a[i][j];
//					a[i][j] = a[i - 1][j];
//					a[i - 1][j] = d;
//				}
//		}
//		/********** reducing to diagonal  matrix ***********/
//
//		for (i = 1; i <= n; i++)
//		{
//			for (j = 1; j <= n * 2; j++)
//				if (j != i)
//				{
//					d = a[j][i] / a[i][i];
//					for (k = 1; k <= n * 2; k++)
//						a[j][k] -= a[i][k] * d;
//				}
//		}
//		/************** reducing to unit matrix *************/
//		for (i = 1; i <= n; i++)
//		{
//			d = a[i][i];
//			for (j = 1; j <= n * 2; j++)
//				a[i][j] = a[i][j] / d;
//		}
//
//		for (i = 1; i <= n; i++)
//		{
//			for (j = n + 1; j <= n * 2; j++)
//				cout << a[i][j] = iMatrixR[i][j];
//		}
//	}
//}
