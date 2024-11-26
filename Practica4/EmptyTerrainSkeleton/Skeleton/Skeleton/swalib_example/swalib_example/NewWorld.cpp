#include "NewWorld.h"
#include "Terrain.h"
#include "TerrainFlyweight.h"
#include "TerrainFlyweightManager.h"

NewWorld* NewWorld::m_NewWorldInstance = nullptr; // Requires definition here because it is a static member variable

NewWorld* NewWorld::Get()
{
	if (m_NewWorldInstance == nullptr)
	{
		m_NewWorldInstance = new NewWorld();
        m_NewWorldInstance->flyweightManager = new TerrainFlyweightManager();
	}
	return m_NewWorldInstance;
}

void NewWorld::GenerateTerrain()
{
    terrainGrid.clear();

    textureIDs.push_back(CORE_LoadPNG("data/Acid.png", true));
    textureIDs.push_back(CORE_LoadPNG("data/circle-bkg-128.png", true));
    textureIDs.push_back(CORE_LoadPNG("data/Water.png", true));

    navigationCosts.push_back(10.0f);
    navigationCosts.push_back(1.0f);
    navigationCosts.push_back(5.0f);

    for (int i = 0; i < WORLD_HEIGHT; ++i) 
    {
        std::vector<Terrain*> row;
        for (int j = 0; j < WORLD_WIDTH; ++j) 
        {
            GLuint randomTextureID = textureIDs[rand() % textureIDs.size()];
            float randomNavigationCost = navigationCosts[rand() % navigationCosts.size()];

            // Use the factory to get or create a flyweight
            TerrainFlyweight* sharedInstance = flyweightManager->GetFlyweight(randomTextureID, randomNavigationCost);

            // Create the Terrain object with the shared flyweight
            vec2 position = vec2(i * TILE_WIDTH + TILE_WIDTH / 2, j * TILE_HEIGHT + TILE_HEIGHT / 2);
            Terrain* terrain = new Terrain(sharedInstance, position);
            row.push_back(terrain);
        }
        terrainGrid.push_back(row);
    }
}

void NewWorld::DestroyTerrain()
{
    delete flyweightManager;

    for (GLuint textureID : textureIDs)
    {
        CORE_UnloadPNG(textureID);
    }
    textureIDs.clear();
    navigationCosts.clear();
}

NewWorld::NewWorld()
{
}

void InitNewGlobalData()
{
	NewWorld::Get()->GenerateTerrain();
}

void ShutDownNewGlobalData()
{
	NewWorld::Get()->DestroyTerrain();
}
