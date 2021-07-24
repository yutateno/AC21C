#include "SceneOver.hpp"

#include "DxLib.h"

#include "KeyInput.hpp"


namespace scene
{
	namespace over
	{

#pragma region Impl
		struct SceneOver::Impl
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

		SceneOver::Impl::Impl()
			: m_is_next(false)
		{

		}
		SceneOver::Impl::~Impl()
		{

		}
		void SceneOver::Impl::init()
		{
		}
		void SceneOver::Impl::ctrl()
		{
			if (input::key::KeyInput::Get(KEY_INPUT_Z) == 1)
			{
				m_is_next = true;
			}
		}
		void SceneOver::Impl::disp()
		{
			DrawBox(0, 0, 640, 480, GetColor(255, 125, 125), true);

			DrawString(320 - 64 * 4, 120, "Ｚキーでタイトル", GetColor(0, 0, 0));
		}
		void SceneOver::Impl::dest()
		{

		}
#pragma endregion
#pragma region Over
		SceneOver::SceneOver()
			: impl(new Impl)
		{
			m_state = scene::SceneBase::State::Over;
		}
		SceneOver::~SceneOver()
		{

		}

		void SceneOver::init()
		{
			impl->init();
		}
		void SceneOver::ctrl()
		{
			impl->ctrl();

			if (impl->get_is_next())
			{
				m_state = scene::SceneBase::State::Title;	// ※クリア画面からタイトルに戻れるようにする
			}
		}
		void SceneOver::disp()
		{
			impl->disp();
		}
		void SceneOver::dest()
		{
			impl->dest();
		}
#pragma endregion
	}
}