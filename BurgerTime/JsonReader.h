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
		void setLevelPlatformTexture(const std::string& texturePath);
		void setLevelLadderTexture(const std::string& texturePath);
		void setLevelBurgerTopTexture(const std::string& texturePath);
		void setLevelBurgerMeatTexture(const std::string& texturePath);
		void setLevelBurgerLettuceTexture(const std::string& texturePath);
		void setLevelBurgerCheeseTexture(const std::string& texturePath);
		void setLevelBurgerTomatoTexture(const std::string& texturePath);
		void setLevelBurgerBottomTexture(const std::string& texturePath);



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

		std::string m_PlatformTexturePath;
		std::string m_LadderTexturePath;
		std::string m_BurgerTopTexturePath;
		std::string m_BurgerMeatTexturePath;
		std::string m_BurgerLettuceTexturePath;
		std::string m_BurgerCheeseTexturePath;
		std::string m_BurgerTomatoTexturePath;
		std::string m_BurgerBottomTexturePath;
	};
}



