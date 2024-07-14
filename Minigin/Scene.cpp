#include "Scene.h"
#include "GameObject.h"

#include <algorithm>

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene() = default;

void Scene::Add(std::unique_ptr<GameObject> object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(std::unique_ptr<GameObject> object)
{
	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void Scene::Update(double elapsedTime)
{
	for(auto& object : m_objects)
	{
		object->Update(elapsedTime);
	}
}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		object->Render();
	}
}

void dae::Scene::DeleteObjects()
{
	for (size_t index{ m_objects.size() }; index > 0; --index){
		if (m_objects[index].get()->getRemove())
		{
			m_objects[index].reset();
			m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), m_objects[index]), m_objects.end());
		}
	}
}

