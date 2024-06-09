#pragma once
#include "Components.h"

namespace dae {

	class Enemy : public UpdatingComponent
	{
	public:
		Enemy(GameObject gameObject);

		void Update(double elapsed) override;



		~Enemy();
		Enemy(const Enemy& other) = delete;
		Enemy(Enemy&& other) = delete;
		Enemy& operator=(const Enemy& other) = delete;
		Enemy& operator=(Enemy&& other) = delete;
	};


}