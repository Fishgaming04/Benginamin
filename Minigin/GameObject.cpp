#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
namespace dae {


	GameObject::GameObject() 
		:m_TransformPtr{ new Transform() }
	{
	}

	GameObject::~GameObject() = default;

	void GameObject::Update() {
		for (Component* Comp : m_ComponentPtr)
		{
			Comp->Update();
		}
	}

	void GameObject::Render() const
	{
		for (Component* Comp : m_ComponentPtr)
		{
			Comp->Render();
		}

		//const auto& pos = m_transform.GetPosition();
		//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
	}


	Transform* GameObject::GetTransform() {
		return m_TransformPtr;
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