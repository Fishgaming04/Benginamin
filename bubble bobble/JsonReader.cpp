#include "JsonReader.h"
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <vector>
#include "LevelCreater.h"


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
			//std::vector<std::vector<int>> EnemyData = obj["Enemies"].get<std::vector<std::vector<int>>>();

			LevelCreater levelCreater;
			levelCreater.SetLevelTexture(m_BlockTexturePath);
			levelCreater.GenerateLevel(scene, levelData);
		
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
