#include "JsonReader.h"
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <vector>
#include "LevelCreater.h"
#include "EnemyCreater.h"

dae::JsonReader::JsonReader()
	:m_BlockTexturePath{}
	, m_EnemyTexturePath{}
{
}

bool dae::JsonReader::readLevelJson(const std::string& filePath, Scene& scene)
{
	std::ifstream inputFile;

	inputFile.open(filePath, std::ios::in);

	if (!inputFile.is_open()) {
		std::cout << "Failed to open " << filePath << "\n";
		return false;
	}

	// Parse the JSON file
	nlohmann::json doc;
		inputFile >> doc;
		for (const auto& obj : doc) {
			// Extract the "type" and "loc" values
			std::vector<std::vector<int>> levelData = obj["Blocks"].get<std::vector<std::vector<int>>>();
			EnemiesSpawning EnemyData;
			EnemyData.name = obj["EnemyType"];
			EnemyData.amount = obj["Amount"];

			LevelCreater levelCreater;
			levelCreater.SetLevelTexture(m_BlockTexturePath);
			levelCreater.GenerateLevel(scene, levelData);
			EnemyCreater enemyCreater;
			enemyCreater.SetScene(&scene);
			if (m_Players.size() > 0) {
				for (auto player : m_Players) {
					enemyCreater.addPlayer(player);
				}	
			}
			enemyCreater.CreateEnemy(EnemyData);
		}
		return true;
}

void dae::JsonReader::setLevelBlockTexture(const std::string& texturePath)
{
	m_BlockTexturePath = texturePath;
}

void dae::JsonReader::setLevelEnemyTexture(const std::string& texturePath)
{
	m_EnemyTexturePath = texturePath;
}
