#pragma once
#include <vector>
#include "Observers.h"

namespace dae {
	class ObserverManager
	{
	public:
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);
	protected:
		void NotifyObservers(Event event);
	private:
		std::vector<Observer*> m_observers;

	};
}
