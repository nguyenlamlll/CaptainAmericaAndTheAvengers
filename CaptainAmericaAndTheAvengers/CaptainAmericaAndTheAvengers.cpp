//// CaptainAmericaAndTheAvengers.cpp : Defines the entry point for the application.
////
//
//#include <d3d9.h>
//#include <d3dx9.h>
#include "stdafx.h"
//#include "CaptainAmericaAndTheAvengers.h"
//#include "SceneManager.h"
//#include "GameError.h"
//#include "Game.h"
//// For detecting memory leaks
//#if defined(DEBUG) | defined(_DEBUG)
//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h>  
//#endif
//
//#ifdef _DEBUG
//#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#else
//#define new new
//#endif
//
//#define MAX_LOADSTRING 100
//
//// Global Variables:
//HINSTANCE hInst;                                // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
//
//// Forward declarations of functions included in this code module:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HWND&, HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//
//Game *game = NULL;
//HWND hwnd = NULL;
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//                     _In_opt_ HINSTANCE hPrevInstance,
//                     _In_ LPWSTR    lpCmdLine,
//                     _In_ int       nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//	// Memory leak detecting in debug mode.
//#if defined(DEBUG) | defined(_DEBUG)
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//#endif
//
//    // TODO: Place code here.
//
//    // Initialize global strings
//    //LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//    //LoadStringW(hInstance, IDC_CAPTAINAMERICAANDTHEAVENGERS, szWindowClass, MAX_LOADSTRING);
//    MyRegisterClass(hInstance);
//
//    // Perform application initialization:
//    if (!InitInstance (hwnd, hInstance, nCmdShow))
//    {
//        return FALSE;
//    }
//
//    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CAPTAINAMERICAANDTHEAVENGERS));
//
//    MSG msg;
//
//    // Main message loop:
//	try {
//		SceneManager::getInstance()->init(hwnd);
//		// main message loop
//		int done = 0;
//		while (!done)
//		{
//			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//			{
//				// look for quit message
//				if (msg.message == WM_QUIT)
//					done = 1;
//
//				// decode and pass messages on to WinProc
//				TranslateMessage(&msg);
//				DispatchMessage(&msg);
//			}
//			else
//			{
//				//game->run(hwnd);    // run the game loop
//				SceneManager::getInstance()->run();
//			}
//		}
//		//SAFE_DELETE(game);     // free memory before exit
//		SceneManager::getInstance()->deleteAll();
//		return msg.wParam;
//	}
//	catch (const GameError &err)
//	{
//		SceneManager::getInstance()->deleteAll();
//		//game->deleteAll();
//		DestroyWindow(hwnd);
//		MessageBox(NULL, err.getMessage(), "Error", MB_OK);
//	}
//	catch (...)
//	{
//		SceneManager::getInstance()->deleteAll();
//		//game->deleteAll();
//		DestroyWindow(hwnd);
//		MessageBox(NULL, "Unknown error occured in game.", "Error", MB_OK);
//	}
//    return 0;
//}
//
//
//
////
////  FUNCTION: MyRegisterClass()
////
////  PURPOSE: Registers the window class.
////
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style          = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc    = WndProc;
//    wcex.cbClsExtra     = 0;
//    wcex.cbWndExtra     = 0;
//    wcex.hInstance      = hInstance;
//    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CAPTAINAMERICAANDTHEAVENGERS));
//    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
//    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CAPTAINAMERICAANDTHEAVENGERS);
//    wcex.lpszClassName  = szWindowClass;
//    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}
//
////
////   FUNCTION: InitInstance(HINSTANCE, int)
////
////   PURPOSE: Saves instance handle and creates main window
////
////   COMMENTS:
////
////        In this function, we save the instance handle in a global variable and
////        create and display the main program window.
////
//BOOL InitInstance(HWND &hWnd, HINSTANCE hInstance, int nCmdShow)
//{
//   hInst = hInstance; // Store instance handle in our global variable
//
//   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//   if (!hWnd)
//   {  
//      return FALSE;
//   }
//
//   ShowWindow(hWnd, nCmdShow);
//   UpdateWindow(hWnd);
//
//   return TRUE;
//}
//
////
////  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
////
////  PURPOSE: Processes messages for the main window.
////
////  WM_COMMAND  - process the application menu
////  WM_PAINT    - Paint the main window
////  WM_DESTROY  - post a quit message and return
////
////
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	return (SceneManager::getInstance()->messageHandler(hwnd, message, wParam, lParam));
//    switch (message)
//    {
//    case WM_COMMAND:
//        {
//            int wmId = LOWORD(wParam);
//            // Parse the menu selections:
//            switch (wmId)
//            {
//            case IDM_ABOUT:
//                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//				
//                break;
//            case IDM_EXIT:
//                DestroyWindow(hWnd);
//                break;
//            default:
//                return DefWindowProc(hWnd, message, wParam, lParam);
//            }
//        }
//        break;
//    case WM_PAINT:
//        {
//            PAINTSTRUCT ps;
//            HDC hdc = BeginPaint(hWnd, &ps);
//            // TODO: Add any drawing code that uses hdc here...
//            EndPaint(hWnd, &ps);
//        }
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}

