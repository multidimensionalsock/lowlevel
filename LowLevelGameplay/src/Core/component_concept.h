#pragma once
#include <concepts>
#include "Core\MonoBehaviour.h"

template<class T>
concept isComponent = std::derived_from<T, LLGP::MonoBehaviour> == true;
