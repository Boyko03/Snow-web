#include "Map.h"
#include "TileFactory.h"
#include "surface.h"

using namespace Tmpl8;

Map::Map(int rows, int colls, Difficulty difficulty, Surface& screen) :
	rows(rows), colls(colls), difficulty(difficulty), screen(screen)
{
	width = colls + 2 * border_width;
	map.assign(rows * width, tileFactory.getTile(Tile::Terrains_t::Snow, Tile::Objects_t::None));
}

Map::~Map()
{
	delete player;

	for (size_t i = 0; i < map.size(); i++)
		map.pop_back();
	map.erase(map.begin());
}

void Map::DrawBackground()
{
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < colls + 2 * border_width; c++) {
			int x = screen.GetWidth() / 2 - (colls / 2 - c + border_width) * TILE;
			map[((first_row + r) % rows * width) + c].DrawBackground(x, (int)(r * TILE - current_position), screen);
		}
	}
}

void Map::DrawForeground()
{
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < colls + 2 * border_width; c++) {
			int x = screen.GetWidth() / 2 - (colls / 2 - c + border_width) * TILE;
			map[((first_row + r) % rows * width) + c].DrawForegound(x, (int)(r * TILE - current_position), screen);
		}
	}
}

void Map::DrawHearts()
{
	Sprite heart = Sprite(new Surface("assets/heart.png"), 1);
	for (int i = 0; i < player->health; i++) {
		heart.Draw(&screen, heart.GetWidth() * i + 16, 16);
	}
}

void Map::AddBorder()
{
	Tile* row = &map[first_row * width];
	// Left border
	for (int i = 0; i < border_width; i++) {
		int r = rand() % 4;
		if (r == 0) row[i] = tileFactory.getTile(Tile::Terrains_t::Snow, Tile::Objects_t::None);
		else row[i] = tileFactory.getTile(Tile::Terrains_t::Snow, Tile::Objects_t(r + 11)); // 12, 13, 14
	}

	// Right border
	for (int i = 0; i < border_width; i++) {
		int r = rand() % 4;
		if (r == 0) row[border_width + colls + i] = tileFactory.getTile(Tile::Terrains_t::Snow, Tile::Objects_t::None);
		else row[border_width + colls + i] = tileFactory.getTile(Tile::Terrains_t::Snow, Tile::Objects_t(r + 11)); // 12, 13, 14
	}
}

void Map::ReduceCurrentPosition() {
	while (current_position >= TILE) {
		current_position -= TILE;
	}
}