#pragma once


namespace input
{
	namespace key
	{
		class KeyInput
		{
		private:
			// �L�[�{�[�h�̓��͏��
			static int m_key[256];		// �L�[�̓��͏�Ԋi�[�p�ϐ�
			static char m_tmpKey[256];	// ���݂̃L�[�̓��͏�Ԃ��i�[����

		public:
			static void InitKey();


			static void UpDate();


			static const int& Get(const int& t_keyCode);

			static const bool IsCheckEnd();
		};
	}
}