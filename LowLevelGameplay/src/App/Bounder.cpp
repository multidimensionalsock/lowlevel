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
	CircleCollider* collider =  AddComponent<CircleCollider>();
	collider->moveable = false;
	collider->position = this->transform.position;
	collider->radius = tex.RectTexSize.y / tex.spritesInTexture.y / 2;
	collider->type = Circle;

}
