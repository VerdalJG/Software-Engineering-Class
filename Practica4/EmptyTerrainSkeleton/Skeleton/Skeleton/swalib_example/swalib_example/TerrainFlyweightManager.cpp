#include "TerrainFlyweightManager.h"
#include "TerrainFlyweight.h"

TerrainFlyweight* TerrainFlyweightManager::GetFlyweight(GLuint textureID, float navigationCost)
{
    // Use a key based on textureID and navigationCost
    std::string key = std::to_string(textureID) + "_" + std::to_string(navigationCost);

    // If this configuration doesn't exist, create and store it
    if (sharedTerrainInstances.find(key) == sharedTerrainInstances.end()) 
    {
        sharedTerrainInstances[key] = new TerrainFlyweight(textureID, navigationCost);
    }
    return sharedTerrainInstances[key];
}

// Clean up memory
TerrainFlyweightManager::~TerrainFlyweightManager()
{
    for (std::pair<const std::string, TerrainFlyweight*>& pair : sharedTerrainInstances)
    {
        delete pair.second;
    }
}
