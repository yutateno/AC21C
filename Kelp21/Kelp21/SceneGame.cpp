#include "SceneGame.hpp"
#include "Player.hpp"

#include "DxLib.h"

#include "KeyInput.hpp"

#include "Base.hpp"

#include <random>

namespace scene
{
	namespace game
	{
#pragma region Coll
		// ・壁があり、当たり判定がある

		bool CheckLeftColl(const int _a_left, const int _b_right)
		{
			if (_a_left == _b_right)
			{
				return true;
			}

			return false;
		}

		bool CheckRightColl(const int _a_right, const int _b_left)
		{
			if (_a_right == _b_left)
			{
				return true;
			}

			return false;
		}

		bool CheckUpColl(const int _a_top, const int _b_bottom)
		{
			if (_a_top == _b_bottom)
			{
				return true;
			}

			return false;
		}

		bool CheckDownColl(const int _a_bottom, const int _b_top)
		{
			if (_a_bottom == _b_top)
			{
				return true;
			}

			return false;
		}
#pragma endregion
#pragma region Block
		class Block
		{
		public:
			Block()
				: m_x(0)
				, m_y(0)
				, m_x_size(base::size)
				, m_y_size(base::size)
			{
			}
			Block(int _x, int _y)
				: m_x(_x)
				, m_y(_y)
				, m_x_size(base::size)
				, m_y_size(base::size)
			{
			}
			Block(int _x, int _y, int _x_size, int _y_size)
				: m_x(_x)
				, m_y(_y)
				, m_x_size(_x_size)
				, m_y_size(_y_size)
			{
			}
			~Block() {}

			int get_x()
			{
				return m_x;
			}
			int get_y() 
			{
				return m_y;
			}
			int get_x_size()
			{
				return m_x_size;
			}
			int get_y_size()
			{
				return m_y_size;
			}

		private:
			int m_x;
			int m_y;

			int m_x_size;
			int m_y_size;
		};
#pragma endregion
#pragma region Impl
		struct SceneGame::Impl
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

			bool get_is_clear()
			{
				return m_is_clear;
			}

		private:
			bool m_is_next;
			bool m_is_clear;

			int m_goal_x;
			int m_goal_y;

			player::Player* m_player;

			const int c_block_num = 200;
			Block* m_block[200];

			const int c_end_time = 1000;
			int m_end_time_count;
		};

