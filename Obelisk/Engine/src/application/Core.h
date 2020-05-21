#pragma once

#include "Common.h"

extern "C" {
	/**
     * \brief Initializes the entire engine once on startup.
     */
    extern void OBLAPI ObeliskApp_Init();

	/**
     * \brief Cleans up the entire engine once on shutdown.
     */
    extern void OBLAPI ObeliskApp_Shutdown();

	/**
	 * \brief Updates the engine once per frame.
	 */
	extern void OBLAPI ObeliskApp_Update();

	/**
	 * \brief Renders the engine to the screen once per frame.
	 */
	extern void OBLAPI ObeliskApp_Render();
}
