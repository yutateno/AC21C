#pragma once


// ・プレイヤーがある
namespace player
{
	class Player
	{
	public:
		enum class Move {
			UP, DOWN, RIGHT, LEFT, Max
		};

	public:
		Player();
		~Player();

		void init();
		void ctrl();
		void disp();
		void dest();

		int get_x();
		int get_y();

		void set_is_unable_move(Move _unable_move)
		{
			m_is_able_move[static_cast<int>(_unable_move)] = false;
		}
		void move_able_reset()
		{
			for (int i = 0; i < static_cast<int>(Move::Max); ++i)
			{
				m_is_able_move[i] = true;
			}
		}

	private:
		int m_x;
		int m_y;

		int m_size;

		int m_walk_frame;

		bool m_is_able_move[4];
	};
}
