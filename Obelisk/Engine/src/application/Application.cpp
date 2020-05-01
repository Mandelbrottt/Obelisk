#include "oblpch.h"
#include "Application.h"

static bool g_created     = false;
static bool g_initialized = false;

namespace Obelisk {
	Application::Application() {
		OBL_ASSERT(g_created == false);
		g_created = true;
	}

	Application::~Application() {
		g_created = false;
	}

	void Application::Init() {
		OBL_ASSERT(g_initialized == false);
		g_initialized = true;

		// Direct input and output to the console
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		m_running = true;
	}

	void Application::Shutdown() {
		OBL_ASSERT(g_initialized == true);
		g_initialized = false;

		m_running = false;
	}

	void Application::Run() {
		while (m_running) {
			
		}
	}
}