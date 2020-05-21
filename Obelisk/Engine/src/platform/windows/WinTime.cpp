#include "oblpch.h"

#include "WinTime.h"

#include <Windows.h>

namespace Obelisk::Detail {

	void WinTime::Init() {
		LARGE_INTEGER li;
		QueryPerformanceFrequency(&li);
		m_frequency = static_cast<float>(li.QuadPart);

		QueryPerformanceCounter(&li);
		m_timeStart = li.QuadPart;
		m_lastTime  = li.QuadPart;
	}
	
	void WinTime::Update() {
		const int nFramesToHold = 10;

		static float prevFrames[nFramesToHold]{ 0.0f };
		static int   prevFrameIndex = 0;
		
		m_timeScale = m_timeScaleHint;

		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);

		m_unscaledElapsedTime = static_cast<float>(li.QuadPart - m_timeStart) / m_frequency;

		float currentDeltaTime = static_cast<float>(li.QuadPart - m_lastTime) / m_frequency;

		prevFrames[prevFrameIndex++] = std::clamp(currentDeltaTime, 0.0f, 1.0f);

		float sum = 0.0f;
		for (float frame : prevFrames) {
			sum += frame;
		}

		if (m_nFramesPassed < nFramesToHold) {
			sum /= static_cast<float>(++m_nFramesPassed);
		} else {
			sum /= nFramesToHold;
		}
		
		prevFrameIndex %= 10;

		m_unscaledDeltaTime = sum;

		m_deltaTime = m_unscaledDeltaTime * m_timeScale;

		m_elapsedTimeDifference += m_deltaTime - m_unscaledDeltaTime;

		m_elapsedTime = m_unscaledElapsedTime + m_elapsedTimeDifference;

		m_lastTime = li.QuadPart;
	}

	void WinTime::Mark() {
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);

		m_lastTime = li.QuadPart;
	}
}
