#pragma once
#include "Components.h"
#include "glm/glm.hpp"
namespace dae
{

	class ToppingPartCollision final : public ObserverComponent
	{
	public:
		ToppingPartCollision(GameObject* obj);

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;


		void setIsPressed(bool isPressed) { m_IsPressed = isPressed; }
		bool getIsPressed() const { return m_IsPressed; }

		virtual ~ToppingPartCollision() {};
		


		ToppingPartCollision(const ToppingPartCollision& other) = delete;
		ToppingPartCollision(ToppingPartCollision&& other) = delete;
		ToppingPartCollision& operator=(const ToppingPartCollision& other) = delete;
		ToppingPartCollision& operator=(ToppingPartCollision&& other) = delete;
	private:
		bool m_IsPressed;
	};

}
