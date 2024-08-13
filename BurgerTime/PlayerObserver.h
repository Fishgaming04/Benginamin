#pragma once
#include "GameObject.h"
#include "Observers.h"
#include "Components.h"
namespace dae
{

	class PlayerObserver final : public ObserverComponent
	{
	public:
		PlayerObserver(GameObject* obj);

		virtual ~PlayerObserver() {};

		virtual void OnNotify(Event event, Subject*, const std::any& args) override;

		PlayerObserver(const PlayerObserver& other) = delete;
		PlayerObserver(PlayerObserver&& other) = delete;
		PlayerObserver& operator=(const PlayerObserver& other) = delete;
		PlayerObserver& operator=(PlayerObserver&& other) = delete;
	private:
	};

}

