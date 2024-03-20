#include "ObserverManager.h"

namespace dae {

	void dae::ObserverManager::AddObserver(Observer* observer)
	{
		m_observers.push_back(observer);
	}

	void dae::ObserverManager::RemoveObserver(Observer* observer)
	{
		if (observer) {
			m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
		}
	}

	void dae::ObserverManager::NotifyObservers(Event event)
	{
		for (auto observer : m_observers)
			observer->Notify(event, this);
	}
}