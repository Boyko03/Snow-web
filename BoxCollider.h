#pragma once

#include "template.h"

class BoxCollider
{
public:
	Tmpl8::vec2 min, max;
	BoxCollider(Tmpl8::vec2 topLeft, Tmpl8::vec2 bottomRight) : min(topLeft), max(bottomRight) {}
	bool Collides(BoxCollider& other);
private:
};
