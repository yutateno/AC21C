#pragma once
#include "SceneBase.hpp"

#include <memory>

namespace scene
{
	namespace over
	{
		class SceneOver : public SceneBase
		{
		public:
			SceneOver();
			virtual ~SceneOver();

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
