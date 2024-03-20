#pragma once
#include "GameObject.h"

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
	};

	class ObserverManager;
	class Observer 
	{
	public:
		virtual ~Observer() = default;
		virtual void Notify(Event event, ObserverManager* actor) = 0;
	};
}
