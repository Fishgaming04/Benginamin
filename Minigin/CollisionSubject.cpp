#include "CollisionSubject.h"
#include <glm/glm.hpp>

namespace dae
{
	CollisionSubject::CollisionSubject()
		:Subject()
	{
	}
	void CollisionSubject::update(double elapsedTime)
	{
		size_t currentObject{};
		for (auto& moving : m_MovingObjects)
		{
			auto movingPos = moving->GetTransform()->GetWorldRect();
			for (auto& staticObj : m_StaticObjects)
			{
				if (CheckCollision(movingPos, staticObj->GetTransform()->GetWorldRect()))
				{
					CollisionInfo info{ moving, staticObj };
					Notify(Event::collision ,this , info);
				}
			}
			currentObject++;
			for (size_t index{ currentObject }; index < m_MovingObjects.size(); ++index)
			{
				if (CheckCollision(movingPos, m_MovingObjects[index]->GetTransform()->GetWorldRect()))
				{
					CollisionInfo info{ moving, m_MovingObjects[index] };
					Notify(Event::collision, this, info);
				}
			}
		}
	}

	void CollisionSubject::addStaticGameObject(GameObject* gameObject)
	{
		if (!gameObject) {
			return;
		}
		for (auto go : m_StaticObjects)
		{
			if (go == gameObject)
				return;
		}
		m_StaticObjects.push_back(gameObject);
	}

	void CollisionSubject::addMovingGameObject(GameObject* gameObject)
	{
		if (!gameObject) {
			return;
		}
		for (auto go : m_MovingObjects)
		{
			if (go == gameObject)
				return;
		}
		m_MovingObjects.push_back(gameObject);
	}

	void CollisionSubject::removeGameObject(GameObject* gameObject)
	{
		if (!gameObject) {
			return;
		}
		for (unsigned int index{}; index < m_StaticObjects.size(); ++index)
		{
			if (m_StaticObjects[index] == gameObject)
			{
				m_StaticObjects.erase(m_StaticObjects.begin() + index);
				return;
			}
		}
		for (unsigned int index{}; index < m_MovingObjects.size(); ++index)
		{
			if (m_MovingObjects[index] == gameObject)
			{
				m_MovingObjects.erase(m_MovingObjects.begin() + index);
				return;
			}
		}
	}

	bool CollisionSubject::CheckCollision(Rect4f object1, Rect4f object2)
	{
		if (object1.x < object2.x + object2.width &&
			object1.x + object1.width > object2.x &&
			object1.y < object2.y + object2.height &&
			object1.y + object1.height > object2.y)
		{
			return true;
		}
	}

}