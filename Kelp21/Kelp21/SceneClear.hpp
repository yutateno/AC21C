#pragma once
#include "SceneBase.hpp"

#include <memory>

namespace scene
{
	namespace clear
	{
		class SceneClear : public SceneBase
		{
		public:
			SceneClear();
			virtual ~SceneClear();

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
