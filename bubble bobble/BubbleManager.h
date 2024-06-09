#pragma once
#include "Components.h"
#include "GameObject.h"
#include "Scene.h"
namespace dae {
	class BubbleManager final: public dae::UpdatingComponent
	{
	public:
		BubbleManager(GameObject* obj);
		virtual ~BubbleManager() {};
		virtual void Update(double elapsed);
		void Shoot();
		void SetScene(Scene* scene) { m_Scene = scene; }
		void SetBubbleTimer(float timer) { m_BubbleTimer = timer; }
		void SetBubbleShootingDistance(float distance) { m_BubbleShootingDistance = distance; }
		void SetBubbleSpeed(float speed) { m_BubbleSpeed = speed; }
		void SetTexture(std::shared_ptr<Texture2D> texture) { m_Texture = texture; }
		//rule of 5
		BubbleManager(const BubbleManager& other) = delete;
		BubbleManager(BubbleManager&& other) = delete;
		BubbleManager& operator=(const BubbleManager& other) = delete;
		BubbleManager& operator=(BubbleManager&& other) = delete;
	private:
		void CreateBubble();
		Scene* m_Scene;
		std::vector<GameObject*> m_Bubbles;
		float m_BubbleTimer;
		float m_BubbleShootingDistance;
		float m_BubbleSpeed;
		std::shared_ptr<Texture2D> m_Texture;
	};
}
