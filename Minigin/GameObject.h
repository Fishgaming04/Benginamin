#pragma once
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include "Transform.h"
#include "Components.h"
#include <type_traits>


namespace dae
{
	class Texture2D;
	class Transform;
	// todo: this should become final.
	class GameObject final
	{
	public:
		virtual void Update(double elapsedTime);
		virtual void Render() const;

		template<typename Comp>
		bool AddComponent();

		template<typename Comp>
		bool RemoveComponent();

		template<typename Comp>
		bool HasComponent();

		template<typename Comp>
		Comp* GetComponent();


		GameObject* GetParent() const;
		void SetParent(GameObject* parent);
		int GetChildCount();
		GameObject* GetChildAtIndex(int index) const ;


		Transform* GetTransform();

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		void addChild(GameObject* child);
		void removeChild(GameObject* orphan);

		bool parentNotChildCheck(GameObject* parent);

		GameObject* m_Parent;
		std::vector<GameObject*> m_Childeren;
				
		Transform* m_TransformPtr;
		std::vector<Component*> m_ComponentPtr;

		// todo: mmm, every gameobject has a texture? Is that correct?
		// std::shared_ptr<Texture2D> m_texture{};
	};


	template<typename Comp>
	inline Comp* GameObject::GetComponent() {
		for (Component* Components : m_ComponentPtr) {
			auto temp = dynamic_cast<Comp*>(Components);
			if (temp != nullptr) {
				return temp;
			}
		}
		return nullptr;
	}

	template<typename Comp>
	inline bool GameObject::HasComponent() {
		for (Component* Components : m_ComponentPtr) {
			if (dynamic_cast<Comp*>(Components)) {
				return true;
			}
		}
		return false;
	}

	template<typename Comp>
	inline bool GameObject::AddComponent() {
		if (std::is_base_of<Component, Comp>()) {
			Comp* temp{ new Comp(this) };
			m_ComponentPtr.push_back(temp);
			return true;
		}
		return false;
	}


	template<typename Comp>
	inline bool GameObject::RemoveComponent() {
		for (int index{}; index < m_ComponentPtr.size(); index++) {
			if (dynamic_cast<Comp*>(m_ComponentPtr[index])) {
				delete m_ComponentPtr[index];
				m_ComponentPtr = nullptr;
				m_ComponentPtr.erase(m_ComponentPtr.begin() + index);
				return true;
			}
		}
		return false;
	}





}