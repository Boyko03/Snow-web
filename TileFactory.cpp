#include "TileFactory.h"
#include "Tile.h"
#include "BoxCollider.h"

using namespace Tmpl8;

Tile TileFactory::getTile(Tile::Terrains_t terrain, Tile::Objects_t object)
{
	// Tile(int ox, int oy, int cx, int cy, int dx, int dy, Objects_t object,
	//		Terrains_t terrain, int tile_width=TILE, int tile_height=TILE);
	switch (object)
	{
	// Objects
	case Tile::Objects_t::None:
		return Tile(0, 0, BoxCollider(vec2(-1, -1), vec2(-1, -1)), object, terrain);
	case Tile::Objects_t::Tree:
		return Tile(0, 1, BoxCollider(vec2(11, 18), vec2(20, 26)), object, terrain);
	case Tile::Objects_t::Rock:
		return Tile(2, 1, BoxCollider(vec2(5, 16), vec2(26, 29)), object, terrain);
	case Tile::Objects_t::Bush:
		return Tile(1, 1, BoxCollider(vec2(6, 16), vec2(27, 29)), object, terrain);
	case Tile::Objects_t::Log:
		return Tile(3, 0, BoxCollider(vec2(3, 14), vec2(30, 24)), object, terrain);
	// Not used yet
	case Tile::Objects_t::Sign:
		return Tile(2, 0, BoxCollider(vec2(15, 24), vec2(17, 26)), object, terrain);
	// Not randomly generated. Used for correct drawing of trees
	case Tile::Objects_t::TwoTrees:
		return Tile(1, 0, BoxCollider(vec2(11, 18), vec2(20, 26)), object, terrain);
	case Tile::Objects_t::TopOfTree:
		return Tile(0, 0, BoxCollider(vec2(-1, -1), vec2(-1, -1)), object, terrain);
	// Powerups
	case Tile::Objects_t::Heart:
		return Tile(5, 2, BoxCollider(vec2(2, 2), vec2(30, 30)), object, terrain);
	case Tile::Objects_t::Shield:
		return Tile(6, 2, BoxCollider(vec2(2, 0), vec2(30, 32)), object, terrain);
	// Flags
	case Tile::Objects_t::BlueFlag:
		return Tile(6, 0, BoxCollider(vec2(6, 43), vec2(26, 52)), object, terrain, TILE, 2 * TILE);
	case Tile::Objects_t::RedFlag:
		return Tile(8, 0, BoxCollider(vec2(6, 43), vec2(26, 52)), object, terrain, TILE, 2 * TILE);
	// Border trees
	case Tile::Objects_t::Pine1:
		return Tile(10, 0, BoxCollider(vec2(-1, -1), vec2(-1, -1)), object, terrain, TILE, 2 * TILE);
	case Tile::Objects_t::Pine2:
		return Tile(11, 0, BoxCollider(vec2(-1, -1), vec2(-1, -1)), object, terrain, 38, 2 * TILE);
	case Tile::Objects_t::WinterTree:
		return Tile(13, 0, BoxCollider(vec2(-1, -1), vec2(-1, -1)), object, terrain, 42, 2 * TILE);
	default:
		// Undefined
		return Tile(0, 0, BoxCollider(vec2(-1, -1), vec2(-1, -1)), object, terrain);
	}
}
