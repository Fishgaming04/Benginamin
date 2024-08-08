#include "JsonReader.h"
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <vector>


namespace dae {

dae::JsonReader::JsonReader()
	//:m_BlockTexturePath{}
	//, m_EnemyTexturePath{}
{
}

bool dae::JsonReader::readLevelJson(const std::string& filePath, Scene& scene)
{
	scene;
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
		std::vector<int> PlatformLocations = obj["Platforms"].get<std::vector<int>>();
		std::vector<std::vector<int>> LadderLocations = obj["Ladders"].get<std::vector<std::vector<int>>>();

		for (int platform : PlatformLocations) {
			std::cout << "Platform: " << platform << "\n";
		}	


		//LevelCreater levelCreater;
		//levelCreater.SetLevelTexture(m_BlockTexturePath);
		//levelCreater.GenerateLevel(scene, levelData);
		//EnemyCreater enemyCreater;
		//enemyCreater.SetScene(&scene);
		//if (m_Players.size() > 0) {
		//	for (auto player : m_Players) {
		//		enemyCreater.addPlayer(player);
		//	}
		//}
		//enemyCreater.CreateEnemy(EnemyData);
	}
	return true;
}

	void JsonReader::setLevelPlatformTexture(const std::string& texturePath)
	{
		m_PlatformTexturePath = texturePath;
	}

	void JsonReader::setLevelLadderTexture(const std::string& texturePath)
	{
		m_LadderTexturePath = texturePath;
	}

	void JsonReader::setLevelBurgerTopTexture(const std::string& texturePath)
	{
		m_BurgerTopTexturePath = texturePath;
	}

	void JsonReader::setLevelBurgerMeatTexture(const std::string& texturePath)
	{
		m_BurgerMeatTexturePath = texturePath;
	}

	void JsonReader::setLevelBurgerLettuceTexture(const std::string& texturePath)
	{
		m_BurgerLettuceTexturePath = texturePath;
	}

	void JsonReader::setLevelBurgerCheeseTexture(const std::string& texturePath)
	{
		m_BurgerCheeseTexturePath = texturePath;
	}

	void JsonReader::setLevelBurgerTomatoTexture(const std::string& texturePath)
	{
		m_BurgerTomatoTexturePath = texturePath;
	}

	void JsonReader::setLevelBurgerBottomTexture(const std::string& texturePath)
	{
		m_BurgerBottomTexturePath = texturePath;
	}



}