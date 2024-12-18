#include "PreCompile.h"
#include "ContentsCore.h"
#include <EngineCore/EngineCore.h>
#include "TitleGameMode.h"
#include <EngineCore/Pawn.h>


CreateContentsCoreDefine(UContentsCore);
UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::EngineStart(UEngineInitData& _Data)
{
	_Data.WindowPos = { 100, 100 };
	_Data.WindowSize = { 300, 300 };
	UEngineCore::CreateLevel<ATitleGameMode, APawn>("Titlelevel");
	UEngineCore::OpenLevel("Titlelevel");
	// 윈도우 크기 지정
}

void UContentsCore::EngineTick(float _DeltaTime)
{

}

void UContentsCore::EngineEnd()
{

}