# dxerr
DirectX Error Library. Forked from https://github.com/microsoft/DXUT/tree/main/Core/dxerr.[cpp, h] with MBCS, Windows 11 Platform SDK, and GDK support added.

July 2025: Fixed a problem where DXGetErrorString( hresult ) was returning
(for example) "((HRESULT)0x887A0001L)" instead of DXGI_ERROR_INVALID_CALL or
"3L" instead of ERROR_PATH_NOT_FOUND.