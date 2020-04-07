#include "oblpch.hpp"

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
    if (!AttachConsole(ATTACH_PARENT_PROCESS))
        AllocConsole();
    freopen("CONIN$",  "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
#endif

	std::cout << "Lmao\n";
	std::cerr << "Also Lmao";
	
	getchar();

	return 0;
}
