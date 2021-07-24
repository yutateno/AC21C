#include "Player.hpp"

#include "DxLib.h"

#include "KeyInput.hpp"

#include "Base.hpp"


namespace player
{
	Player::Player()
		: m_x(0)
		, m_y(0)
		, m_size(base::size)
		, m_walk_frame(20)
	{
		for (int i = 0; i < static_cast<int>(Move::Max); ++i)
		{
			m_is_able_move[i] = true;
		}
	}
	Player::~Player()
	{

	}

	void Player::init()
	{
		m_x = m_size;
		m_y = m_size;
	}
	void Player::ctrl()
	{
		if (m_is_able_move[static_cast<int>(Move::RIGHT)]
			&& (input::key::KeyInput::Get(KEY_INPUT_D) == 1
			|| input::key::KeyInput::Get(KEY_INPUT_D) % m_walk_frame == 1))
		{
			m_x += m_size;
		}
		if (m_is_able_move[static_cast<int>(Move::LEFT)]
			&& (input::key::KeyInput::Get(KEY_INPUT_A) == 1
			|| input::key::KeyInput::Get(KEY_INPUT_A) % m_walk_frame == 1))
		{
			m_x -= m_size;
		}
		if (m_is_able_move[static_cast<int>(Move::DOWN)]
			&& (input::key::KeyInput::Get(KEY_INPUT_S) == 1
			|| input::key::KeyInput::Get(KEY_INPUT_S) % m_walk_frame == 1))
		{
			m_y += m_size;
		}
		if (m_is_able_move[static_cast<int>(Move::UP)]
			&& (input::key::KeyInput::Get(KEY_INPUT_W) == 1
			|| input::key::KeyInput::Get(KEY_INPUT_W) % m_walk_frame == 1))
		{
			m_y -= m_size;
		}

	}
	void Player::disp()
	{
		DrawBox(m_x, m_y, m_x + m_size, m_y + m_size, GetColor(0, 255, 0), true);
	}
	void Player::dest()
	{
	}
	int Player::get_x()
	{
		return m_x;
	}
	int Player::get_y()
	{
		return m_y;
	}
}