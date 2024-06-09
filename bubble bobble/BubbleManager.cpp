#include "BubbleManager.h"
#include "BubbleCompenent.h"
#include "GameObject.h"
#include "CollisionSubject.h"
#include "TextureComponent.h"
#include "CollisionBubbleComponent.h"
namespace dae {
	BubbleManager::BubbleManager(GameObject* obj)
		:UpdatingComponent(obj)
		, m_Scene(nullptr)
		, m_BubbleTimer(0.0f)
	{
	}

	void BubbleManager::Update(double)
	{
		
	}

	void BubbleManager::Shoot()
	{
		if (m_Bubbles.size() > 0) {

			for (auto bubble : m_Bubbles)
			{
				if (!bubble->GetComponent<BubbleCompenent>()->GetIsActive())
				{
					bubble->GetComponent<BubbleCompenent>()->Shot(GetGameObject()->getIsLookingLeft(), GetGameObject());
					return;
				}
			}
		}
		CreateBubble();
		m_Bubbles.back()->GetComponent<BubbleCompenent>()->Shot(GetGameObject()->getIsLookingLeft(), GetGameObject());
	}

	void BubbleManager::CreateBubble()
	{
		auto& CollsionSubject = dae::CollisionSubject().GetInstance();
		auto Bubble = std::make_shared<dae::GameObject>();
		Bubble->AddComponent<BubbleCompenent>();
		Bubble->GetComponent<BubbleCompenent>()->setMaxTimer(m_BubbleTimer);
		Bubble->GetComponent<BubbleCompenent>()->setShootingDistance(m_BubbleShootingDistance, m_BubbleSpeed);
		Bubble->AddComponent<TextureComponent>();
		Bubble->AddComponent<CollisioBubbleComponent>();
		Bubble->GetComponent<TextureComponent>()->SetTexture(m_Texture);
		CollsionSubject.addMovingGameObject(Bubble.get());
		CollsionSubject.AddObserver(Bubble->GetComponent<dae::CollisioBubbleComponent>());


		m_Bubbles.push_back(Bubble.get());
		m_Scene->Add(Bubble);
	}
}
