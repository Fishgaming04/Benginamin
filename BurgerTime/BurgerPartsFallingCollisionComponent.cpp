#include "BurgerPartsFallingCollisionComponent.h"
#include "GameObject.h"
#include "CollisionSubject.h"
#include "IsPressedThenFallComponent.h"
#include <iostream>
#include "PlatterComponent.h"
#include "EnemyComponent.h"
#include "CounterIncreaseObserver.h"


namespace dae {

	BurgerPartsFallingCollisionComponent::BurgerPartsFallingCollisionComponent(GameObject* obj)
		:ObserverComponent(obj)
		, m_FallPlatformCounter{ 0 }
		, m_FallEnemyCounter{ 0 }
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
				if (HitObject->getTag() == "Enemy")
				{
					if (!HitObject->GetComponent<EnemyComponent>()->GetIsHit()) {
						if (info.CollisionObject == ToppingObject && info.CollisionDirection.y == 1) {
							HitObject->SetParent(ToppingObject, false);
							HitObject->setLocalPosition({ 0,0,0 });
							++m_FallEnemyCounter;
						}
						else if (info.MovingSubject == ToppingObject && info.CollisionDirection.y == -1)
						{
							HitObject->SetParent(ToppingObject, false);
							HitObject->setLocalPosition({ 0,0,0 });
							++m_FallEnemyCounter;
						}	
						HitObject->GetComponent<EnemyComponent>()->Hit();
					}
					
				}
				else if (HitObject->getTag() == "Platform")
				{

					m_TouchingPlatform = true;
					if (!m_TouchingPlatformLastFrame) {
						++m_FallPlatformCounter;
					}

					
					else if (m_FallPlatformCounter == m_FallEnemyCounter + 2)
					{
						ToppingObject->GetComponent<IsPressedThenFallComponent>()->ResetTopping();
						for (int index{}; index < ToppingObject->GetChildCount(); ++index)
						{
							auto child = ToppingObject->GetChildAtIndex(index);
							if (child->getTag() == "Enemy")
							{
								child->SetParent(nullptr, false);
							}
						}
						int points = 0;
						if (m_FallEnemyCounter == 0)
						{
							points = 50;
						}
						else {
							points = 500;
							for (int index{}; index < m_FallEnemyCounter; ++index)
							{
								points *= 2;
							}
						}
						m_Subject->Notify(Event::UpdateCounter, m_Subject.get(), UpdateCounterEvent{ "Points", points });
						m_FallPlatformCounter = 0;
						m_FallEnemyCounter = 0;
					}
				}
				else if (HitObject->getTag() == "ParentTopping") {
					//std::cout << "\n\n topping \n";
					//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";

					if (info.MovingSubject == ToppingObject)
					{
						if (info.CollisionDirection.y == 1 && !HitObject->GetComponent<IsPressedThenFallComponent>()->GetIsFalling()) {
							if (!HitObject->GetParent() || HitObject->GetParent()->getTag() != "Platter"){
								HitObject->GetComponent<IsPressedThenFallComponent>()->HitByTopping();

							}
							else if (HitObject->GetParent()->getTag() == "Platter") {
								ToppingObject->SetParent(HitObject->GetParent(), true);
								ToppingObject->GetParent()->GetComponent<PlatterComponent>()->SetIsDirty(true);
								ToppingObject->GetComponent<IsPressedThenFallComponent>()->ResetTopping();
								ToppingObject->GetComponent<IsPressedThenFallComponent>()->SetIsOnPlatter(true);
							}
						}
					}
					else if (info.CollisionObject == ToppingObject)
					{
						if (info.CollisionDirection.y == -1 && !HitObject->GetComponent<IsPressedThenFallComponent>()->GetIsFalling()) {
							if (!HitObject->GetParent() || HitObject->GetParent()->getTag() != "Platter") {
								HitObject->GetComponent<IsPressedThenFallComponent>()->HitByTopping();

							}
							else if (HitObject->GetParent()->getTag() == "Platter") {
								ToppingObject->SetParent(HitObject->GetParent(), true);
								ToppingObject->GetParent()->GetComponent<PlatterComponent>()->SetIsDirty(true);
								ToppingObject->GetComponent<IsPressedThenFallComponent>()->ResetTopping();
								ToppingObject->GetComponent<IsPressedThenFallComponent>()->SetIsOnPlatter(true);
							}
						}
					}
				}
				else if (HitObject->getTag() == "Platter") {
					//::cout << "\n\n Platter \n";
					//std::cout << info.CollisionDirection.x << " " << info.CollisionDirection.y << "\n";
					//std::cout << info.overlapPercentage.x << " " << info.overlapPercentage.y << " " << info.overlapPercentage.Total << "\n";
					if (info.overlapPercentage.y > 0.5f) {
						ToppingObject->SetParent(HitObject, true);
						HitObject->GetComponent<PlatterComponent>()->SetIsDirty(true);
						ToppingObject->GetComponent<IsPressedThenFallComponent>()->ResetTopping();
						ToppingObject->GetComponent<IsPressedThenFallComponent>()->SetIsOnPlatter(true);
					}

					for (int index{}; index < ToppingObject->GetChildCount(); ++index)
					{
						auto child = ToppingObject->GetChildAtIndex(index);
						if (child->getTag() == "Enemy")
						{
							child->GetComponent<EnemyComponent>()->Hit();
							HitObject->SetParent(nullptr, true);
						}
					}
				}
			}
		}
	}
}