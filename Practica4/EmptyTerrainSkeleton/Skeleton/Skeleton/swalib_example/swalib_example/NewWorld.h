#pragma once
#include "../Code/Game/global.h"

class Terrain;
class TerrainFlyweightManager;

class NewWorld
{
public:
	using NewTerrainGrid = std::vector<std::vector<Terrain*>>;

	// Singleton accessor
	static NewWorld* Get();

	/** Method that generate the terrain randomly*/
	void GenerateTerrain();

	/** Delete terrain tiles and free the terrain textures*/
	void DestroyTerrain();

private:
	NewWorld();

private:
	static NewWorld* m_NewWorldInstance;
	NewTerrainGrid terrainGrid;
	std::vector<GLuint> textureIDs;
	std::vector<float> navigationCosts;
	TerrainFlyweightManager* flyweightManager;

public:
	NewTerrainGrid& GetTerrainGrid() { return terrainGrid; }
};

// Initialization global data.
void InitNewGlobalData();
// Shutdown global data.
void ShutDownNewGlobalData();

