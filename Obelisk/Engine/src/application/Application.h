#pragma once

#include "Common.h"

namespace Obelisk {
	class OBLAPI Application {
	public:
		Application();
		~Application();

		Application(const Application&)            = delete;
		Application(Application&&)                 = delete;
		Application& operator=(const Application&) = delete;

		void Init();
		void Shutdown();
		
		void Run();
	};
}