		SceneGame::Impl::Impl()
			: m_is_next(false)
			, m_is_clear(false)
			, m_goal_x(0)
			, m_goal_y(0)
			, m_player(nullptr)
			, m_end_time_count(0)
		{
			for (int i = 0; i < c_block_num; ++i)
			{
				m_block[i] = nullptr;
			}
		}
		SceneGame::Impl::~Impl()
		{

		}
		void SceneGame::Impl::init()
		{
			m_player = new player::Player;
			m_player->init();

			m_goal_x = 640 - (base::size * 2);
			m_goal_y = 480 - (base::size * 2);

			// ・壁があり、当たり判定がある
			m_block[0] = new Block(0, 0, 640, base::size);
			m_block[1] = new Block(0, 0, base::size, 480);
			m_block[2] = new Block(640 - base::size, 0, 640, 480);
			m_block[3] = new Block(0, 480 - base::size, 640, 480);
			for (int i = 4; i < c_block_num; ++i)
			{
				std::random_device rnd;
				std::mt19937 mt(rnd());
				std::uniform_int_distribution<> x(1, 30);
				std::uniform_int_distribution<> y(1, 22);

				int area_x = x(mt);
				int area_y = y(mt);
				while ((area_x == 1 && area_y == 1) || area_x == 30 && area_y == 22)
				{
					std::random_device rnd;
					std::mt19937 mt(rnd());
					std::uniform_int_distribution<> x(1, 30);
					std::uniform_int_distribution<> y(1, 22);

					area_x = x(mt);
					area_y = y(mt);
				}

				m_block[i] = new Block(area_x * base::size, area_y * base::size);
			}
		}
		void SceneGame::Impl::ctrl()
		{
			m_end_time_count++;

			m_player->ctrl();

			m_player->move_able_reset();

			for (int i = 0; i < c_block_num; ++i)
			{
				if (CheckLeftColl(m_player->get_x(), m_block[i]->get_x() + m_block[i]->get_x_size())
					&& m_block[i]->get_y() <= m_player->get_y() && m_block[i]->get_y() + m_block[i]->get_y_size() >= m_player->get_y() + base::size)
				{
					m_player->set_is_unable_move(player::Player::Move::LEFT);
				}

				if (CheckRightColl(m_player->get_x() + base::size, m_block[i]->get_x())
					&& m_block[i]->get_y() <= m_player->get_y() && m_block[i]->get_y() + m_block[i]->get_y_size() >= m_player->get_y() + base::size)
				{
					m_player->set_is_unable_move(player::Player::Move::RIGHT);
				}

				if (CheckUpColl(m_player->get_y(), m_block[i]->get_y() + m_block[i]->get_y_size())
					&& m_block[i]->get_x() <= m_player->get_x() && m_block[i]->get_x() + m_block[i]->get_x_size() >= m_player->get_x() + base::size)
				{
					m_player->set_is_unable_move(player::Player::Move::UP);
				}

				if (CheckDownColl(m_player->get_y() + base::size, m_block[i]->get_y())
					&& m_block[i]->get_x() <= m_player->get_x() && m_block[i]->get_x()+m_block[i]->get_x_size() >= m_player->get_x() + base::size)
				{
					m_player->set_is_unable_move(player::Player::Move::DOWN);
				}
			}

			// ・GOAL条件を満たしたらクリア画面に移動
			if (m_player->get_x() == m_goal_x
				&& m_player->get_y() == m_goal_y)
			{
				m_is_clear = true;
				m_is_next = true;
			}

			if (m_end_time_count > c_end_time)
			{
				m_is_next = true;
			}
		}
		void SceneGame::Impl::disp()
		{
			DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), true);

			DrawString(320 - 64 * 2, 120, "ＧＡＭＥ", GetColor(0, 0, 0));
			DrawFormatString(320 - 64 * 3, 182, GetColor(0, 0, 0), "%d / %d", m_end_time_count, c_end_time);

			DrawBox(m_goal_x, m_goal_y, m_goal_x + base::size, m_goal_y + base::size, GetColor(0, 0, 255), true);

			for (int i = 0; i < c_block_num; ++i)
			{
				DrawBox(m_block[i]->get_x(), m_block[i]->get_y(), m_block[i]->get_x() + m_block[i]->get_x_size(), m_block[i]->get_y() + m_block[i]->get_y_size(), GetColor(255, 0, 0), true);
			}

			m_player->disp();
		}
		void SceneGame::Impl::dest()
		{
			m_player->dest();
			delete m_player;

			for (int i = 0; i < c_block_num; ++i)
			{
				delete m_block[i];
			}
		}
#pragma endregion
#pragma region Game
		SceneGame::SceneGame()
			: impl(new Impl)
		{
			m_state = scene::SceneBase::State::Game;
		}
		SceneGame::~SceneGame()
		{

		}

		void SceneGame::init()
		{
			impl->init();
		}
		void SceneGame::ctrl()
		{
			impl->ctrl();

			
			if (impl->get_is_next())
			{
				if (impl->get_is_clear())
				{
					m_state = scene::SceneBase::State::Clear;	// 画面遷移(タイトル→ゲーム→クリア)
				}
				else
				{
					m_state = scene::SceneBase::State::Over;
				}
			}
		}
		void SceneGame::disp()
		{
			impl->disp();
		}
		void SceneGame::dest()
		{
			impl->dest();
		}
#pragma endregion
	}
}