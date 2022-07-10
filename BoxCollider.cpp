#include "BoxCollider.h"

bool BoxCollider::Collides(BoxCollider& other)
{
	return min.x < other.max.x && max.x > other.min.x &&
		min.y < other.max.y && max.y > other.min.y;
}
