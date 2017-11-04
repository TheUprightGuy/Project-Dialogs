#ifndef __TRANSFORMATION_H__
#define __TRANSFORMATION_H__

#include <Windows.h>

typedef struct COORDS
{
	int iX;
	int iY;
	int iZ;
}Coordinates;

class CTrans
{
public:
	CTrans(HWND _hwnd) { m_hwnd = _hwnd; }
	~CTrans();

	/*Set the matrices*/
	void ReadColMatrix(); //Column Major 
	void ReadRowMatrix(); //Row Major

	/*Read Various Coords of Transforms*/
	void ReadScaleXYZ();
	void ReadTransXYZ();
	void ReadRotXYZ(); //Plus the degrees
	void ReadProj(); //Axis will be read by radio boxes, let jack handle that

	//Not sure how Row and Col are different, (order of operations??), but it looks like we'll be doing calcs for each one, 
	//e.g concatenate row by row, for the equation, display, then do columnn major

	/*These put the respective matrices into the two matrices at the bottom of the window*/
	void SetIdentity();
	void SetScaleMatrix();
	void SetTransMatrix();
	void SetRotateMatrix(); 
	void SetProjectMatrix(); 

	/*These calculate then input to matrices*/
	void ScaleByPrevious();
	void TransByPrevious(); //DID YOU ASSUME MY GENDER
	void RotateByPrevious(); //Don't forget to get angle of rotation
	void ProjectByPrevious();


private:
	int m_iMatrixCol[4][4];
	int m_iMatrixRow[4][4];

	Coordinates m_ScaleXYZ;
	Coordinates m_TransXYZ;
	Coordinates m_RotateXYZ;
	
	int m_iAngleOfRot;

	int m_iProjAxis; //0 = NULL, x == 1, y ==2, z == 3;
	int m_iProjDistance;

	HWND m_hwnd;
};

#endif //_TRANSFORMATION_H__