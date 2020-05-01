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

	// Direct input and output to the console
    freopen("CONIN$",  "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
#endif

	Obelisk::Application* pApp;
	pApp = new Obelisk::Application;
	pApp->Init();
	pApp->Run();
	pApp->Shutdown();
	delete pApp;

	// TEMPORARY
	getchar();

	FreeConsole();
	
	return 0;
}

#endif