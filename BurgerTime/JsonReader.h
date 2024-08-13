#pragma once
#include <string>
#include "Scene.h"
#include <glm/glm.hpp>

namespace dae
{

	struct Topping
	{
		std::vector <glm::vec3> Left;
		std::vector <glm::vec3> Middle;
		std::vector <glm::vec3> Right;
	};

	class JsonReader final
	{
	public:
		JsonReader(int screenWidth, int screenHeight,int numberOfColumns, int m_NumberOfRows);

		bool readLevelJson(const std::string& filePath, Scene& scene);

		void setLevelPlatform	(const std::shared_ptr<Texture2D>& texture);
		void setLevelLadder		(const std::shared_ptr<Texture2D>& texture);
		void setPlatterTexture	(const std::shared_ptr<Texture2D>& texture);
		void setLevelBurgerTopTexture		(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerMeatTexture		(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerLettuceTexture	(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerCheeseTexture	(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerTomatoTexture	(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerBottomTexture	(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);

		void setSubject(Subject* subject) { m_Subject = subject; }
		//rule of 5
		~JsonReader() = default;
		JsonReader(const JsonReader& other) = delete;
		JsonReader(JsonReader&& other) = delete;
		JsonReader& operator=(const JsonReader& other) = delete;
		JsonReader& operator=(JsonReader&& other) = delete;

	private:

		void BurgerPartLocation(int X, int Y, Topping& Topping);
		std::vector <glm::vec3> BurgerPartLocation(int X, int Y);
		std::vector<std::vector <glm::vec3>> m_PlatformLocations;

		void Platter(std::vector<std::unique_ptr<GameObject>>& platters, Scene& scene);
		void CombineTopping(std::vector<std::unique_ptr<GameObject>>& left, std::vector<std::unique_ptr<GameObject>>& middle, std::vector<std::unique_ptr<GameObject>>& right, Scene& scene);

		int m_ScreenWidth;
		int m_ScreenHeight;
		int m_NumberOfColumns;
		int m_NumberOfRows;

		int m_PlatformColumnWidth;
		int m_LadderColumnWidth;
		int m_RowHeight;

		//Platform number legend 
		//0 = empty
		//1 = platform
		//2 = BurgerTop
		//3 = BurgerMeat
		//4 = BurgerLettuce
		//5 = BurgerCheese
		//6 = BurgerTomato
		//7 = BurgerBottom

		std::shared_ptr<Texture2D> m_PlatformTexture;
		std::shared_ptr<Texture2D> m_LadderTexture;
		std::shared_ptr<Texture2D> m_PlatterTexture;
		std::shared_ptr<Texture2D> m_BurgerTopSideTexture;
		std::shared_ptr<Texture2D> m_BurgerTopMiddleTexture;
		std::shared_ptr<Texture2D> m_BurgerMeatSideTexture;
		std::shared_ptr<Texture2D> m_BurgerMeatMiddleTexture;
		std::shared_ptr<Texture2D> m_BurgerLettuceSideTexture;
		std::shared_ptr<Texture2D> m_BurgerLettuceMiddleTexture;
		std::shared_ptr<Texture2D> m_BurgerCheeseSideTexture;
		std::shared_ptr<Texture2D> m_BurgerCheeseMiddleTexture;
		std::shared_ptr<Texture2D> m_BurgerTomatoSideTexture;
		std::shared_ptr<Texture2D> m_BurgerTomatoMiddleTexture;
		std::shared_ptr<Texture2D> m_BurgerBottomSideTexture;
		std::shared_ptr<Texture2D> m_BurgerBottomMiddleTexture;
		
		Subject* m_Subject;
	};
}



