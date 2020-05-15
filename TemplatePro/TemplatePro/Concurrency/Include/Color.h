#pragma once
#include <iostream>
#include <ostream>
#include <Windows.h>

static void  SetConsoleColor(WORD wAttribute)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, wAttribute);
}

inline std::ostream& defcolor(std::ostream& ostr)
{
    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    return ostr;
}

inline std::ostream& green(std::ostream& ostr)
{
    SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    return ostr;
}

inline std::ostream& blue(std::ostream& ostr)
{
    SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    return ostr;
}

inline std::ostream& red(std::ostream& ostr)
{
    SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    return ostr;
}

inline std::ostream& lredcolor(std::ostream& ostr)
{
    SetConsoleColor(FOREGROUND_RED);
    return ostr;
}