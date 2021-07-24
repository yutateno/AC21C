#include "SceneClear.hpp"

#include "DxLib.h"

#include "KeyInput.hpp"


namespace scene
{
	namespace clear
	{

#pragma region Impl
		struct SceneClear::Impl
		{
			Impl();
			~Impl();

			void init();
			void ctrl();
			void disp();
			void dest();

			bool get_is_next()
			{
				return m_is_next;
			}

		private:
			bool m_is_next;
		};

		SceneClear::Impl::Impl()
			: m_is_next(false)
		{

		}
		SceneClear::Impl::~Impl()
		{

		}
		void SceneClear::Impl::init()
		{
		}
		void SceneClear::Impl::ctrl()
		{
			if (input::key::KeyInput::Get(KEY_INPUT_Z) == 1)
			{
				m_is_next = true;
			}
		}
		void SceneClear::Impl::disp()
		{
			DrawBox(0, 0, 640, 480, GetColor(125, 255, 255), true);

			DrawString(320 - 64 * 4, 120, "Ｚキーでタイトル", GetColor(0, 0, 0));
		}
		void SceneClear::Impl::dest()
		{

		}
#pragma endregion
#pragma region Clear
		SceneClear::SceneClear()
			: impl(new Impl)
		{
			m_state = scene::SceneBase::State::Max;
		}
		SceneClear::~SceneClear()
		{

		}

		void SceneClear::init()
		{
			impl->init();
		}
		void SceneClear::ctrl()
		{
			impl->ctrl();

			if (impl->get_is_next())
			{
				m_state = scene::SceneBase::State::Title;	// ※クリア画面からタイトルに戻れるようにする
			}
		}
		void SceneClear::disp()
		{
			impl->disp();
		}
		void SceneClear::dest()
		{
			impl->dest();
		}
#pragma endregion
	}
}