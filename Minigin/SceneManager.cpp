#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update(double elapsedTime)
{
	for(auto& scene : m_scenes)
	{
		scene->Update(elapsedTime);
	}
}

void dae::SceneManager::Render()
{
	for (const auto& scene : m_scenes)
	{
		scene->Render();
	}
}

void dae::SceneManager::Romoval()
{
	for (const auto& scene : m_scenes)
	{
		scene->DeleteObjects();
	}
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}
