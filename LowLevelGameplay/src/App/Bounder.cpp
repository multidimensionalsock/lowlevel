#include "Core/Bounder.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"
#include "Core/BounderAI.h"
#include <cstdlib>
#include "Core/RigidBody2D.h"

void LLGP::Bounder::Start()
{
	SetTag("Bounder");

	TextureDetails tex = sceneManager->textureLoad.enemyBird;

	//spawner positions
	Vector2<float> positions[4] = 
	{ 
		Vector2<float>(250.f  ,146.f - tex.RectTexSize.y / 2),
		Vector2<float>(52.f ,262.f - tex.RectTexSize.y / 2),
		Vector2<float>(510.f ,240.f - tex.RectTexSize.y / 2),
		Vector2<float>(282.f ,407.f - tex.RectTexSize.y / 2)
	};
	Vector2<float> pos = positions[std::rand() % 4];

	transform.position = pos; //do this so it appears at a random spawn point 

	//needs a renderer
	Renderer* ren = AddComponent<Renderer>();
	ren->SetTexture(tex);

	//needs a collider 
	AABBCollider* collider =  AddComponent<AABBCollider>();
	collider->width = 40;
	collider->height = 40;
	collider->type = AABB;
	sceneManager->AddCollider(collider);

	BounderAI* AI = AddComponent<BounderAI>();
}
