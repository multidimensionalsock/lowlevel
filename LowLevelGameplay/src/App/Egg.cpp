#include "Core/Egg.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"
#include "Core/EggLogic.h"
#include "Core/RigidBody2D.h"

LLGP::Egg::~Egg()
{
	std::cout << "egg destored";
}

void LLGP::Egg::Start()
{
	//add egg logic omponent
	EggLogic* logic = AddComponent<EggLogic>();

	//add collider 
	AABBCollider* collider = AddComponent<AABBCollider>();
	collider->type = AABB;
	collider->width = 22;
	collider->height = 22;
	sceneManager->AddCollider(collider);

	//add renderer
	TextureDetails tex = sceneManager->textureLoad.egg;
	Renderer* _renderer = AddComponent<Renderer>();
	_renderer->SetTexture(tex);

	

	//add rigidbody
	RigidBody2D* rb = AddComponent<RigidBody2D>();
	rb->SetMass(1.f);
	rb->SetTransform(&transform);

	
}

