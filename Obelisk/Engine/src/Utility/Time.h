#pragma once

namespace Obelisk {
	namespace Detail {
		class TimeImpl;
	}

	class OBLAPI Time {
		friend class Application;
	public:
		Time()                       = delete;
		~Time()                      = delete;
		Time(const Time&)            = delete;
		Time(Time&&)                 = delete;
		Time& operator=(const Time&) = delete;

		/**
		 * \brief The in-game time since the game started playing.
		 * \return The in-game time in seconds since the start of the game.
		 */
		static float ElapsedTime();

		/**
		 * \brief The real world time since the game started playing.
		 * \return The real world time in seconds since the start of the game.
		 */
		static float UnscaledElapsedTime();

		/**
		 * \brief The in-game time that has passed since the last frame.
		 * \return The in-game time in seconds that has passed since the last frame.
		 */
		static float DeltaTime();

		/**
		 * \brief The real world time that has passed since the last frame.
		 * \return The real world time in seconds that has passed since the last frame.
		 */
		static float UnscaledDeltaTime();

		/**
		 * \brief The fixed timestep that the physics uses to step the simulation.
		 * \return The time in seconds that physics steps the simulation every frame.
		 */
		static float FixedDeltaTime();

		/**
		 * \brief The factor by which in-game time is scaled.
		 * \return The factor by which in-game time is scaled.
		 */
		static float TimeScale();
		
		/**
		 * \brief Set the scale at which in-game time will pass
		 * \param a_scale The factor by which time will be scaled.
		 * \return The new timescale.
		 */
		static float SetTimeScale(float a_scale);
		
	private:
		static void  Init();
		static void  Update();

		static void  Reset();
		
	private:
		static Detail::TimeImpl* s_timeImpl;
	};

	namespace Detail {
		class TimeImpl {
			friend Time;
		public:
			virtual ~TimeImpl() = default;;

			TimeImpl(const TimeImpl&) = delete;
			TimeImpl(TimeImpl&&) = delete;
			TimeImpl& operator=(const TimeImpl&) = delete;

		protected:
			TimeImpl() = default;
			
			virtual void  Init()   = 0;
			virtual void  Update() = 0;

		protected:
			float              m_deltaTime             = 0.0f;
			float              m_unscaledDeltaTime     = 0.0f;
			float              m_fixedDeltaTime        = 1.0f / 60.0f;
					             					   
			float              m_elapsedTime           = 0.0f;
			float              m_unscaledElapsedTime   = 0.0f;
			float              m_elapsedTimeDifference = 0.0f;

			float              m_timeScale             = 1.0f;
			std::atomic<float> m_timeScaleHint         = 1.0f;
		};
	}
}
