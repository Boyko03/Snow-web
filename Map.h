#pragma once

#include <vector>
#include "Tile.h"
#include "Player.h"
#include "TileFactory.h"
using namespace std;

class TileFactory;
class Map
{
public:
	enum class Difficulty {
		Easy,
		Medium,
		Hard
	};

protected:
	vector<Tile> map;
	// number of rows in map
	int rows;
	// number of columns in map
	int colls;
	// tree border width
	int border_width = 3;
	// position in current tile: [0 ~ TILE]
	float current_position = 0;
	// index of the first row
	int first_row = 0;
	// count of tiles in a row
	int width;

	// elapsed time since last frame
	float elapsedTime = 0;

	TileFactory tileFactory;
	Player* player;
	Surface& screen;
	Difficulty difficulty;

public:
	Map(int rows, int colls, Difficulty difficulty, Surface& screen);
	virtual ~Map();

	/// <summary>
	/// Replace the first row tiles and increment first row index
	/// </summary>
	/// <param name="empty">- If true fills row with empty tiles</param>
	virtual void AddRow(bool empty = false) = 0;

	/// <summary>
	/// Moves map
	/// </summary>
	/// <param name="deltaTime"></param>
	virtual void Move(float deltaTime) = 0;

	/// <summary>
	/// Draws map
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// Check if game is won in order to end it
	/// </summary>
	/// <returns>true if game is won</returns>
	virtual bool IsWin() { return false; }

	/// <summary>
	/// Returns player
	/// </summary>
	Player* GetPlayer() { return player; }

protected:
	/// <summary>
	/// Draws hearts on screen
	/// </summary>
	void DrawHearts();

	// Adds border of trees to first row
	void AddBorder();

	/// <summary>
	/// Draws map background
	/// </summary>
	void DrawBackground();

	/// <summary>
	/// Draws map foreground
	/// </summary>
	void DrawForeground();

	/// <summary>
	/// Reduces current position if bigger than TILE
	/// </summary>
	void ReduceCurrentPosition();
};

