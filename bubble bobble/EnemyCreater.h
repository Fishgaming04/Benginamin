#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Scene.h"
namespace dae
{
	struct EnemiesSpawning {
		std::string name;
		int amount;
	};
	

	class EnemyCreater
	{
	public:
		EnemyCreater() = default;
		~EnemyCreater() = default;
		EnemyCreater(const EnemyCreater& other) = delete;
		EnemyCreater(EnemyCreater&& other) = delete;
		EnemyCreater& operator=(const EnemyCreater& other) = delete;
		EnemyCreater& operator=(EnemyCreater&& other) = delete;

		void CreateEnemy(EnemiesSpawning Spawning);
		void SetScene(Scene* scene) { m_Scene = scene; }
		void addPlayer(GameObject* player);

	private:
		std::vector<GameObject*> m_Enemies;
		Scene* m_Scene;
		std::vector<GameObject*> m_Players;

	};

}
