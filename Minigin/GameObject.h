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

	// todo: this should become final.
	class GameObject
	{
	public:
		virtual void Update();
		virtual void Render() const;

		template<typename Comp>
		bool AddComponent();

		template<typename Comp>
		bool RemoveComponent();

		template<typename Comp>
		Comp* GetComponent();



		//void SetTexture(const std::string& filename);
		//void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		//Transform m_transform{};
		//std::vector<GraphicalComponent*> m_GraphicalComponent;
		//std::vector<UpdatingComponent*> m_UpdatingComponent;
		//std::vector<InputComponent*> m_InputComponent;

		std::vector<Component*> m_ComponentPtr;

		//std::unordered_map<std::string, Component*> m_Components;

		// todo: mmm, every gameobject has a texture? Is that correct?
		// std::shared_ptr<Texture2D> m_texture{};
	};


}