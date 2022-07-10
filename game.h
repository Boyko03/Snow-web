#pragma once

#include "Player.h"

#include <vector>

namespace Tmpl8 {

class Surface;
class Game
{
public:
	bool fullscreen = false;

	enum class STATE {
		MAIN_SCREEN,
		LEVEL_MODE,
		LEVEL_DIFFICULTY,
		GAME,
		END_GAME
	};

private:
	Player* player;
	Surface* screen;

	int mx;	// mouse x
	int my;	// mouse y

	bool SELECT = false;	// is menu item selected with enter/space
	bool PAUSE = false;		// is game paused

	// STATE: END_GAME	-	for correct "press any key to continue"
	int gameOverKey = -1, counter = 0;
	bool isGameOver = true, gameOverKeyUp = false;

	char name[32] = "";		// Player name
	int name_index = 0;		// cursor position

	STATE state = STATE::MAIN_SCREEN;

	enum class Mode {
		Normal,
		OffRoad
	} mode;

	struct ScoreStat {
		char name[10];
		int score;
	};

	struct TimeStat {
		char name[10];
		float score;
	};

	bool isMouseDown = false;
	bool btnSelect = false;
	int selectorIndex = 0;

	bool areStatsWritten = false;
	bool makeCopy = true;

public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp(int button);
	void MouseDown( int button );
	void MouseMove(int x, int y);
	void KeyUp(int key);
	void KeyDown(int key);
	void ScreenShot();
	void Reset();

	STATE GetState() { return state; }

private:
	/// <summary>
	/// Handle user input in main screen
	/// </summary>
	void MainScreenHandler();
	/// <summary>
	/// Handle user input in level mode selection screen
	/// </summary>
	void LevelModeHandler();
	/// <summary>
	/// Handle user input in level difficulty selection screen
	/// </summary>
	void LevelDifficultyHandler();
	/// <summary>
	/// Handle user input in pause screen
	/// </summary>
	void PauseBtnsHandler();
	/// <summary>
	/// Handle user input in endgame state
	/// </summary>
	void EndgameHandler();
	/// <summary>
	/// Check if back button is clicked
	/// </summary>
	/// <returns>true if button is clicked</returns>
	bool IsBackClicked();

	/// <summary>
	/// Handle user input with arrow keys / WASD
	/// </summary>
	/// <param name="key">Key code</param>
	void ArrowKeyUpHandler(int key);

	/// <summary>
	/// Draw home screen
	/// </summary>
	void DrawHomeScreen();
	/// <summary>
	/// Draw mode selection screen
	/// </summary>
	void DrawModeSelectScreen();
	/// <summary>
	/// Draw difficulty selection screen
	/// </summary>
	void DrawDifficultySelectScreen();

	/// <summary>
	/// Draw pause screen
	/// </summary>
	void DrawPauseScreen();

	// Prints score during endgame state
	void PrintScore();

	/// <summary>
	/// Write score to file
	/// </summary>
	/// <returns>vector of top 10 stats</returns>
	std::vector<ScoreStat> WriteStatsScore();
	/// <summary>
	/// Writes time to file
	/// </summary>
	/// <returns>vector of top 10 stats</returns>
	std::vector<TimeStat> WriteStatsTime();

	/// <summary>
	/// Add key to player name (if key is valid)
	/// </summary>
	/// <param name="key">Key code</param>
	void EnterName(int key);
	/// <summary>
	/// Convert key code to char
	/// </summary>
	/// <param name="key">Key code</param>
	/// <returns>char from key code</returns>
	char GetCharByKey(int key);

	/// <summary>
	/// Prints FPS at top left corner
	/// </summary>
	/// <param name="deltaTime">Elapsed time from previous frame</param>
	void PrintFPS(float deltaTime);
};

}; // namespace Tmpl8