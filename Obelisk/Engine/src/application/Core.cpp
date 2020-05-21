#include "oblpch.h"
#include "Core.h"

#include "Utility/Time.h"

void ObeliskApp_Init() {
	// Direct input and output to the console
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	Obelisk::Time::Init();
}

void ObeliskApp_Shutdown() {
	
}

void ObeliskApp_Update() {
	Obelisk::Time::Update();
}

void ObeliskApp_Render() {
	
}
