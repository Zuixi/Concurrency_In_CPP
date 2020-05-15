#pragma once

#include <Windows.h>
#include <string>
#include <iostream>
#include <tchar.h>

namespace MyCopyFile {

    LPCWSTR srcFile = _T("D:\\Documents\\awe.jpg");
    LPCWSTR destFile = _T("D:\\Documents\\APITest\\copy.jpg");


    BOOL CopyFileToDest(LPCWSTR srcfile, LPCWSTR destfile)
    {
        BOOL ret;

        ret = CopyFile(srcfile, destfile, true);

        if (ret == 0)
        {
            MessageBox(NULL, _T("Copy failed"), _T("COPY FILE"), NULL);
        }
        else
        {
            MessageBox(NULL, _T("Copy success"), _T("COPY FILE"), NULL);
        }

        return ret;
    }

    BOOL TestCopy()
    {
        BOOL ret;

        ret = CopyFileToDest(srcFile, destFile);

        return ret;
    }
}
