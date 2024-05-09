#include "Core/Egg.h"
#include "Core/Renderer.h"
#include "Core/ColliderTypes.h"
#include "Core/EggLogic.h"

void LLGP::Egg::Start()
{
	//add renderer
	TextureDetails tex = sceneManager->textureLoad.egg;
	Renderer* _renderer = AddComponent<Renderer>();
	_renderer->SetTexture(tex);

	//add collider 
	AABBCollider* collider = AddComponent<AABBCollider>();
	collider->width = 22;
	collider->height = 22;
	sceneManager->AddCollider(collider);

	//add egg logic omponent
	EggLogic* logic = AddComponent<EggLogic>();
}

