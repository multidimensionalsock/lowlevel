#include "Core/Bounder.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"

void LLGP::Bounder::Start()
{
	TextureDetails tex = sceneManager->textureLoad.enemyBird;
	transform.position = Vector2<float>(100, 100);

	//needs a renderer
	Renderer* ren = AddComponent<Renderer>();
	ren->SetTexture(tex);

	//needs a collider 
	AABBCollider* collider =  AddComponent<AABBCollider>();
	collider->moveable = true;
	collider->position = this->transform.position;
	collider->width = 40;
	collider->height = 40;
	collider->type = AABB;

}
