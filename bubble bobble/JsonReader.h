#pragma once
#include <string>
#include "Scene.h"


namespace dae
{
	class JsonReader final
	{
	public:
		JsonReader();

		bool readLevelJson(const std::string& filePath, Scene& scene);
		void setLevelBlockTexture(const std::string& texturePath);
		void setLevelEnemyTexture(const std::string& texturePath);
		void AddPlayer(GameObject* player) { m_Players.push_back(player); }

		//rule of 5
		~JsonReader() = default;
		JsonReader(const JsonReader& other) = delete;
		JsonReader(JsonReader&& other) = delete;
		JsonReader& operator=(const JsonReader& other) = delete;
		JsonReader& operator=(JsonReader&& other) = delete;

	private:
		std::string m_BlockTexturePath;
		std::string m_EnemyTexturePath;
		std::vector<GameObject*> m_Players;
	};
}

