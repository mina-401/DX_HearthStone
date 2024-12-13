#include "PreCompile.h"
#include "EngineCore.h"
#include <EngineBase/EngineDebug.h>
#include <EnginePlatform/EngineWindow.h>

UEngineCore::UEngineCore()
{
}

UEngineCore::~UEngineCore()
{
}

void UEngineCore::EngineStart(HINSTANCE _Instance)
{
	UEngineDebug::LeakCheck();
	//���� ���� ����.
	//������â ������ ���
	UEngineWindow::EngineWindowInit(_Instance);
	//window ����. - engine window

	UEngineWindow MainWindow;

	MainWindow.Open("MainWindow");
	UEngineWindow::WindowMessageLoop(
		[]()
		{
			// �����Ҷ� �ϰ� ������
			// 1. ������â ũ�� �ٲٰ� �ʹ�.
		},
		[]()
		{
			// ������ ���ư��� �ϰ� ������
		},
		[]()
		{
			// ������ �������� �ϰ� ������.
		});



	/*UEngineDebug::OutPutString("sadasdf");*/
}

