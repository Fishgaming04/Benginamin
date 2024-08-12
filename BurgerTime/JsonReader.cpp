#include "JsonReader.h"
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <vector>
#include "LevelBuilder.h"
#include <SDL.h>
#include "Texture2D.h"
#include "CollisionSubject.h"
#include "ToppingPartCollision.h"
#include "IsPressedThenFallComponent.h"
#include "BurgerPartsFallingCollisionComponent.h"
#include "TextureComponent.h"

namespace dae {

dae::JsonReader::JsonReader(int screenWidth, int screenHeight, int numberOfColumns, int numberOfRows)
	:m_ScreenWidth(screenWidth)
	, m_ScreenHeight(screenHeight)
	, m_NumberOfColumns(numberOfColumns)
	, m_NumberOfRows(numberOfRows)
	, m_PlatformColumnWidth( m_ScreenWidth / (m_NumberOfColumns + 1) )
	, m_LadderColumnWidth(m_PlatformColumnWidth / 2)
	, m_RowHeight(m_ScreenHeight / (m_NumberOfRows + 2))
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
			std::vector<int> Platforms = obj["Platforms"].get<std::vector<int>>();
			std::vector<std::vector<int>> Ladders = obj["Ladders"].get<std::vector<std::vector<int>>>();



			std::vector<bool>PlatterNeeded(m_NumberOfColumns, false);
			std::vector <glm::vec3> PlatterLocations;
			std::vector <glm::vec3> LadderLocations;
			std::vector <glm::vec3> PlatformLocations;
			Topping BurgerTopLocations;
			Topping BurgerMeatLocations;
			Topping BurgerLettuceLocations;
			Topping BurgerCheeseLocations;
			Topping BurgerTomatoLocations;
			Topping BurgerBottomLocations;

			for (std::vector<int> ladder : Ladders)
			{
				glm::vec3 ladderLocation;
				ladderLocation.x = static_cast<float>((ladder[0] * m_LadderColumnWidth) + m_PlatformColumnWidth /2);
				ladderLocation.y = static_cast<float>((ladder[1] + 1 ) * m_RowHeight);
				LadderLocations.push_back(ladderLocation);
			}	

			for (int indexY = 0; indexY < m_NumberOfRows; indexY++)
			{
				for (int indexX = 0; indexX < m_NumberOfColumns; indexX++)
				{
					if (Platforms[indexY * m_NumberOfColumns + indexX] > 0)
					{
						glm::vec3 platformLocation;
						platformLocation.x = static_cast<float>(indexX * m_PlatformColumnWidth + m_PlatformColumnWidth/2);
						platformLocation.y = static_cast<float>((indexY + 1) * m_RowHeight);
						PlatformLocations.push_back(platformLocation); 
					}
					if (Platforms[indexY * m_NumberOfColumns + indexX] > 1) {
						PlatterNeeded[indexX] = true;
						//burgerparts
						switch (Platforms[indexY * m_NumberOfColumns + indexX])
						{
						case 2:
						{
							BurgerPartLocation(indexX, indexY, BurgerTopLocations);
							break;
						}
						case 3:
						{
							BurgerPartLocation(indexX, indexY, BurgerMeatLocations);
							break;
						}
						case 4:
						{
							BurgerPartLocation(indexX, indexY, BurgerLettuceLocations);
							break;
						}
						case 5:
						{
							BurgerPartLocation(indexX, indexY, BurgerCheeseLocations);
							break;
						}
						case 6:
						{
							BurgerPartLocation(indexX, indexY, BurgerTomatoLocations);
							break;
						}
						case 7:
						{
							BurgerPartLocation(indexX, indexY, BurgerBottomLocations);
							break;
						}
						default:
							break;
						}

					}
				}
			}

			for (size_t index{}; index < PlatterNeeded.size(); ++index)
			{
				if (PlatterNeeded[index])
				{
					glm::vec3 platterLocation;
					platterLocation.x = static_cast<float>(index * m_PlatformColumnWidth + m_PlatformColumnWidth / 2 + (m_PlatformColumnWidth / 3));
					platterLocation.y = static_cast<float>(m_RowHeight * m_NumberOfRows);
					PlatterLocations.push_back(platterLocation);
				}
			}

