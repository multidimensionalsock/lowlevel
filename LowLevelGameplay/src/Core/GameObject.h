#pragma once
#include "Core/Object.h"
#include "Core/component_concept.h"

class MonoBehaviour;

class GameObject : public Object
{
public:
	GameObject();
	GameObject(std::string name, std::string tag) { m_Name = name; m_Tag = tag; }
	GameObject(const GameObject&) = default;
	//Transform* transform;
	inline void SetName(std::string newName) { m_Name = newName; }
	inline std::string GetName() { return m_Name; }

	void SetActive(bool newActive) { m_Active == newActive; };
	inline bool GetActive() { return m_Active; }

	inline void SetTag(std::string newTag) { m_Tag = newTag; }
	inline bool CompareTag(std::string comp) { return m_Tag == comp;  }

	template<class T> requires isComponent<T> T* GetComponent();
	template<class T> requires isComponent<T> T* AddComponent();
	template<class T> requires isComponent<T> bool RemoveComponent(T* comp);

private: 
	std::string m_Name;
	bool m_Active;
	std::string m_Tag;
	std::vector<std::unique_ptr<MonoBehaviour>> m_Components;

public:
	inline bool operator==(const GameObject& other) { return this->uuid == other.uuid; }
	inline bool operator!=(const GameObject& other) { return !(*this == other); }
};


