#pragma once

#include "Common.h"

namespace Obelisk {

	/**
	 * \class Application
	 * \brief The base of the entire application. 
	 *
	 * \details 
	 */
	class OBLAPI Application {
	public:
		Application();
		~Application();

		Application(const Application&)            = delete;
		Application(Application&&)                 = delete;
		Application& operator=(const Application&) = delete;

		/**
		 * \brief Initializes the application when first opened.
		 */
		void Init();

		/**
		 * \brief Cleans up any resources that the application consumed.
		 */
		void Shutdown();
		
		/**
		 * \brief The main loop of the application.
		 */
		void Run();

	private:
		bool m_running = true;
	};
}