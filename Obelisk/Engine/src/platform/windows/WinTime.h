#pragma once

#include "Utility/Time.h"

namespace Obelisk::Detail {
	class WinTime final : public TimeImpl {
	public:
		virtual ~WinTime() = default;

	protected:
		void Init() override;
		void Update() override;
		void Mark() override;

	private:
		uint64_t m_timeStart = 0ull;
		uint64_t m_lastTime  = 0ull;
		float    m_frequency = 0.0f;

		int      m_nFramesPassed = 0;
	};
}