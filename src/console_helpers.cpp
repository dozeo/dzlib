#include "dzlib/console_helpers.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include <ios>
#include <iostream>
#include <slog/slog.h>

#ifdef _MSC_VER
#undef isatty
#undef fileno
#define isatty _isatty
#define fileno _fileno
#endif

namespace dz
{
	void alloc_console_if_possible()
	{
#ifdef _WIN32
		//// already a terminal
		//if (isatty(fileno(stdin)))
		//	return;
		FreeConsole();

		// exit if we already have a console
		if (AllocConsole() == false)
		{
			slog::info() << "Already have console.. will not allocate a new one";
			return;
		}

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
