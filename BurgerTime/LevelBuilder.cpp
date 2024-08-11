#include "LevelBuilder.h"
#include "Transform.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "CollisionSubject.h"
#include "iostream"
#include "Texture2D.h"
#include <SDL.h>

namespace dae {


	LevelBuilder::LevelBuilder()
	{
	}


	void LevelBuilder::GenerateLevel(Scene& scene, std::vector<glm::vec3> position, std::string tag, bool isStatic, bool isFlipped)
	{
		//auto& recourceManager = dae::ResourceManager::GetInstance();
		int widthMiddle;
		int heightMiddle;
		SDL_QueryTexture(m_Texture.get()->GetSDLTexture(), nullptr, nullptr, &widthMiddle, &heightMiddle);
		auto& CollsionSubject = dae::CollisionSubject::GetInstance();
		for (glm::vec3 pos : position)
		{
			auto gameobject = std::make_unique<GameObject>();
			gameobject->AddComponent<TextureComponent>();
			gameobject->GetComponent<TextureComponent>()->SetTexture(m_Texture);
			gameobject->GetTransform()->SetSize(static_cast<float>(widthMiddle), static_cast<float>(heightMiddle));
			gameobject->setLocalPosition(pos);
			gameobject->setIsLookingLeft(isFlipped);
			gameobject->setTag(tag);
			gameobject->setFacingDirectionStatic(true);
			std::cout << pos.x << " " << pos.y << " " << pos.z << "\n";

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

}