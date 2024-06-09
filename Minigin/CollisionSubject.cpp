#include "CollisionSubject.h"
#include <glm/glm.hpp>
#include "Transform.h"
#include <iostream>
namespace dae
{
	CollisionSubject::CollisionSubject()
		:Subject()
	{
	}

	void CollisionSubject::update(double)
	{
		size_t currentObject{};
		for (auto& moving : m_MovingObjects)
		{
			auto movingPos = moving->GetTransform()->GetWorldRect();
			for (auto& staticObj : m_StaticObjects)
			{
				if (CheckCollision(movingPos, staticObj->GetTransform()->GetWorldRect()))
				{
					ReportCollision(moving, staticObj);
				}
			}
			currentObject++;
			for (size_t index{ currentObject }; index < m_MovingObjects.size(); ++index)
			{
				if (CheckCollision(movingPos, m_MovingObjects[index]->GetTransform()->GetWorldRect()))
				{
					ReportCollision(moving, m_MovingObjects[index]);
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
		return false;
	}

	void CollisionSubject::ReportCollision( GameObject* moving,  GameObject* staticObj)
	{
		Rect4f bounds{ moving->GetTransform()->GetWorldRect() };
		Rect4f otherBounds{ staticObj->GetTransform()->GetWorldRect() };
		glm::vec3 direction{ 0,0,0 };
		OverlapPercentage overlapPercentage{ 0,0,0 };
		if (IsLeftCollision(bounds, otherBounds))
		{
			direction.x = -1;
			overlapPercentage.x = OverlapPercentageX(bounds, otherBounds);
		}
		else if (IsRightCollision(bounds, otherBounds))
		{
			direction.x = 1;
			overlapPercentage.x = OverlapPercentageX(bounds, otherBounds);
		}
		if (IsBottomCollision(bounds, otherBounds))
		{
			direction.y = -1;
			overlapPercentage.y = OverlapPercentageY(bounds, otherBounds);
		}
		else if (IsTopCollision(bounds, otherBounds))
		{
			direction.y = 1;
			overlapPercentage.y = OverlapPercentageY(bounds, otherBounds);
		}
		overlapPercentage.Total = OverlapPercentageTotal(bounds, otherBounds);
		CollisionInfo info{ moving, staticObj, direction, overlapPercentage };
		Notify(Event::collision, this, info);
	}



	bool CollisionSubject::IsLeftCollision(const Rect4f bounds, const Rect4f otherBounds)
	{
		return bounds.x < otherBounds.x && bounds.x + bounds.width > otherBounds.x;
	}
	bool CollisionSubject::IsRightCollision(const Rect4f bounds, const Rect4f otherBounds)
	{
		return bounds.x < (otherBounds.x + otherBounds.width) && (bounds.x + bounds.width) > (otherBounds.x + otherBounds.width);
	}
	bool CollisionSubject::IsBottomCollision(const Rect4f bounds, const Rect4f otherBounds)
	{
		return bounds.y > (otherBounds.y + otherBounds.height) && bounds.y + bounds.height > (otherBounds.y + otherBounds.height);
	}
	bool CollisionSubject::IsTopCollision(const Rect4f bounds, const Rect4f otherBounds)
	{
		//return bounds.y + bounds.height > otherBounds.y + otherBounds.height && bounds.y > otherBounds.y;
		return bounds.y < otherBounds.y  && bounds.y + bounds.height > otherBounds.y;
	}

	float CollisionSubject::OverlapPercentageX(const Rect4f bounds, const Rect4f otherBounds)
	{
		float overlapX{ std::min((bounds.x + bounds.width), (otherBounds.x + otherBounds.width)) - std::max(bounds.x, otherBounds.x) };
		float smallestX{ std::min((bounds.x + bounds.width) - bounds.x, (otherBounds.x + otherBounds.width) - otherBounds.x) };

		return overlapX / smallestX;
	}
	float CollisionSubject::OverlapPercentageY(const Rect4f bounds, const Rect4f otherBounds)
	{
		float overlapY{ std::min(bounds.y + bounds.height, (otherBounds.y + otherBounds.height)) - std::max(bounds.y, otherBounds.y) };
		float smallestY{ std::min(bounds.height, (otherBounds.height)) };

		return overlapY / smallestY;
	}
	float CollisionSubject::OverlapPercentageTotal(const Rect4f bounds, const Rect4f otherBounds)
	{
		return OverlapPercentageX(bounds, otherBounds) * OverlapPercentageY(bounds, otherBounds);
	}
}