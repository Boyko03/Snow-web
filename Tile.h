#pragma once

#include <utility>
#include <map>
#include "surface.h"
#include "BoxCollider.h"

constexpr int TILE = 32;

class Tile
{
public:
	/// <summary>
	/// Terrain types
	/// </summary>
	enum class Terrains_t {
		Snow,
		FinishLine,
		Ice,
		Gravel,
		CobbleStone
	};

	/// <summary>
	/// Object types
	/// </summary>
	enum class Objects_t {
		None,
		Tree,
		Rock,
		Log,
		Bush,
		Sign,	// Not used yet

		// Not Randomly Generated
		TopOfTree,
		TwoTrees,

		// (Powerup) Offroad map only
		Heart,
		Shield,

		// Normal map only
		BlueFlag,
		RedFlag,

		// Border trees
		Pine1,
		Pine2,
		WinterTree
	};

	/// <summary>
	/// Use tile factory. (Uses terrain and object)
	/// </summary>
	/// <param name="ox">- Object X from tilemap</param>
	/// <param name="oy">- Object Y from tilemap</param>
	/// <param name="cx">- Collision center X</param>
	/// <param name="cy">- Collision bottom Y</param>
	/// <param name="dx">- Collision delta X</param>
	/// <param name="dy">- Collision delta Y</param>
	/// <param name="object">- Object</param>
	/// <param name="terrain">- Terrain</param>
	/// <param name="tile_width">- tile width, default: TILE</param>
	/// <param name="tile_height">- tile height, default: TILE</param>
	Tile(int ox, int oy, BoxCollider collider, Objects_t object, Terrains_t terrain, int tile_width=TILE, int tile_height=TILE);

	int ox, oy;			// x, y in tileset
	BoxCollider collider;

	static std::map<Terrains_t, std::pair<int, int>> terrains;

	Terrains_t terrain;
	Objects_t object;

private:
	static Tmpl8::Surface tiles;	// tilemap
	static int t_width;				// tilemap width
	int tile_width, tile_height;	// Can be different from TILE

public:
	// Draw background only
	void DrawBackground(int x, int y, Tmpl8::Surface& screen);
	// Draw foreground only
	void DrawForegound(int x, int y, Tmpl8::Surface& screen);
	// Draw object only
	void DrawObjectOnly(int x, int y, Tmpl8::Surface& screen);

private:
	/// <summary>
	/// Draw tile on screen
	/// </summary>
	/// <param name="tx">- tilemap X</param>
	/// <param name="ty">- tilemap Y</param>
	/// <param name="screen">- surface to draw tile on to</param>
	/// <param name="x">- screen X</param>
	/// <param name="y">- screen Y</param>
	/// <param name="is_object">- if tile is object uses tile_width and tile_height else default TILE size</param>
	void DrawTile(int tx, int ty, Tmpl8::Surface& screen, int x, int y, bool is_object=false);
};

