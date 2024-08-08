#pragma once
#include "Scene.h"
#include <vector>
#include <glm/glm.hpp>
#include "ResourceManager.h"
namespace dae
{

	class LevelCreater final
	{
	public:
		LevelCreater();

		void GenerateLevel(Scene& scene, std::vector<std::vector<int>>lvl);
		void SetLevelTexture(const std::string& texturePath);

		//rule of 5
		~LevelCreater() = default;
		LevelCreater(const LevelCreater& other) = delete;
		LevelCreater(LevelCreater&& other) = delete;
		LevelCreater& operator=(const LevelCreater& other) = delete;
		LevelCreater& operator=(LevelCreater&& other) = delete;
	private:
		std::string m_TexturePath;
	};

}
