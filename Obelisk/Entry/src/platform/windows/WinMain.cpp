#include <cstdio>
#include <application/Application.h>

#if defined _WIN32

#include <Windows.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
) {
	(void) hInstance;
	(void) hPrevInstance;
	(void) lpCmdLine;
	(void) nShowCmd;
	
#if !defined(OBL_RELEASE)
	// Attach to the console if launched from the command line, otherwise create one
    if (!AttachConsole(ATTACH_PARENT_PROCESS))
        AllocConsole();
#endif

	Obelisk::Application app = {};
	app.Init();
	app.Run();
	app.Shutdown();

	// TEMPORARY
	getchar();

#if !defined(OBL_RELEASE)
	// Free the console once we're done with it
	FreeConsole();
#endif
	
	return 0;
}

#endif