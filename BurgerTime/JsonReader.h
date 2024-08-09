#pragma once
#include <string>
#include "Scene.h"


namespace dae
{
	class JsonReader final
	{
	public:
		JsonReader(int screenWidth, int screenHeight,int numberOfColumns, int m_NumberOfRows);

		bool readLevelJson(const std::string& filePath, Scene& scene);
		void setLevelPlatform(const std::shared_ptr<Texture2D>& texture);
		void setLevelLadder(const std::shared_ptr<Texture2D>& texture);
		void setLevelBurgerTopTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerMeatTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerLettuceTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerCheeseTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerTomatoTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);
		void setLevelBurgerBottomTexture(const std::shared_ptr<Texture2D>& TextureBurgerPartSide, const std::shared_ptr<Texture2D>& TextureBurgerPartMiddle);



		//rule of 5
		~JsonReader() = default;
		JsonReader(const JsonReader& other) = delete;
		JsonReader(JsonReader&& other) = delete;
		JsonReader& operator=(const JsonReader& other) = delete;
		JsonReader& operator=(JsonReader&& other) = delete;

	private:

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

		int m_ScreenWidth;
		int m_ScreenHeight;
		int m_NumberOfColumns;
		int m_NumberOfRows;

	};
}



