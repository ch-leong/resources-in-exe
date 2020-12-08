#include <iostream>
#include <Windows.h>
#include "resource.h"

bool ReadFileFromResource(HMODULE hInstance, WORD resourceID)//, char const* sFilename)
{
    if (!hInstance)
        return false;

    //HANDLE hFile = CreateFile((LPCWSTR)sFilename, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    //if (!hFile)
    //    return false;

    HRSRC hResource = FindResource(hInstance, MAKEINTRESOURCE(resourceID), L"FILE");
    if (!hResource)
        return false;

    HGLOBAL hFileResource = LoadResource(hInstance, hResource);
    if (!hFileResource)
        return false;

    LPVOID lpFile = LockResource(hFileResource);
    if (!lpFile)
        return false;

    //DWORD dwSize = SizeofResource(hInstance, hResource);
    //HANDLE hFilemap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, dwSize, NULL);
    //if (!hFilemap)
    //    return false;

    //LPVOID lpBaseAddress = MapViewOfFile(hFilemap, FILE_MAP_WRITE, 0, 0, 0);
    //if (!lpBaseAddress)
    //    return false;

    //CopyMemory(lpBaseAddress, lpFile, dwSize);
    std::cout << (char const*)lpFile << "\n";

    //UnmapViewOfFile(lpBaseAddress);
    //CloseHandle(hFilemap);
    //CloseHandle(hFile);

    return true;
}

int main()
{
    ReadFileFromResource(GetModuleHandle(NULL), IDR_FILE_DATA1);//, "data1.txt");
    ReadFileFromResource(GetModuleHandle(NULL), IDR_FILE_DATA2);//, "data2.txt");

    system("PAUSE");
    return 0;
}
