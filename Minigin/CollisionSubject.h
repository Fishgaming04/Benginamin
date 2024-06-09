#pragma once
#include "Observers.h"
#include "GameObject.h"
#include <vector>
#include "Singleton.h"
namespace dae {
	
	struct OverlapPercentage
	{
		float x;
		float y;
		float Total;
	};

	struct CollisionInfo
	{
		GameObject* MovingSubject;
		GameObject* CollisionObject;
		glm::vec3 CollisionDirection;
		OverlapPercentage overlapPercentage;
	};


	class CollisionSubject final : public Subject, public Singleton<CollisionSubject>
	{
	public:
		CollisionSubject();
		void update(double);
		void addStaticGameObject(GameObject* gameObject);
		void addMovingGameObject(GameObject* gameObject);
		void removeGameObject(GameObject* gameObject);





		virtual ~CollisionSubject() = default;
	private:

		bool CheckCollision(Rect4f object1, Rect4f object2);

		void ReportCollision( GameObject* moving,  GameObject* staticObj);


		//Code From Jolan Plaum slighty modified to work in this project
		bool IsLeftCollision(const Rect4f bounds, const Rect4f otherBounds);
		bool IsRightCollision(const Rect4f bounds, const Rect4f otherBounds);
		bool IsBottomCollision(const Rect4f bounds, const Rect4f otherBounds);
		bool IsTopCollision(const Rect4f bounds, const Rect4f otherBounds);

		float OverlapPercentageX(const Rect4f bounds, const Rect4f otherBounds);
		float OverlapPercentageY(const Rect4f bounds, const Rect4f otherBounds);
		float OverlapPercentageTotal(const Rect4f bounds, const Rect4f otherBounds);
		//End of code from Jolan Plaum


		std::vector<GameObject*> m_StaticObjects;
		std::vector<GameObject*> m_MovingObjects;
	};
}
