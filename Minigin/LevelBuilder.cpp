#include "LevelBuilder.h"
#include "Transform.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "CollisionSubject.h"
namespace dae {


	LevelBuilder::LevelBuilder()
		:m_TexturePath("Resources/Textures/LvlTile1.png")
	{
	}


	void LevelBuilder::GenerateLevel(Scene& scene, std::vector<std::vector<int>> lvl)
	{
		auto& recourceManager = dae::ResourceManager::GetInstance();
		auto& CollsionSubject = dae::CollisionSubject::GetInstance();
		for (std::vector<int> pos : lvl)
		{
			auto gameobject = std::make_unique<GameObject>();
			gameobject->AddComponent<TextureComponent>();
			gameobject->GetComponent<TextureComponent>()->SetTexture(recourceManager.LoadTexture(m_TexturePath));
			gameobject->GetTransform()->SetSize(16, 16);
			gameobject->setTag("Envirement");
			gameobject->setLocalPosition(static_cast<float>(pos[0]), static_cast<float>(pos[1]), static_cast<float>(pos[2]));
			CollsionSubject.addStaticGameObject(gameobject.get());
			scene.Add(std::move(gameobject));
		}
	}

	void LevelBuilder::SetLevelTexture(const std::string& texturePath)
	{
		m_TexturePath = texturePath;
	}

}