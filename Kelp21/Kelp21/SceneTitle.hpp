#pragma once
#include "SceneBase.hpp"

#include <memory>

namespace scene
{
	namespace title
	{
		class SceneTitle : public SceneBase
		{
		public:
			SceneTitle();
			virtual ~SceneTitle();

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
