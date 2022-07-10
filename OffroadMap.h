#pragma once
#include "Map.h"

class OffroadMap : public virtual Map
{
public:
	OffroadMap(int rows, int colls, Difficulty difficulty, Surface& screen);

	void AddRow(bool empty = false) override;

	void Move(float deltaTime) override;
	void Draw() override;

private:
	/// <summary>
	/// Generates random tile based on its position in map
	/// </summary>
	/// <param name="column">- column in row</param>
	/// <returns>Random tile</returns>
	Tile GenerateTile(int column);
	/// <summary>
	/// Generates random object
	/// </summary>
	Tile::Objects_t GetRandomObject();
	/// <summary>
	/// Generate random powerup
	/// </summary>
	int GetRandomPowerup();

	/// <summary>
	/// Check if player collides with object
	/// </summary>
	/// <param name="x">- player X</param>
	/// <param name="y">- player Y</param>
	/// <returns>false if player hits an obstacle</returns>
	bool CheckPos(int x, int y);

	/// <summary>
	/// Draw player
	/// </summary>
	void DrawPlayer();
	/// <summary>
	/// Print score on scoreboard
	/// </summary>
	void PrintScore();
	/// <summary>
	/// Print shield timer
	/// </summary>
	void PrintShieldTimer();

	/// <summary>
	/// Check if player hits a powerup and collect it
	/// </summary>
	/// <returns>true if tile has a powerup else false</returns>
	bool CheckForPowerups(Tile* tile);
};
