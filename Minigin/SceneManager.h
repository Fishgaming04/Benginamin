#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"
#include "GameObject.h"

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Update(double elapsedTime);
		void Render();
		void Romoval();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_scenes;
	};
}
