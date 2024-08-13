#include "Observers.h"

#include <iostream>
namespace dae {


	void Subject::AddObserver(Observer* observer)
	{
		if (!observer)
		{
			return;
		}
		for (Observer* Observer : m_Observers)
		{
			if (Observer == observer)
			{
				return;	
			}
		}
		m_Observers.push_back(observer);
	}

	void Subject::RemoveObserver(Observer* observer)
	{
		if (!observer)
		{
			return;
		}
		for (unsigned int index{}; index < m_Observers.size(); ++index)
		{
			if (m_Observers[index] == observer)
			{
				m_Observers.erase(m_Observers.begin() + index);
				return;
			}
		}
	}

	void Subject::Notify(Event event, Subject* subject,const std::any& args)
	{
		for (auto& observer : m_Observers)
		{
			if (observer) {	
				observer->OnNotify(event, subject, args);

			}
		}
	}

}