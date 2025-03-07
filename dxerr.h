// Obtained from https://github.com/microsoft/DXUT/tree/main/Core/dxerr.h
// commit 3f6cfba8cf16e0f35781e7539274dfcdf85fd0f2
// MBCS and Windows 11 Platform SDK support added

//--------------------------------------------------------------------------------------
// File: DXErr.h
//
// DirectX Error Library
//
// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

#include <Windows.h>
#include <sal.h>

#ifdef __cplusplus
extern "C" {
#endif

//--------------------------------------------------------------------------------------
// DXGetErrorString
//--------------------------------------------------------------------------------------
const char* WINAPI DXGetErrorStringA( _In_ HRESULT hr );
const WCHAR* WINAPI DXGetErrorStringW( _In_ HRESULT hr );

#ifdef UNICODE
    #define DXGetErrorString DXGetErrorStringW
#else
    #define DXGetErrorString DXGetErrorStringA
#endif

//--------------------------------------------------------------------------------------
// DXGetErrorDescription has to be modified to return a copy in a buffer rather than
// the original static string.
//--------------------------------------------------------------------------------------
void WINAPI DXGetErrorDescriptionA( _In_ HRESULT hr, _Out_cap_(count) char* desc, _In_ size_t count );
void WINAPI DXGetErrorDescriptionW( _In_ HRESULT hr, _Out_cap_(count) WCHAR* desc, _In_ size_t count );

#ifdef UNICODE
    #define DXGetErrorDescription DXGetErrorDescriptionW
#else
    #define DXGetErrorDescription DXGetErrorDescriptionA
#endif

//--------------------------------------------------------------------------------------
//  DXTrace
//
//  Desc:  Outputs a formatted error message to the debug stream
//
//  Args:  TCHAR* strFile   The current file, typically passed in using the
//                         __FILEW__ macro.
//         DWORD dwLine    The current line number, typically passed in using the
//                         __LINE__ macro.
//         HRESULT hr      An HRESULT that will be traced to the debug stream.
//         CHAR* strMsg    A string that will be traced to the debug stream (may be NULL)
//         BOOL bPopMsgBox If TRUE, then a message box will popup also containing the passed info. Ignored in builds with _GAMING_XBOX set.
//
//  Return: The hr that was passed in.
//--------------------------------------------------------------------------------------
HRESULT WINAPI DXTraceA( _In_z_ const char* strFile, _In_ DWORD dwLine, _In_ HRESULT hr, _In_opt_z_ const char* strMsg, _In_ BOOL bPopMsgBox );
HRESULT WINAPI DXTraceW( _In_z_ const WCHAR* strFile, _In_ DWORD dwLine, _In_ HRESULT hr, _In_opt_ const WCHAR* strMsg, _In_ BOOL bPopMsgBox );

#ifdef UNICODE
    #define DXTrace DXTraceW
#else
    #define DXTrace DXTraceA
#endif

//--------------------------------------------------------------------------------------
//
// Helper macros
//
//--------------------------------------------------------------------------------------
#if defined(DEBUG) || defined(_DEBUG)
    #ifdef UNICODE
        #define DXTRACE_MSG(str)              DXTrace( __FILEW__, (DWORD)__LINE__, 0, str, false )
        #define DXTRACE_ERR(str,hr)           DXTrace( __FILEW__, (DWORD)__LINE__, hr, str, false )
        #define DXTRACE_ERR_MSGBOX(str,hr)    DXTrace( __FILEW__, (DWORD)__LINE__, hr, str, true )
    #else
        #define DXTRACE_MSG(str)              DXTrace( __FILE__, (DWORD)__LINE__, 0, str, false )
        #define DXTRACE_ERR(str,hr)           DXTrace( __FILE__, (DWORD)__LINE__, hr, str, false )
        #define DXTRACE_ERR_MSGBOX(str,hr)    DXTrace( __FILE__, (DWORD)__LINE__, hr, str, true )
    #endif
#else
    #define DXTRACE_MSG(str)              (0L)
    #define DXTRACE_ERR(str,hr)           (hr)
    #define DXTRACE_ERR_MSGBOX(str,hr)    (hr)
#endif

#ifdef __cplusplus
}
#endif //__cplusplus
