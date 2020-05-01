#include "oblpch.h"
#include "Application.h"

static bool g_initialized = false;

namespace Obelisk {
	Application::Application() {
		OBL_ASSERT(g_initialized == false);
		g_initialized = true;
	}

	Application::~Application() {
		g_initialized = false;
	}

	void Application::Init() {
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
	}

	void Application::Shutdown() {
		
	}

	void Application::Run() {
		
	}
}