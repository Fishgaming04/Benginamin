#pragma once
#include "Components.h"

namespace dae {

	class Enemy final: public UpdatingComponent
	{
	public:
		Enemy(GameObject* gameObject);

		void Update(double elapsed) override;
		void AddPlayer(GameObject* player);
		void RemovePlayer(GameObject* player);

		void moveTowordsPlayer(GameObject* player, double elapsed);

		void SetSpeed(float speed) { m_Speed = speed; }
		void SetTimer(float timer) { m_Timer = timer; }
		void SetInBubble(bool inBubble) { m_InBubble = inBubble; }
		void GetInBubble() { m_InBubble; }

		~Enemy();
		Enemy(const Enemy& other) = delete;
		Enemy(Enemy&& other) = delete;
		Enemy& operator=(const Enemy& other) = delete;
		Enemy& operator=(Enemy&& other) = delete;
	private:
		std::vector<GameObject*> m_Players;
		float m_Speed;
		float m_Timer;
		bool m_InBubble;
	};


}