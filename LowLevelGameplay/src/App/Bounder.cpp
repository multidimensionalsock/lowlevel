#include "Core/Bounder.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"
#include "Core/BounderAI.h"

void LLGP::Bounder::Start()
{
	SetTag("Bounder");

	TextureDetails tex = sceneManager->textureLoad.enemyBird;
	transform.position = Vector2<float>(100, 100); //do this so it appears at a random spawn point 

	//needs a renderer
	Renderer* ren = AddComponent<Renderer>();
	ren->SetTexture(tex);

	//needs a collider 
	AABBCollider* collider =  AddComponent<AABBCollider>();
	collider->width = 40;
	collider->height = 40;
	collider->type = AABB;

	BounderAI* AI = AddComponent<BounderAI>();
}
