//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Corey Freeman and Jack Belton
// Mail			: your.name@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN


#include "matrix.h"
#include "quaternion.h"
#include "GausElim.h"
#include "sleeeerp.h"
#include "transformation.h"

//#include "utils.h"
#include "resource.h"
#define WINDOW_CLASS_NAME L"WINCLASS1"

HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;
CMatrix* g_pMatrix = 0;
CQuater* g_pQuater = 0;
CGausElim* g_pGausElim = 0;
CSlerp* g_pSlerp = 0;
CTrans* g_pTrans = 0;

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

	// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
		break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
		break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{
			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
			//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			
			break;
		}
			//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
;
			break;
		}
			//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);

			
			break;
		}
		default:
			break;
		}
		return(0);
	}
		break;

	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
		break;

	default:break;
	} // End switch.

	// Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}

BOOL CALLBACK MatrixDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	//static CMatrix InputMatrix;

	

	static float _value;
	switch (_msg)
	{

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDOK6: //Multiply A
		{
			g_pMatrix->ScalarMult(1);
		}
		break;
		case IDOK10: //Multiply B
		{
			g_pMatrix->ScalarMult(0);
		}
		break;
		case IDCANCEL2: //Inverse A
		{
			g_pMatrix->MatrixInverse(1);
		}
		break;
		case IDCANCEL3: //Inverse B
		{
			g_pMatrix->MatrixInverse(0);
		}
		break;
		case IDOK9: //A Transpose
		{
			g_pMatrix->Transpose(1);
		}
		break;
		case IDOK11: //B Transpose
		{
			g_pMatrix->Transpose(0);
		}
		break;
		case IDOK3: // |A|
		{
			g_pMatrix->Get4DMatrixDetA();
		}
		break;
		case IDOK7: // |B|
		{
			g_pMatrix->Get4DMatrixDetB();
		}
		break;
		case IDOK4: // A -> I
		{
			g_pMatrix->MatrixToI(1);
		}
		break;
		case IDOK8: // B -> I
		{
			g_pMatrix->MatrixToI(0);
		}
		break;
		//Uses A and B into C
		case IDOK: // A + B
		{
			g_pMatrix->MatrixAdd();
		}
		break;
		case IDCANCEL: // A - B
		{
			g_pMatrix->MatrixSub();
		}
		break;
		case IDOK2: // A * B
		{
			g_pMatrix->MatrixMult(1);
		}
		break;
		case IDOK5: // B * A
		{
			g_pMatrix->MatrixMult(0);
		}
		break;
		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		//MessageBox(_hwnd, ToWideString(_value).c_str(), L"Value in A11", MB_OK);
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	HWND hwndComboBox = GetDlgItem(_hwnd, IDC_COMBO1);
	HWND hwndProjBox = GetDlgItem(_hwnd, IDC_COMBO2);
	static int iItemIndex;

	switch (_msg)
	{
	case WM_INITDIALOG:
	{
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Set Identity Matrix"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Set Scale Matrix"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Set Tranlation Matrix"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Set Rotation Matrix"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Set Projection Matrix"));

		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Scale by Previous"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Translation by Previous"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Rotation by Previous"));
		SendMessage(hwndComboBox, CB_ADDSTRING, NULL, (LPARAM)(L"Projection by Previous"));

		SendMessage(hwndProjBox, CB_ADDSTRING, NULL, (LPARAM)(L"X Axis"));
		SendMessage(hwndProjBox, CB_ADDSTRING, NULL, (LPARAM)(L"Y Axis"));
		SendMessage(hwndProjBox, CB_ADDSTRING, NULL, (LPARAM)(L"Z Axis"));
//		SendMessage(hwndProjBox, CB_SETCURSEL, 0, NULL);
	}
	break;
	case WM_COMMAND:
	{
		if (HIWORD(_wparam) == CBN_SELCHANGE)
		{
			iItemIndex = SendMessage(hwndComboBox, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
		
		}
		switch (LOWORD(_wparam))
		{
		case IDC_BUTTON4:
		{
			switch (iItemIndex)
			{
			case 0: //Identity Matrix
			{
				g_pTrans->SetIdentity();
			}
			break;
			case 1: //Scale
			{
				g_pTrans->SetScaleMatrix();
			}
			break;
			case 2: //Transformation
			{
				g_pTrans->SetTransMatrix();
			}
			break;
			case 3: //Rotation
			{
				g_pTrans->SetRotateMatrix();
			}
			break;
			case 4: //Projection
			{
				g_pTrans->SetProjectMatrix();
			}
			break;
			case 5: //Scale by Previous
			{
				g_pTrans->ScaleByPrevious();
			}
			break;
			case 6: //Translation by Previous
			{
				g_pTrans->TransByPrevious();
			}
			break;
			case 7: //Rotation by Previous
			{
				g_pTrans->RotateByPrevious();
			}
			break;
			case 8: //Projection by Previous
			{
				g_pTrans->ProjectByPrevious();
			}
			break;
			default:
				break;
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK GaussianDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			case IDC_BUTTON1:
			{
				g_pGausElim->RowMult();
			}
			break;
			case IDC_BUTTON2:
			{
				g_pGausElim->RowSwap();
			}
			break;
			case IDC_BUTTON3:
			{
				g_pGausElim->RowMult();
			}
			break;

			default:
				break;
		}
	}
	break;
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}


BOOL CALLBACK QuaternionDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_BUTTON1: // Add A and B
		{
			g_pQuater->QAdd();
		}
		break;
		case IDC_BUTTON5: // A Minus B
		{
			g_pQuater->QMinusAB();
		}
		break;
		case IDC_BUTTON6: // B Minus A
		{
			g_pQuater->QMinusBA();
		}
		break;
		case IDC_BUTTON2: // A multiplied by B;
		{
			g_pQuater->QMultiAB();
		}
		break;
		case IDC_BUTTON7: // B multiplied by A;
		{
			g_pQuater->QMultiBA();
		}
		break;
		case IDOK11: // Dot Product of A and B
		{
			g_pQuater->QDotProduct();
		}
		break;
		case IDOK3: // Conjugate A
		{
			g_pQuater->QConjugateA();
		}
		break;
		case IDOK7: // Conjugate B
		{
			g_pQuater->QConjugateB();
		}
		break;
		case IDOK4: // Magnitude A
		{
			g_pQuater->QMagnitudeA();
		}
		break;
		case IDOK8: // Magnitude B
		{
			g_pQuater->QMagnitudeB();
		}
		break;
		case IDOK: // Inverse of A
		{
			g_pQuater->QAInver();
		}
		break;
		case IDCANCEL: // Inverse of B
		{
			g_pQuater->QBInver();
		}
		break;
		case IDOK2: // A scaled by t
		{
//			g_pQuater->QAScal();
		}
		break;
		case IDOK5: // B scaled by t
		{
//			g_pQuater->QBScal();
		}
		break;
		default:
			break;
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK SLERPDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case IDC_BUTTON1:
		{
			g_pSlerp->SlerpABT();
		}
		break;
		case IDC_BUTTON2:
		{
			g_pSlerp->ConvertA();
		}
		break;
		case IDC_BUTTON3:
		{
			g_pSlerp->ConvertB();
		}
		break;
		case IDC_BUTTON4:
		{
			g_pSlerp->ConvertSlerp();
		}
		break;
		default:
			break;
		}
		return TRUE;
		break;
	}
	break;
	default:
		break;
	}
	return FALSE;
}

int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

	// First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground = //CreatePatternBrush(LoadBitmap(_hInstance, MAKEINTRESOURCE(IDB_BITMAP1)));
		static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Jack Belton & Corey Freeman",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 65,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, MatrixDlgProc);
	g_pMatrix = new CMatrix(g_hDlgMatrix);

	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, TransformationDlgProc);
	g_pTrans = new CTrans(g_hDlgTransformation);

	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, GaussianDlgProc);
	g_pGausElim = new CGausElim(g_hDlgGaussian);

	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, QuaternionDlgProc);
	g_pQuater = new CQuater(g_hDlgQuaternion);

	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, SLERPDlgProc);
	g_pSlerp = new CSlerp(g_hDlgSLERP);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}


