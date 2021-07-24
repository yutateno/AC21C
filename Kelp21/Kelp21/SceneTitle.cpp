#include "SceneTitle.hpp"

#include "DxLib.h"

#include "KeyInput.hpp"


namespace scene
{
	namespace title
	{

#pragma region Impl
		struct SceneTitle::Impl
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

		SceneTitle::Impl::Impl()
			: m_is_next(false)
		{

		}
		SceneTitle::Impl::~Impl()
		{

		}
		void SceneTitle::Impl::init()
		{
		}
		void SceneTitle::Impl::ctrl()
		{
			if (input::key::KeyInput::Get(KEY_INPUT_Z) == 1)
			{
				m_is_next = true;
			}
		}
		void SceneTitle::Impl::disp()
		{
			DrawBox(0, 0, 640, 480, GetColor(235, 235, 235), true);

			DrawString(320 - 64 * 4, 120, "Ｚキーでスタート", GetColor(0, 0, 0));
		}
		void SceneTitle::Impl::dest()
		{

		}
#pragma endregion
#pragma region Title
		SceneTitle::SceneTitle()
			: impl(new Impl)
		{
			m_state = scene::SceneBase::State::Max;
		}
		SceneTitle::~SceneTitle()
		{

		}

		void SceneTitle::init()
		{
			impl->init();
		}
		void SceneTitle::ctrl()
		{
			impl->ctrl();

			if (impl->get_is_next())
			{
				m_state = scene::SceneBase::State::Game;	// 画面遷移(タイトル→ゲーム→クリア)
			}
		}
		void SceneTitle::disp()
		{
			impl->disp();
		}
		void SceneTitle::dest()
		{
			impl->dest();
		}
#pragma endregion
	}
}