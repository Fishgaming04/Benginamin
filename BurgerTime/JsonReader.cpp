#include "JsonReader.h"
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <vector>
#include "LevelBuilder.h"


namespace dae {

dae::JsonReader::JsonReader(int screenWidth, int screenHeight, int numberOfColumns, int numberOfRows)
	:m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_NumberOfColumns(numberOfColumns)
	, m_NumberOfRows(numberOfRows)
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
		std::vector<int> Platforms = obj["Platforms"].get<std::vector<int>>();
		std::vector<std::vector<int>> Ladders = obj["Ladders"].get<std::vector<std::vector<int>>>();




		std::vector <std::vector<int>> LadderLocations;
		std::vector <std::vector<int>> PlatformLocations;
		int PlatformColumnWidth{ m_ScreenWidth / (m_NumberOfColumns + 1) };
		int ladderColumnWidth{ PlatformColumnWidth / 2  };
		int RowHeight{ m_ScreenHeight / (m_NumberOfRows + 2) };
		for (std::vector<int> ladder : Ladders)
		{
			std::vector<int> ladderLocation;
			ladderLocation.push_back((ladder[0] * ladderColumnWidth) + PlatformColumnWidth /2);
			ladderLocation.push_back((ladder[1] + 1 ) * RowHeight);
			LadderLocations.push_back(ladderLocation);
		}	

		for (int indexY = 0; indexY < m_NumberOfRows; indexY++)
		{
			for (int indexX = 0; indexX < m_NumberOfColumns; indexX++)
			{
				if (Platforms[indexY * m_NumberOfColumns + indexX] > 0)
				{
					std::vector<int> platformLocation;
					platformLocation.push_back(indexX * PlatformColumnWidth + PlatformColumnWidth/2);
					platformLocation.push_back((indexY + 1) * RowHeight);
					PlatformLocations.push_back(platformLocation); 
				}
			}
		}

		LevelBuilder builder;
		builder.SetLevelTexture(m_LadderTexture);
		builder.GenerateLevel(scene, LadderLocations, "Ladder", true);
		builder.SetLevelTexture(m_PlatformTexture);
		builder.GenerateLevel(scene, PlatformLocations, "Platform", true);







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

	void JsonReader::setLevelPlatform(const std::shared_ptr<Texture2D>& texture)
	{
		m_PlatformTexture = texture;

	}

	void JsonReader::setLevelLadder(const std::shared_ptr<Texture2D>& texture)
	{
		m_LadderTexture = texture;
	}

	void JsonReader::setLevelBurgerTopTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle)
	{
		m_BurgerTopSideTexture = TextureBurgerPartSide;
		m_BurgerTopMiddleTexture = TextureBurgerPartMiddle;
	}

	void JsonReader::setLevelBurgerMeatTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle)
	{
		m_BurgerMeatMiddleTexture = TextureBurgerPartMiddle;
		m_BurgerMeatSideTexture = TextureBurgerPartSide;
	}

	void JsonReader::setLevelBurgerLettuceTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle)
	{
		m_BurgerLettuceMiddleTexture = TextureBurgerPartMiddle;
		m_BurgerLettuceSideTexture = TextureBurgerPartSide;
	}

	void JsonReader::setLevelBurgerCheeseTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle)
	{
		m_BurgerCheeseMiddleTexture = TextureBurgerPartMiddle;
		m_BurgerCheeseSideTexture = TextureBurgerPartSide;
	}

	void JsonReader::setLevelBurgerTomatoTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle)
	{
		m_BurgerTomatoMiddleTexture = TextureBurgerPartMiddle;
		m_BurgerTomatoSideTexture = TextureBurgerPartSide;
	}

	void JsonReader::setLevelBurgerBottomTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle)
	{
		m_BurgerBottomMiddleTexture = TextureBurgerPartMiddle;
		m_BurgerBottomSideTexture = TextureBurgerPartSide;
	}


}