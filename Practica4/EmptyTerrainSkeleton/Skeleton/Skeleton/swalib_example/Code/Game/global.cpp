#include "global.h"
#include <stdlib.h>
#include "../../swalib_example/Terrain.h"
#include "../../swalib_example/NewWorld.h"

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void InitGlobalData()
{
	World::Get()->GenerateTerrain();
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void ShutDownGlobalData()
{
    World::Get()->DestroyTerrain();
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

World* World::m_WorldInstance = nullptr;

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

World* World::Get()
{
	if (m_WorldInstance == nullptr)
	{
		m_WorldInstance = new World;
	}
	return m_WorldInstance;
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void World::GenerateTerrain()
{
	terrainGrid.clear();

	textureIDs.push_back(CORE_LoadPNG("data/Acid.png", true));
	textureIDs.push_back(CORE_LoadPNG("data/circle-bkg-128.png", true));
	textureIDs.push_back(CORE_LoadPNG("data/Water.png", true));

	navigationCosts.push_back(10.0f);
	navigationCosts.push_back(1.0f);
	navigationCosts.push_back(5.0f);

	for (int i = 0; i < WORLD_HEIGHT; i++)
	{
		std::vector<Terrain*> row;
		for (int j = 0; j < WORLD_WIDTH; j++) 
		{
			GLuint randomTextureID = textureIDs[rand() % 3];
			float navigationCost = navigationCosts[rand() % 3];
			float xPosition = i * TILE_WIDTH + TILE_WIDTH / 2;
			float yPosition = j * TILE_HEIGHT + TILE_HEIGHT / 2;
			Terrain* terrain = new Terrain(randomTextureID, navigationCost, vec2(xPosition, yPosition));
			row.push_back(terrain);
		}
		terrainGrid.push_back(row);
	}
	navigationCosts.push_back(5.0f);
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void World::DestroyTerrain()
{
	for (int i = 0; i < WORLD_HEIGHT; i++)
	{
		for (int j = 0; j < WORLD_WIDTH; j++)
		{
			if (terrainGrid[i][j])
			{
				delete terrainGrid[i][j];
			}
		}
	}
	terrainGrid.clear();

	for (GLuint textureID : textureIDs)
	{
		CORE_UnloadPNG(textureID);
	}
	textureIDs.clear();
	navigationCosts.clear();
}

World::World()
{
}
