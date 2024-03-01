#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <iostream>
namespace dae {


	GameObject::GameObject()
		:m_PosPtr{new Transform()}
		,m_Parent{nullptr}
	{
	}

	GameObject::~GameObject() {
		delete m_PosPtr;
		m_PosPtr = nullptr;
		for (Component* Comp : m_ComponentPtr) {
			delete Comp;
			Comp = nullptr;
		}
	};

	void GameObject::Update(double elapsedTime) {
		for (Component* Comp : m_ComponentPtr)
		{
			Comp->Update(elapsedTime);
		}
	}

	void GameObject::Render() const {
		for (Component* Comp : m_ComponentPtr)
		{
			Comp->Render();
		}
	}

	void GameObject::setLocalPosition(int x, int y, int z) {
		x;
		y;
		z;
	}



	Transform* GameObject::GetTransform() {
		return m_PosPtr;
	}


	GameObject* GameObject::GetParent() const {
		return m_Parent;
	}

	void GameObject::SetParent(GameObject* parent) {
		if (parent != m_Parent && parentNotChildCheck(parent) && parent != this) {
			if (!m_Parent)
			{
				m_Parent->removeChild(this);
			}
			m_Parent = parent;
			if (parent) {
				parent->addChild(this);
			};
			// TODO: update position, rotation and scale
		}
	}
	
	void GameObject::addChild(GameObject* child) {
		if (!child && child != m_Parent) {
			for (int index{}; index < m_Childeren.size(); ++index) {
				if (m_Childeren[index] == child) {
					return;
				}
			}
			m_Childeren.push_back(child);
		}
	}


	void GameObject::removeChild(GameObject* orphan) {
		if (orphan != m_Parent && orphan) {
			for (int index{}; index < m_Childeren.size(); ++index) {
				if (m_Childeren[index] == orphan) {
					m_Childeren[index]->SetParent(nullptr);
					m_Childeren.erase(m_Childeren.begin() + index);
					return;
				}
			}
		}
	}


	bool GameObject::parentNotChildCheck(GameObject* parent) {
		for (GameObject* child : m_Childeren) {
			if (child == parent){
				return false;
			}
		}
		return true;
	}

	int GameObject::GetChildCount() {
		return int(m_Childeren.size());
	}

	GameObject* GameObject::GetChildAtIndex(int index) const {
		return m_Childeren[index];
	}

}