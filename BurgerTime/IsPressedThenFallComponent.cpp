#include "IsPressedThenFallComponent.h"
#include "GameObject.h"
#include "ToppingPartCollision.h"
namespace dae {



	IsPressedThenFallComponent::IsPressedThenFallComponent(GameObject* obj)
		:UpdatingComponent(obj)
		, m_Pressdistance{ 0 }
		, m_FallingSpeed{ 0 }
		, m_IsFalling{ false }
		, m_IsPressed(4, false)
	{
	}

	void IsPressedThenFallComponent::Update(double deltatime)
	{

		if (!m_IsOnPlatter) {
			if (m_IsFalling)
			{
				GetGameObject()->setLocalPosition(GetGameObject()->GetTransform()->getLocalposition() + glm::vec3(0, m_FallingSpeed * deltatime, 0));
			}
			else
			{

				for (int index{}; index < GetGameObject()->GetChildCount(); ++index)
				{
					auto child = GetGameObject()->GetChildAtIndex(index);
					if (child->getTag() == "Topping" || child->getTag() == "Bun")
					{
						auto topping = child->GetComponent<ToppingPartCollision>();
						if (topping->getIsPressed())
						{
							if (!m_IsPressed[index])
							{
								m_IsPressed[index] = true;
								child->setLocalPosition(child->GetTransform()->getLocalposition() + glm::vec3(0, m_Pressdistance, 0));
							}
						}
					}
				}
				if (m_IsPressed[0] && m_IsPressed[1] && m_IsPressed[2] && m_IsPressed[3])
				{
					m_IsFalling = true;
				}
			}
		}
	}


	void IsPressedThenFallComponent::HitByTopping()
	{
		if (!m_IsOnPlatter) {
			for (int index{}; index < GetGameObject()->GetChildCount(); ++index) {
				auto child = GetGameObject()->GetChildAtIndex(index);
				if (child->getTag() == "Topping" || child->getTag() == "Bun")
				{
					child->GetComponent<ToppingPartCollision>()->setIsPressed(true);
				}
			}
		}
	}

	void IsPressedThenFallComponent::ResetTopping()
	{
		m_IsFalling = false;
		for (int index{}; index < GetGameObject()->GetChildCount(); ++index)
		{
			auto child = GetGameObject()->GetChildAtIndex(index);
			if (child->getTag() == "Topping" || child->getTag() == "Bun")
			{
				child->setLocalPosition(child->GetTransform()->getLocalposition() - glm::vec3(0, m_Pressdistance, 0));
				child->GetComponent<ToppingPartCollision>()->setIsPressed(false);
				m_IsPressed[index] = false;
			}
		}

	}
	void IsPressedThenFallComponent::SetIsFalling(bool isFalling)
	{
		if (!m_IsOnPlatter){
			m_IsFalling = isFalling;
		}
	}
}