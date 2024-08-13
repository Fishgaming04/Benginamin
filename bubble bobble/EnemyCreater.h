#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "Scene.h"
namespace dae
{
	struct EnemysSpawning {
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

		void CreateEnemy(EnemysSpawning Spawning);
		void SetScene(Scene* scene) { m_Scene = scene; }
		void addPlayer(GameObject* player);

	private:
		std::vector<GameObject*> m_Enemys;
		Scene* m_Scene;
		std::vector<GameObject*> m_Players;

	};

}
