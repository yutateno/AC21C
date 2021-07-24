#pragma once
#include "SceneBase.hpp"

#include <memory>

namespace scene
{
	namespace game
	{
		class SceneGame : public SceneBase
		{
		public:
			SceneGame();
			virtual ~SceneGame();

			void init() override;
			void ctrl() override;
			void disp() override;
			void dest() override;

		private:
			struct Impl;
			std::unique_ptr<Impl> impl;
		};
	}
}
