#include "Core/Player.h"
#include "Core/Renderer.h"
#include "Core/RigidBody2D.h"
#include "Core/PlayerMovement.h"
#include "core/ColliderTypes.h"

void LLGP::Player::Start()
{
	//initialize and add components here 
	SetTag("Player");
	SetName("PlayerGameObject");

	//renderer
	Renderer* ren = AddComponent<Renderer>();
	ren->SetTexture(sceneManager->textureLoad.player1Bird);

	//rigidbody
	RigidBody2D* rb = AddComponent<LLGP::RigidBody2D>();
	rb->SetMass(1.f);
	rb->SetTransform(&transform);

	//player movement 
	AddComponent<PlayerMovement>();

	//collider
	AABBCollider* collider = AddComponent<AABBCollider>();
	collider->position = transform.position;
	collider->moveable = true;
	collider->width = 40;
	collider->height = 40;
	sceneManager->AddCollider(collider);

	

}
