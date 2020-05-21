#include "oblpch.h"

#include "Application.h"

#include "Utility/Time.h"

#include "Core.h"

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

		m_running = true;

		ObeliskApp_Init();
	}

	void Application::Shutdown() {
		OBL_ASSERT(g_initialized == true);
		g_initialized = false;

		m_running = false;

		ObeliskApp_Shutdown();
	}

	void Application::Run() {
		while (m_running) {
			ObeliskApp_Update();
		}
	}
}