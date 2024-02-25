#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
namespace dae {


	GameObject::~GameObject() = default;

	void GameObject::Update() {
		for (Component* Comp : m_ComponentPtr)
		{
			Comp->Update(*this);
		}
	}

	void GameObject::Render() const
	{
		//
		//for (Component* Comp : m_Component)
		//{
		//	Comp->Update(*this);
		//}

		//const auto& pos = m_transform.GetPosition();
		//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
	}

	template<typename Comp>
	Comp* GameObject::GetComponent() {
		for (Component* Components : m_ComponentPtr) {
			if (dynamic_cast<Comp*>(Components)) {
				return Components;
			}
		}
		return nullptr;
	}

	template<typename Comp>
	bool GameObject::AddComponent() {
		if (std::is_base_of<Component, Comp>) {
			Comp* temp{ new Comp() };
			m_ComponentPtr.push_back(temp);
			return true;
		}
		return false;
	}


	template<typename Comp>
	bool GameObject::RemoveComponent() {
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

	//template<typename Comp>
	//Comp* findComponent() {
	//	auto it = std::find_if(vec.begin(), vec.end(), [&](const MyClass& obj) {
	//		return 
	//
	//	}
	//}




	//void dae::GameObject::SetTexture(const std::string& filename)
	//{
	//	//m_texture = ResourceManager::GetInstance().LoadTexture(filename);
	//}
	//
	//void dae::GameObject::SetPosition(float x, float y)
	//{
	//	m_transform.SetPosition(x, y, 0.0f);
	//}
}