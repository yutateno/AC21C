#include "DxLib.h"
#include <string>

#include "Manager.hpp"
#include "KeyInput.hpp"



/// --------------------------------------------------------------------------------------------------
// �E�B���h�E�T�C�Y�����߂�
int winWidth = 0;
int winHeight = 0;
int bitColor = 0;



/// --------------------------------------------------------------------------------------------------
bool Init(const int t_winWidth, const int t_winHeight, const int t_bitColor, std::string t_projectName, bool t_fullScreen)
{
	winWidth = t_winWidth;
	winHeight = t_winHeight;
	bitColor = t_bitColor;

#ifdef _DEBUG
	SetOutApplicationLogValidFlag(TRUE);	// ���O�e�L�X�g�o�͂���
#elif NDEBUG
	SetOutApplicationLogValidFlag(FALSE);	// ���O�e�L�X�g�o�͂��Ȃ�
#endif


	SetWindowText(t_projectName.c_str());		// ���C���E�C���h�E�̃E�C���h�E�^�C�g����ύX����
	SetBackgroundColor(0, 0, 0);				// �w�i�F��ύX
	ChangeWindowMode(TRUE);						// �E�B���h�E�Y���[�h�ɂ�����


	if (t_fullScreen)
	{
		SetGraphMode(winWidth, winHeight, bitColor);			// ��ʃT�C�Y�ݒ�
		GetDefaultState(&winWidth, &winHeight, &bitColor);		// �f�t�H���g�E�B���h�E�l�𓾂�
		SetWindowSize(winWidth, winHeight);			// �f�t�H���g�E�B���h�E�T�C�Y�ɍ��킹�ăQ�[���T�C�Y��ύX
	}


	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return false;			// �G���[���N�����璼���ɏI��
	}


	SetDrawScreen(DX_SCREEN_BACK);	// �w�i�`��


	return true;
}



/// --------------------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!Init(640, 480, 32, "https://www.youtube.com/watch?v=7zcbWuN3IVs", false)) return -1;	// �E�E�B���h�E�T�C�Y��640�~480

	SetFontSize(64);

	Manager m_manager;
	m_manager.init();

	input::key::KeyInput::InitKey();

	// �E�ǂ̉�ʂł�esc�L�[�ŏI��
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !input::key::KeyInput::IsCheckEnd())
	{
		input::key::KeyInput::UpDate();

		m_manager.ctrl();
		m_manager.disp();
	}

	m_manager.dest();

	// �폜
	DxLib_End();		// DX���C�u�����̌�n��


	return 0;
}