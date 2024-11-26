#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "../../../common/vector2d.h"
#include "../../../common/sys.h"
#include "../../../common/stdafx.h"
#include "../../../common/core.h"
#include "../../../common/lodepng.h"
#include "../../../common/font.h"

const unsigned int WORLD_WIDTH = 10;
const unsigned int WORLD_HEIGHT = 10;
const float TILE_WIDTH = SCR_WIDTH / WORLD_WIDTH;
const float TILE_HEIGHT = SCR_HEIGHT / WORLD_HEIGHT;

class Terrain;

/** 
*	Class to represent the game playable world
*	It's composed by a matrix of terrains
*/
class World
{
public:
	using TerrainGrid = std::vector<std::vector<Terrain*>>;

	// Singleton accessor
	static World* Get();

	/** Method that generate the terrain randomly*/
	void GenerateTerrain();

	/** Delete terrain tiles and free the terrain textures*/
	void DestroyTerrain();

private:
	World();

private:
	static World* m_WorldInstance;
	TerrainGrid terrainGrid;
	std::vector<GLuint> textureIDs;
	std::vector<float> navigationCosts;

public:
	TerrainGrid& GetTerrainGrid() { return terrainGrid; }
};

// Initialization global data.
void InitGlobalData();
// Shutdown global data.
void ShutDownGlobalData();

#endif // !_GLOBAL_H_
