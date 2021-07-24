#pragma once

namespace scene
{
	class SceneBase
	{
	public:
		enum class State {
			Title, Game, Over, Clear, Max,	// ÅESTARTÅAGOALÇ™Ç†ÇÈ
		};


		SceneBase() : m_state(State::Max) {}
		virtual ~SceneBase() {}


		virtual void init() {}
		virtual void ctrl() {}
		virtual void disp() {}
		virtual void dest() {}


		State get_state()
		{
			return m_state;
		}

	protected:
		State m_state;
	};
}
