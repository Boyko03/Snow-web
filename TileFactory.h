#pragma once
#include "Tile.h"

class TileFactory
{
public:
	// Creates tile from terrain and object
	Tile getTile(Tile::Terrains_t terrain, Tile::Objects_t object);
};

