#pragma once

#include <EngineBase/Object.h>
#include <EngineBase/EngineDebug.h>

// 설명 :
class ULevel : public UObject
{
public:
	// constrcuter destructer
	ENGINEAPI ULevel();
	ENGINEAPI ~ULevel();

	// delete Function
	ULevel(const ULevel& _Other) = delete;
	ULevel(ULevel&& _Other) noexcept = delete;
	ULevel& operator=(const ULevel& _Other) = delete;
	ULevel& operator=(ULevel&& _Other) noexcept = delete;

	// 내가 이제 실행되는 레벨이 되었을때
	void LevelChangeStart();
	// 내가 교체 당했을때
	void LevelChangeEnd();


	void Tick(float _DeltaTime);

	template<typename ActorType>
	std::shared_ptr<ActorType> SpawnActor()
	{
		// AMonster : public AActor
		// SpawnActor<AMonster>();
		// std::shared_ptr<AMonster>

		static_assert(std::is_base_of_v<AActor, ActorType>, "액터를 상속받지 않은 클래스를 SpawnActor하려고 했습니다.");

		if (false == std::is_base_of_v<AActor, ActorType>)
		{
			MSGASSERT("액터를 상속받지 않은 클래스를 SpawnActor하려고 했습니다.");
			return nullptr;
			// static_assert
		}

		char* ActorMemory = new char[sizeof(ActorType)];


		AActor* ActorPtr = reinterpret_cast<ActorType*>(ActorMemory);
		ActorPtr->World = this;

		ActorType* NewPtr = reinterpret_cast<ActorType*>(ActorMemory);
		// 레벨먼저 세팅하고
		// 플레이스먼트 new 
		std::shared_ptr<ActorType> NewActor(NewPtr = new(ActorMemory) ActorType());


		//컴파일러는 그걸 모른다.
		BeginPlayList.push_back(NewActor);

		return NewActor;
	}

protected:

private:
	std::list<std::shared_ptr<class AActor>> BeginPlayList;

	std::list<std::shared_ptr<class AActor>> AllActorList;

};

