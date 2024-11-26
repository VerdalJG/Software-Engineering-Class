#include "render.h"
#include "../../../common/stdafx.h"
#include "../../../common/sys.h"
#include "../../../common/core.h"
#include "../../../common/font.h"
#include "../../../common/vector2d.h"
#include "global.h"
#include "../../swalib_example/Terrain.h"
#include "../../swalib_example/NewWorld.h"

void InitRender()
{
	FONT_Init();	// Characters and symbols inicialization to draw on screen.

	// Set up rendering
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping.
	glClearColor(0.0f, 0.1f, 0.3f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.
}

void RenderSlot()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	// Render tiles
	//World* worldRef = World::Get();
	//World::TerrainGrid& grid = worldRef->GetTerrainGrid();
	NewWorld* newWorldRef = NewWorld::Get();
	NewWorld::NewTerrainGrid& grid = newWorldRef->GetTerrainGrid();

    for (int i = 0; i < WORLD_HEIGHT; i++)
    {
		for (int j = 0; j < WORLD_WIDTH; j++)
		{
			// HERE RENDER EACH TILE
			vec2 position = grid[i][j]->GetPosition();
			vec2 size = vec2(TILE_WIDTH, TILE_HEIGHT);
			GLuint textureID = grid[i][j]->GetTextureID();

			CORE_RenderCenteredSprite(position, size, textureID);
 		}
	}

	// Exchanges the front and back buffers.
	SYS_Show();
}

void ShutDownRender()
{
	// Fonts shutdown.
	FONT_End();
}