#include "PlatterComponent.h"
#include "GameObject.h"

namespace dae {




	PlatterComponent::PlatterComponent(GameObject* obj)
		: UpdatingComponent(obj)
		, m_IsDirty(false)
		, m_BurgerCompleted(false)
	{
	}

	void PlatterComponent::Update(double)
	{
		if (m_IsDirty && !m_BurgerCompleted){
			m_IsDirty = false;
			for (int index = 0; index < GetGameObject()->GetChildCount() && !m_BurgerCompleted; ++index)
			{
				auto child = GetGameObject()->GetChildAtIndex(index);
				for (int childeren{}; childeren < child->GetChildCount() && !m_BurgerCompleted; ++childeren) {
					if (child->GetChildAtIndex(childeren)->getTag() == "Bun")
					{
						m_BurgerCompleted = true;
					}
				}
			}
		}
	}

	void PlatterComponent::addObserver(ObserverComponent* observer)
	{
		m_Subject.AddObserver(observer);
	}

	void PlatterComponent::removeObserver(ObserverComponent* observer)
	{
		m_Subject.RemoveObserver(observer);
	}




}