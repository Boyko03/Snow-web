#pragma once
#include "Map.h"

class NormalMap : public virtual Map
{
public:
	NormalMap(int rows, int colls, Difficulty difficulty, Surface& screen);

	void AddRow(bool empty = false) override;

	void Move(float deltaTime) override;
	void Draw() override;

	bool IsWin() override;

	/// <summary>
	/// Get the total time in mm:ss:ms format
	/// </summary>
	char* GetTotalTime();

	// Get total time in milliseconds
	float GetTotalTimeMs() const { return total_time; }

private:
	// Distance between flags
	int DISTANCE;

	// Flags count * distance between flags
	int flags_counter;

	// Max flags shown per frame
	int max_flags_shown_per_frame;

	// Is finish line drawn
	bool finish_drawn = false;

	// Is a flag missed
	bool missed_flag = false;

	// Total time since game start
	float total_time = 0.0f;

	// Check if player hits object
	bool CheckPos(int x, int y);

	/// <summary>
	/// Check if flag is missed
	/// </summary>
	/// <param name="x">Player X</param>
	/// <param name="y">Player Y</param>
	/// <returns>False if flag is missed else true</returns>
	bool CheckFlag(int x, int y);

	// Draw player
	void DrawPlayer();

	// PrintTime
	void PrintTime();
};
