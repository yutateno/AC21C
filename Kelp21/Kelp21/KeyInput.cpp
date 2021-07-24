#include "KeyInput.hpp"

#include "DxLib.h"

namespace input
{
	namespace key
	{
		int KeyInput::m_key[256];		// �L�[�̓��͏�Ԋi�[�p�ϐ�
		char KeyInput::m_tmpKey[256];	// ���݂̃L�[�̓��͏�Ԃ��i�[����


		void KeyInput::InitKey()
		{
			for (int i = 0; i != 256; ++i)
			{
				m_key[i];
				m_tmpKey[i];
			}
		}
		void KeyInput::UpDate()
		{
			// �S�ẴL�[�̓��͏�Ԃ𓾂�i�����ꂽ��P���o�͂��A������Ă��Ȃ�������O��Ԃ�
			if (GetHitKeyStateAll(m_tmpKey) == -1) return;


			// �S�L�[���͏���
			for (int i = 0; i < 256; ++i)
			{
				// ������Ă��Ȃ�������
				if (m_tmpKey[i] == 0)
				{
					if (m_key[i] < 0)
					{
						m_key[i] = 0;
					}
					else if (m_key[i] > 0)
					{
						m_key[i] = -1;
					}
				}
				// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
				else if (m_tmpKey[i] == 1)
				{
					m_key[i]++;
				}
			}
		}
		const int& KeyInput::Get(const int& t_keyCode)
		{
			return m_key[t_keyCode];
		}
		const bool KeyInput::IsCheckEnd()
		{
			return m_key[KEY_INPUT_ESCAPE] > 0;
		}
	}
}