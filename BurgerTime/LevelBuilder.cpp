#include "LevelBuilder.h"
#include "Transform.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "CollisionSubject.h"
namespace dae {


	LevelBuilder::LevelBuilder()
		:m_Width(32)
		,m_Height(32)
	{
	}


	void LevelBuilder::GenerateLevel(Scene& scene, std::vector<std::vector<int>> position, std::string tag, bool isStatic)
	{
		//auto& recourceManager = dae::ResourceManager::GetInstance();
		auto& CollsionSubject = dae::CollisionSubject::GetInstance();
		for (std::vector<int> pos : position)
		{
			auto gameobject = std::make_unique<GameObject>();
			gameobject->AddComponent<TextureComponent>();
			gameobject->GetComponent<TextureComponent>()->SetTexture(m_Texture);
			gameobject->GetTransform()->SetSize(static_cast<float>(m_Width), static_cast<float>(m_Height));
			gameobject->setTag(tag);
			gameobject->setLocalPosition(static_cast<float>(pos[0]), static_cast<float>(pos[1]));
			if (isStatic) {
				CollsionSubject.addStaticGameObject(gameobject.get());
			}
			else
			{
				CollsionSubject.addMovingGameObject(gameobject.get());
			}
			scene.Add(std::move(gameobject));
		}
	}

	void LevelBuilder::SetLevelTexture(const std::shared_ptr<Texture2D> texture)
	{
		m_Texture = texture;
	}

	void LevelBuilder::SetSize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
	}
}