#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(){
	for (Component* Comp : m_Component)
	{
		Comp->Update(*this);
	}
}

void dae::GameObject::Render() const 
{
	//const auto& pos = m_transform.GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

template<typename Comp>
bool dae::GameObject::addComponent() {
	if (std::is_base_of<Component, Comp>) {
		m_Component.push_back(Comp);
		return true;
	}
	return false;
}


//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	//m_texture = ResourceManager::GetInstance().LoadTexture(filename);
//}
//
//void dae::GameObject::SetPosition(float x, float y)
//{
//	m_transform.SetPosition(x, y, 0.0f);
//}
