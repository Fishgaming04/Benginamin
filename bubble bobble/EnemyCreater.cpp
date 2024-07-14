#include "EnemyCreater.h"
#include "Enemy.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include <memory>
#include "GravityComponent.h"
#include "CollisionSubject.h"
#include "CollisionPlayerComponent.h"
#include "EnemyCollisionObserver.h"

namespace dae {
	void dae::EnemyCreater::CreateEnemy(EnemiesSpawning Spawning)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		auto& CollsionSubject = dae::CollisionSubject::GetInstance();
		float xPos = 224.f;
		if (Spawning.name == "Zen-Chan") {
			for (int i = 0; i < Spawning.amount; i++)
			{
				auto enemy = std::make_unique<GameObject>();
				enemy->AddComponent<Enemy>();
				enemy->AddComponent<TextureComponent>();
				enemy->GetComponent<TextureComponent>()->SetTexture(recourceManager.LoadTexture("Zen-Chan.png"));
				for (auto player : m_Players) {
					enemy->GetComponent<Enemy>()->AddPlayer(player);
				}
				enemy->GetComponent<Enemy>()->SetSpeed(50);
				enemy->AddComponent<GravityComponent>();
				enemy->GetComponent<dae::GravityComponent>()->SetMaxMomentum(9.81);
				enemy->GetComponent<dae::GravityComponent>()->SetMomentumScaler(0.4);
				enemy->AddComponent<CollisionPlayerComponent>();
				enemy->AddComponent<EnemyCollisionObserver>();
				enemy->setTag("Zen-Chan");
				enemy->setLocalPosition(xPos, -15);
				xPos += 16;
				enemy->GetTransform()->SetSize(16, 16);

				CollsionSubject.addMovingGameObject(enemy.get());
				CollsionSubject.AddObserver(enemy->GetComponent<dae::CollisionPlayerComponent>());
				CollsionSubject.AddObserver(enemy->GetComponent<EnemyCollisionObserver>());

				m_Scene->Add(std::move(enemy));
			}
		}
	}

	void EnemyCreater::addPlayer(GameObject* player)
	{
		if (player) {
			m_Players.push_back(player);
		}
	}

}