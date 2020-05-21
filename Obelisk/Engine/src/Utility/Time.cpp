#include "oblpch.h"

#include "Time.h"

#include "platform/windows/WinTime.h"

namespace Obelisk {
	Detail::TimeImpl* Time::s_timeImpl = nullptr;

	float Time::ElapsedTime() {
		return s_timeImpl->m_elapsedTime;
	}
	
	float Time::UnscaledElapsedTime() {
		return s_timeImpl->m_unscaledElapsedTime;
	}

	float Time::DeltaTime() {
		return s_timeImpl->m_deltaTime;
	}

	float Time::UnscaledDeltaTime() {
		return s_timeImpl->m_unscaledDeltaTime;
	}

	float Time::FixedDeltaTime() {
		return s_timeImpl->m_fixedDeltaTime;
	}

	float Time::TimeScale() {
		return s_timeImpl->m_timeScale;
	}

	float Time::SetTimeScale(float a_scale) {
		return s_timeImpl->m_timeScaleHint = a_scale;
	}

	void Time::Init() {
		Reset();
		s_timeImpl->Init();
	}

	void Time::Update() {
		s_timeImpl->Update();
	}

	void Time::Mark() {
		s_timeImpl->Mark();
	}

	void Time::Reset() {
		delete s_timeImpl;
		s_timeImpl = nullptr;

		s_timeImpl = new Detail::WinTime;
	}
}
