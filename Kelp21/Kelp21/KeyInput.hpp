#pragma once


namespace input
{
	namespace key
	{
		class KeyInput
		{
		private:
			// キーボードの入力状態
			static int m_key[256];		// キーの入力状態格納用変数
			static char m_tmpKey[256];	// 現在のキーの入力状態を格納する

		public:
			static void InitKey();


			static void UpDate();


			static const int& Get(const int& t_keyCode);

			static const bool IsCheckEnd();
		};
	}
}