#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include <iostream>
#include "Components.h" 
namespace dae {


	GameObject::GameObject()
		:m_PosPtr{new Transform()}
		,m_Parent{nullptr}
		,m_isDirty{false}
		,m_IslookingLeft{false}
		, m_SetForRemoval{ false }
		, m_Tag{ "" }
	{
	}

	GameObject::~GameObject() {
		delete m_PosPtr;
		m_PosPtr = nullptr;
		for (Component* Comp : m_ComponentPtr) {
			delete Comp;
			Comp = nullptr;
		}
		for (GameObject* child : m_Childeren) {
			child->SetParent(nullptr, true);
		}
		if (m_Parent)
		{
			m_Parent->removeChild(this, true);
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

	void GameObject::setLocalPosition(float x, float y, float z) {
		setLocalPosition(glm::vec3(x, y, z));
	}

	void GameObject::setLocalPosition(glm::vec3 Pos) {
		m_PosPtr->SetLocalPosition(Pos);
		SetDirty();
	}

	void GameObject::setTag(std::string tag)
	{
		m_Tag = tag;
	}

	bool GameObject::getIsLookingLeft()
	{
		return m_IslookingLeft;
	}

	void GameObject::setForRemoval()
	{
		m_SetForRemoval = true;
	}

	std::string GameObject::getTag()
	{
		return m_Tag;
	}

	void GameObject::NotifyObservers(Event event)
	{
		for (auto observer : m_observers){
			event;
			observer;
			//observer->OnNotify(event, this);
		}
	}

	void GameObject::UpdatePos() {
		if (m_isDirty) {
			float perviousposition = m_PosPtr->getWorldposition().x;
			if (m_Parent) {
				m_PosPtr->SetWorldPosition( m_Parent->GetTransform()->getWorldposition() + m_PosPtr->getLocalposition());
			}
			else {
				m_PosPtr->SetWorldPosition(m_PosPtr->getLocalposition());
			}
			m_isDirty = false;
			if (m_PosPtr->getWorldposition().x - perviousposition > 0)
			{
				m_IslookingLeft = false;
			}
			else if (m_PosPtr->getWorldposition().x - perviousposition < 0)
			{
				m_IslookingLeft = true;
			}
		}
	}

	Transform* GameObject::GetTransform() {
		UpdatePos();
		return m_PosPtr;
	}

	void GameObject::AddObserver(Observer* observer){
		m_observers.push_back(observer);
	}

	void GameObject::RemoveObserver(Observer* observer){
		if (observer) {
			m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
		}
	}

	GameObject* GameObject::GetParent() const {
		return m_Parent;
	}

	void GameObject::SetDirty() {
		m_isDirty = true;
		for (GameObject* child : m_Childeren) {
			child->SetDirty();
		}
	}

	void GameObject::SetParent(GameObject* parent, bool keepLocationChilderen) {
		if (parent != m_Parent && parentNotChildCheck(parent) && parent != this) {
			if (m_Parent)
			{
				m_Parent->removeChild(this, keepLocationChilderen);
			}
			m_Parent = parent;
			UpdatePos();
			if (parent) {
				parent->addChild(this);
			};
		}
	}
	
	void GameObject::addChild(GameObject* child) {
		if (!child && child != m_Parent) {
			for (unsigned int index{}; index < m_Childeren.size(); ++index) {
				if (m_Childeren[index] == child) {
					return;
				}
			}
			m_Childeren.push_back(child);
		}
	}

	void GameObject::removeChild(GameObject* orphan, bool keepLocationChilderen) {
		if (orphan != m_Parent && orphan) {
			for (unsigned int index{ }; index < m_Childeren.size(); ++index) {
				if (m_Childeren[index] == orphan) {
					if (keepLocationChilderen) {
						m_Childeren[index]->setLocalPosition(m_Childeren[index]->GetTransform()->getWorldposition());
					}
					else {
						m_Childeren[index]->SetDirty();
					}
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