#pragma once
#include "Scene.h"
#include <vector>
#include <glm/glm.hpp>
#include "ResourceManager.h"
namespace dae
{

	class LevelBuilder final
	{
	public:
		LevelBuilder();

		void GenerateLevel(Scene& scene, std::vector<glm::vec3>position, std::string Tag, bool isStatic = true, bool isFlipped = false);
		void SetLevelTexture(const std::shared_ptr<Texture2D> texture);

		//rule of 5
		~LevelBuilder() = default;
		LevelBuilder(const LevelBuilder& other) = delete;
		LevelBuilder(LevelBuilder&& other) = delete;
		LevelBuilder& operator=(const LevelBuilder& other) = delete;
		LevelBuilder& operator=(LevelBuilder&& other) = delete;
	private:
		std::shared_ptr<Texture2D> m_Texture;
	};
}
