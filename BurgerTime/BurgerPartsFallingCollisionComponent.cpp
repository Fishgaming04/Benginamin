#include "BurgerPartsFallingCollisionComponent.h"
#include "GameObject.h"
#include "CollisionSubject.h"
#include "IsPressedThenFallComponent.h"
#include <iostream>


namespace dae {

	BurgerPartsFallingCollisionComponent::BurgerPartsFallingCollisionComponent(GameObject* obj)
		:ObserverComponent(obj)
		, m_FallPlatformCounter{ 0 }
		, m_FallEnemieCounter{ 0 }
	{

	}

	void BurgerPartsFallingCollisionComponent::Update(double)
	{
		m_TouchingPlatformLastFrame = m_TouchingPlatform;
		m_TouchingPlatform = false;

	}

	void BurgerPartsFallingCollisionComponent::OnNotify(Event event, Subject*, const std::any& args)
	{
		if (event == Event::collision)
		{
			GameObject* HitObject = nullptr;
			GameObject* ToppingObject = GetGameObject();
			CollisionInfo info = std::any_cast<CollisionInfo>(args);
			if (info.MovingSubject == ToppingObject)
			{
				HitObject = info.CollisionObject;
			}
			else if (info.CollisionObject == ToppingObject)
			{
				HitObject = info.MovingSubject;
			}
			else
			{
				return;
			}

			if (ToppingObject->GetComponent<IsPressedThenFallComponent>()->GetIsFalling()) {
				if (HitObject->getTag() == "Enemie")
				{
					if (info.CollisionDirection.y == 1)
					{
						HitObject->SetParent(ToppingObject, true);
						++m_FallEnemieCounter;
					}
					else if (info.CollisionDirection.y == -1)
					{
						//die
					}
				}
				else if (HitObject->getTag() == "Platform")
				{
					std::cout << "\n\n Platform \n";
					std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";

					m_TouchingPlatform = true;
					if (!m_TouchingPlatformLastFrame) {
						++m_FallPlatformCounter;
					}

					
					else if (m_FallPlatformCounter == m_FallEnemieCounter + 2)
					{
						ToppingObject->GetComponent<IsPressedThenFallComponent>()->ResetTopping();
						for (int index{}; index < ToppingObject->GetChildCount(); ++index)
						{
							auto child = ToppingObject->GetChildAtIndex(index);
							if (child->getTag() == "Enemie")
							{
								//die
							}
						}
						m_FallPlatformCounter = 0;
						m_FallEnemieCounter = 0;
					}
				}
				else if (HitObject->getTag() == "ParentTopping") {
					std::cout << "\n\n topping \n";
					std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
					if (info.MovingSubject == ToppingObject)
					{
						if (info.CollisionDirection.y == 1 && !HitObject->GetComponent<IsPressedThenFallComponent>()->GetIsFalling()) {
							if (!HitObject->GetParent() || HitObject->GetParent()->getTag() != "Platter"){
								HitObject->GetComponent<IsPressedThenFallComponent>()->HitByTopping();

							}
						}
					}
					else if (info.CollisionObject == ToppingObject)
					{
						if (info.CollisionDirection.y == -1 && !HitObject->GetComponent<IsPressedThenFallComponent>()->GetIsFalling()) {
							if (!HitObject->GetParent() || HitObject->GetParent()->getTag() != "Platter") {
								HitObject->GetComponent<IsPressedThenFallComponent>()->HitByTopping();

							}
						}
					}
				}
				else if (HitObject->getTag() == "Platter") {
					std::cout << "\n\n Platter \n";
					std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
					if (info.overlapPercentage.y > 0.5f) {
						ToppingObject->SetParent(HitObject, true);
						ToppingObject->GetComponent<IsPressedThenFallComponent>()->ResetTopping();
						glm::vec2 size{ HitObject->GetTransform()->getSize() };
						HitObject->GetTransform()->SetSize(size.x, size.y + ToppingObject->GetTransform()->getSize().y);
					}
				}
			}
		}
	}
}