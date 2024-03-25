#pragma once
#include <vector>


namespace dae
{


	enum class Event
	{
		EnemyDied,
		PlayerDied,
		PlayerHit,
		EnemyHit,
		EnemySpawned,
		PlayerSpawned,
		LevelComplete,
		LevelStart,
		LevelEnd,
		LevelReset,
		CounterUpdate,
		Win,
		Win100,
		TravelFarAccum,
		TravelFarSingle,
		SecretAchievement
	};

	class GameObject;
	class Observer 
	{
	public:
		virtual ~Observer() = default;
		virtual void OnNotify(Event event, GameObject* actor) = 0;
	};
}
