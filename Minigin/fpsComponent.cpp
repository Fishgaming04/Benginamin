#include "FPSComponent.h"
#include "GameObject.h"
#include "TextComponent.h"


namespace dae {
	FPSComponent::FPSComponent(GameObject* obj) 
		:UpdatingComponent(obj)
		,m_FPS(0)
	{

	}
	void FPSComponent::Update(double elapsedTime) {
		m_FPS = int(1.0 / elapsedTime);
		m_ObjectPtr->GetComponent<TextComponent>()->SetText(std::to_string(m_FPS));
	}

	int FPSComponent::GetFps() {
		return m_FPS;
	}
}