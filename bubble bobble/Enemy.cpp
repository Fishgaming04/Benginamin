#include "Enemy.h"
#include "GameObject.h"
#include "Transform.h"
#include "GravityComponent.h"
namespace dae
{
	Enemy::Enemy(GameObject* gameObject)
		:UpdatingComponent(gameObject)
	{
	}


	void Enemy::Update(double elapsed)
	{
		if (m_Players.size() == 0) return;
		else if (m_Players.size() == 1) {
			auto posPlayer = m_Players[0]->GetTransform()->getWorldposition();
			auto pos2 = GetGameObject()->GetTransform()->getWorldposition();
			moveTowordsPlayer(m_Players[0], elapsed);
		}
		else {
			float distances{};
			int lowestDistanceIndex{};
			for (size_t index{}; index < m_Players.size(); ++index) {
				auto posPlayer = m_Players[index]->GetTransform()->getWorldposition();
				auto pos2 = GetGameObject()->GetTransform()->getWorldposition();
				float distance = static_cast<float>(sqrt(pow(posPlayer.x - pos2.x, 2) + pow(posPlayer.y - pos2.y, 2)));
				if (distances < distance) {
					distances = distance;
					lowestDistanceIndex = static_cast<int>(index);
				}
			}	
			moveTowordsPlayer(m_Players[lowestDistanceIndex], elapsed);
		}
	}

	void Enemy::AddPlayer(GameObject* player)
	{
		m_Players.push_back(player);
	}

	void Enemy::RemovePlayer(GameObject* player)
	{
		if (player) {
			m_Players.erase(std::find(m_Players.begin(), m_Players.end(), player));
		}
	}
	void Enemy::moveTowordsPlayer(GameObject* player, double elapsed)
	{
		auto posPlayer = player->GetTransform()->getWorldposition();
		auto pos2 = GetGameObject()->GetTransform()->getWorldposition();
		if (posPlayer.x > pos2.x) {
			GetGameObject()->setLocalPosition(pos2.x + m_Speed * static_cast<float>(elapsed), pos2.y, pos2.z);
		}
		else {
			GetGameObject()->setLocalPosition(pos2.x - m_Speed * static_cast<float>(elapsed), pos2.y, pos2.z);
		}
	}
	Enemy::~Enemy()
	{
	}
}