			LevelBuilder builder;
			builder.SetLevelTexture(m_LadderTexture);
			builder.GenerateLevel(scene, LadderLocations, "Ladder", true);
			builder.SetLevelTexture(m_PlatformTexture);
			builder.GenerateLevel(scene, PlatformLocations, "Platform", true);
			builder.SetLevelTexture(m_PlatterTexture);
			builder.GenerateLevel(scene, PlatterLocations, "Platter", true);



			//BurgerTop
			builder.SetLevelTexture(m_BurgerTopSideTexture);
			auto left{ builder.GenerateLevel( BurgerTopLocations.Left, "Bun", false) };
			auto right{ builder.GenerateLevel( BurgerTopLocations.Right, "Bun", false, true) };
			builder.SetLevelTexture(m_BurgerTopMiddleTexture);
			auto middle{ builder.GenerateLevel( BurgerTopLocations.Middle, "Bun", false) };

			CombineTopping(left, middle, right, scene);
			//BurgerMeat
			builder.SetLevelTexture(m_BurgerMeatSideTexture);
			left  =	builder.GenerateLevel( BurgerMeatLocations.Left, "Topping", false);
			right = builder.GenerateLevel(BurgerMeatLocations.Right, "Topping", false, true);
			builder.SetLevelTexture(m_BurgerMeatMiddleTexture);
			middle = builder.GenerateLevel( BurgerMeatLocations.Middle, "Topping", false);

			CombineTopping(left, middle, right, scene);
			//BurgerLettuce
			builder.SetLevelTexture(m_BurgerLettuceSideTexture);
			left = builder.GenerateLevel( BurgerLettuceLocations.Left, "Topping", false);
			right = builder.GenerateLevel( BurgerLettuceLocations.Right, "Topping", false, true);
			builder.SetLevelTexture(m_BurgerLettuceMiddleTexture);
			middle = builder.GenerateLevel(BurgerLettuceLocations.Middle, "Topping", false);

			CombineTopping(left, middle, right, scene);
			//BurgerCheese
			builder.SetLevelTexture(m_BurgerCheeseSideTexture);
			left  = builder.GenerateLevel(BurgerCheeseLocations.Left, "Topping", false);
			right = builder.GenerateLevel( BurgerCheeseLocations.Right, "Topping", false, true);
			builder.SetLevelTexture(m_BurgerCheeseMiddleTexture);
			middle = builder.GenerateLevel( BurgerCheeseLocations.Middle, "Topping", false);

			CombineTopping(left, middle, right, scene);
			//BurgerTomato
			builder.SetLevelTexture(m_BurgerTomatoSideTexture);
			left = builder.GenerateLevel( BurgerTomatoLocations.Left, "Topping", false);
			right = builder.GenerateLevel( BurgerTomatoLocations.Right, "Topping", false, true);
			builder.SetLevelTexture(m_BurgerTomatoMiddleTexture);
			middle = builder.GenerateLevel( BurgerTomatoLocations.Middle, "Topping", false);

			CombineTopping(left, middle, right, scene);
			//BurgerBottom
			builder.SetLevelTexture(m_BurgerBottomSideTexture);
			left = builder.GenerateLevel( BurgerBottomLocations.Left, "Topping", false);
			right = builder.GenerateLevel( BurgerBottomLocations.Right, "Topping", false, true);
			builder.SetLevelTexture(m_BurgerBottomMiddleTexture);
			middle = builder.GenerateLevel( BurgerBottomLocations.Middle, "Topping", false);