#pragma once

#include <Windows.h>
#include <stdlib.h>             // for detecting memory leaks
#include <crtdbg.h>             // for detecting memory leaks
#include "gameError.h"
#include "constants.h"
#include "Game.h"
#include "resource.h"
#include "SceneManager.h"

// Function prototypes
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HWND &, HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);

// Game pointer
Game *game = NULL;
HWND hwnd = NULL;

//=============================================================================
// Starting point for a Windows application
//=============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// Check for memory leak if debug build
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	MSG msg;

	// Create the game, sets up message handler
	//game = new Metroid;

	// Create the window
	if (!CreateMainWindow(hwnd, hInstance, nCmdShow))
		return 1;

	try {
		//game->initialize(hwnd);     // throws GameError
		SceneManager::getInstance()->init(hwnd);
		// main message loop
		int done = 0;
		while (!done)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// look for quit message
				if (msg.message == WM_QUIT)
					done = 1;

				// decode and pass messages on to WinProc
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				//game->run(hwnd);    // run the game loop
				SceneManager::getInstance()->run();
			}
		}
		//SAFE_DELETE(game);     // free memory before exit
		SceneManager::getInstance()->deleteAll();
		return msg.wParam;
	}
	catch (const GameError &err)
	{
		SceneManager::getInstance()->deleteAll();
		//game->deleteAll();
		DestroyWindow(hwnd);
		MessageBox(NULL, err.getMessage(), "Error", MB_OK);
	}
	catch (...)
	{
		SceneManager::getInstance()->deleteAll();
		//game->deleteAll();
		DestroyWindow(hwnd);
		MessageBox(NULL, "Unknown error occured in game.", "Error", MB_OK);
	}

	//SAFE_DELETE(game);     // free memory before exit
	return 0;
}

//=============================================================================
// window event callback function
//=============================================================================
LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//return (game->messageHandler(hwnd, msg, wParam, lParam));
	return (SceneManager::getInstance()->messageHandler(hwnd, msg, wParam, lParam));
}

//=============================================================================
// Create the window
// Returns: false on error
//=============================================================================
bool CreateMainWindow(HWND &hwnd, HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcx;

	// Fill in the window class structure with parameters 
	// that describe the main window. 
	wcx.cbSize = sizeof(wcx);           // size of structure 
	wcx.style = CS_HREDRAW | CS_VREDRAW;    // redraw if size changes 
	wcx.lpfnWndProc = WinProc;          // points to window procedure 
	wcx.cbClsExtra = 0;                 // no extra class memory 
	wcx.cbWndExtra = 0;                 // no extra window memory 
	wcx.hInstance = hInstance;          // handle to instance 
	wcx.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CAPTAINAMERICAANDTHEAVENGERS)); // icon
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);   // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);    // black background 
	wcx.lpszMenuName = NULL;           // name of menu resource 
	wcx.lpszClassName = CLASS_NAME;     // name of window class 
	wcx.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SMALL)); // small class icon

										// Register the window class. 
										// RegisterClassEx returns 0 on error.
	if (RegisterClassEx(&wcx) == 0)    // if error
		return false;

	//set up the screen in windowed or fullscreen mode?
	DWORD style;
	if (FULLSCREEN)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	// Create window
	hwnd = CreateWindow(
		CLASS_NAME,             // name of the window class
		GAME_TITLE,             // title bar text
		style,                  // window style
		CW_USEDEFAULT,          // default horizontal position of window
		CW_USEDEFAULT,          // default vertical position of window
		VIEWPORT_WIDTH,             // width of window
		VIEWPORT_HEIGHT,            // height of the window
		(HWND)NULL,            // no parent window
		(HMENU)NULL,           // no menu
		hInstance,              // handle to application instance
		(LPVOID)NULL);         // no window parameters

							   // if there was an error creating the window
	if (!hwnd)
		return false;

	if (!FULLSCREEN)             // if window
	{
		// Adjust window size so client area is GAME_WIDTH x GAME_HEIGHT
		RECT clientRect;
		GetClientRect(hwnd, &clientRect);   // get size of client area of window
		MoveWindow(hwnd,
			0,                                           // Left
			0,                                           // Top
			VIEWPORT_WIDTH + (VIEWPORT_WIDTH - clientRect.right),    // Right
			VIEWPORT_HEIGHT + (VIEWPORT_HEIGHT - clientRect.bottom), // Bottom
			TRUE);                                       // Repaint the window
	}

	// Show the window
	ShowWindow(hwnd, nCmdShow);

	return true;
}