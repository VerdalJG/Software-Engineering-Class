#pragma once
#include "../Code/Game/global.h"
#include <unordered_map>

class TerrainFlyweight;

class TerrainFlyweightManager
{
public:
    ~TerrainFlyweightManager();

    TerrainFlyweight* GetFlyweight(GLuint textureID, float navigationCost);

private:
    std::unordered_map<std::string, TerrainFlyweight*> sharedTerrainInstances;
};