			CombineTopping(left, middle, right, scene);

		}
		return true;
	}

	void JsonReader::BurgerPartLocation(int X, int Y, Topping& Topping)
	{
		std::vector<glm::vec3> temp{ BurgerPartLocation(X, Y) };
		Topping.Left.push_back(temp[0]);
		Topping.Middle.push_back(temp[1]);
		Topping.Middle.push_back(temp[2]);
		Topping.Right.push_back(temp[3]);
	}

	std::vector <glm::vec3> JsonReader::BurgerPartLocation(int X, int Y)
	{
		std::vector <glm::vec3> BurgerPartLocations;
		int widthMiddle;
		int heightMiddle;		
		SDL_QueryTexture(m_BurgerBottomMiddleTexture.get()->GetSDLTexture(), nullptr, nullptr, &widthMiddle, &heightMiddle);

		for (int index{ -2 }; index < 2; index++)
		{
			glm::vec3 BurgerPartLocation;
			BurgerPartLocation.x = static_cast<float>(X * m_PlatformColumnWidth + m_PlatformColumnWidth/2 + (2 * m_PlatformColumnWidth / 3 ) + widthMiddle * index);
			BurgerPartLocation.y = static_cast<float>((Y + 1) * m_RowHeight - heightMiddle/2);
			BurgerPartLocation.z = 1;
			BurgerPartLocations.push_back(BurgerPartLocation);
		}

		return BurgerPartLocations;
	}

	void JsonReader::CombineTopping(std::vector<std::unique_ptr<GameObject>>& left, std::vector<std::unique_ptr<GameObject>>& middle, std::vector<std::unique_ptr<GameObject>>& right, Scene& scene)
	{
		//auto& recourceManager = dae::ResourceManager::GetInstance();
		auto& CollsionSubject = dae::CollisionSubject::GetInstance();
		for (size_t index{}; index < left.size(); ++index) {
			auto leftObject			= left[index].get();
			auto middleLeftObject		= middle[index *2].get();
			auto middleRightObject		= middle[index*2 +1].get();
			auto rightObject			= right[index].get();



			std::unique_ptr Parent = std::make_unique<GameObject>();
			Parent->setLocalPosition(leftObject->GetTransform()->getLocalposition()) ;
			auto size{ leftObject->GetTransform()->getSize() };
			Parent.get()->GetTransform()->SetSize(size.x * 4, size.y);
			Parent.get()->setTag("ParentTopping");
			CollsionSubject.addMovingGameObject(Parent.get());
			Parent.get()->AddComponent<IsPressedThenFallComponent>();
			Parent.get()->GetComponent<IsPressedThenFallComponent>()->SetPressDistance(3);
			Parent.get()->GetComponent<IsPressedThenFallComponent>()->SetFallingSpeed(10);
			///Parent.get()->AddComponent<TextureComponent>();
			//Parent.get()->GetComponent<TextureComponent>()->SetTexture(recourceManager.LoadTexture("../Data/BurgerTime/Ingredients/ParentDebugTexture.png"));

			leftObject->SetParent(Parent.get(), true);
			middleLeftObject->SetParent(Parent.get(), true);
			middleRightObject->SetParent(Parent.get(), true);
			rightObject->SetParent(Parent.get(), true);

			Parent.get()->AddComponent<BurgerPartsFallingCollisionComponent>();
			leftObject->AddComponent<ToppingPartCollision>();
			middleLeftObject->AddComponent<ToppingPartCollision>();
			middleRightObject->AddComponent<ToppingPartCollision>();
			rightObject->AddComponent<ToppingPartCollision>();


			CollsionSubject.AddObserver(Parent.get()->GetComponent<BurgerPartsFallingCollisionComponent>());
			CollsionSubject.AddObserver(leftObject->GetComponent<ToppingPartCollision>());
			CollsionSubject.AddObserver(middleLeftObject->GetComponent<ToppingPartCollision>());
			CollsionSubject.AddObserver(middleRightObject->GetComponent<ToppingPartCollision>());
			CollsionSubject.AddObserver(rightObject->GetComponent<ToppingPartCollision>());

			scene.Add(std::move(left[index]));
			scene.Add(std::move(middle[index * 2]));
			scene.Add(std::move(middle[index * 2 + 1]));
			scene.Add(std::move(right[index]));
			scene.Add(std::move(Parent));

		}
	}


	void JsonReader::setLevelPlatform(const std::shared_ptr<Texture2D>& texture)
	{
		m_PlatformTexture = texture;

	}

	void JsonReader::setLevelLadder(const std::shared_ptr<Texture2D>& texture)
	{
		m_LadderTexture = texture;
	}

	void JsonReader::setPlatterTexture(const std::shared_ptr<Texture2D>& texture)
	{
		m_PlatterTexture = texture;
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