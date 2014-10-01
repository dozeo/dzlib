#include "dzlib/console_helpers.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include <ios>
#include <iostream>

namespace dz
{
	void alloc_console_if_possible()
	{
#ifdef _WIN32
		// exit if we already have a console
		if (AllocConsole() == false)
			return;

		// redirect unbuffered STDOUT to the console
		{
			auto lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
			auto hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
			auto fp = _fdopen(hConHandle, "w");
			*stdout = *fp;
			setvbuf(stdout, NULL, _IONBF, 0);
		}

		// redirect unbuffered STDIN to the console
		{
			auto lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
			auto hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
			auto fp = _fdopen( hConHandle, "r" );
			*stdin = *fp;
			setvbuf( stdin, NULL, _IONBF, 0 );
		}

		// redirect unbuffered STDERR to the console
		{
			auto lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
			auto hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
			auto fp = _fdopen( hConHandle, "w" );
			*stderr = *fp;
			setvbuf( stderr, NULL, _IONBF, 0 );
		}

		// make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog
		// point to console as well
		std::ios::sync_with_stdio();
#endif
	}
}
