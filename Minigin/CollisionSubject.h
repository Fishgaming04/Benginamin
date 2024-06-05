#pragma once
#include "Observers.h"
#include "GameObject.h"
#include <vector>

namespace dae {
	
	struct CollisionInfo
	{
		GameObject* object1;
		GameObject* object2;
	};


	class CollisionSubject : public Subject
	{
	public:
		CollisionSubject();
		void update(double elapsedTime);
		void addStaticGameObject(GameObject* gameObject);
		void addMovingGameObject(GameObject* gameObject);
		void removeGameObject(GameObject* gameObject);


		virtual ~CollisionSubject() = default;
	private:

		bool CheckCollision(Rect4f object1, Rect4f object2);


		std::vector<GameObject*> m_StaticObjects;
		std::vector<GameObject*> m_MovingObjects;
	};
}
