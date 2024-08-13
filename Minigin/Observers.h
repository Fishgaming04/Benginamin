#pragma once
#include <vector>
#include <any>
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
		collision
	};


	class Subject;
	class Observer 
	{
	public:
		virtual ~Observer() = default;
		virtual void OnNotify(Event event, Subject* subject, const std::any& args) = 0;
	};


	class Subject
	{
	public:
		Subject() = default;
			
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);
		void Notify(Event event, Subject* subjec,const std::any& args);
	private:
		std::vector<Observer*> m_Observers;
	};
}
