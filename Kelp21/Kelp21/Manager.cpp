#include "Manager.hpp"

#include "SceneBase.hpp"
#include "SceneTitle.hpp"
#include "SceneGame.hpp"
#include "SceneOver.hpp"
#include "SceneClear.hpp"

#include "DxLib.h"

#include <cassert>

#pragma region Impl
struct Manager::Impl
{
	Impl();
	~Impl();

	void init();
	void ctrl();
	void disp();
	void dest();


	scene::SceneBase* m_scene;
};

Manager::Impl::Impl()
{
	m_scene = new scene::title::SceneTitle;
}
Manager::Impl::~Impl()
{
	delete m_scene;
}
void Manager::Impl::init()
{
	m_scene->init();
}
void Manager::Impl::ctrl()
{
	m_scene->ctrl();

	if (m_scene->get_state() != scene::SceneBase::State::Max)
	{
		scene::SceneBase::State state = m_scene->get_state();

		m_scene->dest();
		delete m_scene;

		switch (state)
		{
		case scene::SceneBase::State::Title:
			m_scene = new scene::title::SceneTitle;
			break;

		case scene::SceneBase::State::Game:
			m_scene = new scene::game::SceneGame;
			break;

		case scene::SceneBase::State::Over:
			m_scene = new scene::over::SceneOver;
			break;

		case scene::SceneBase::State::Clear:
			m_scene = new scene::clear::SceneClear;
			break;

		default:
			assert(0);
			break;
		}

		m_scene->init();
	}
}
void Manager::Impl::disp()
{
	m_scene->disp();
}
void Manager::Impl::dest()
{
	m_scene->dest();
}
#pragma endregion
#pragma region Manager
Manager::Manager()
	: impl(new Impl)
{
}

Manager::~Manager()
{
}

void Manager::init()
{
	impl->init();
}

void Manager::ctrl()
{
	impl->ctrl();
}

void Manager::disp()
{
	impl->disp();
}

void Manager::dest()
{
	impl->dest();
}
#pragma endregion