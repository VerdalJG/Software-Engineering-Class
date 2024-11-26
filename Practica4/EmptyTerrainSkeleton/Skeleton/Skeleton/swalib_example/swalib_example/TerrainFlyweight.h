#pragma once
#include "../Code/Game/global.h"

class TerrainFlyweight
{
public:
    TerrainFlyweight(GLuint textureID, float navigationCost);
    ~TerrainFlyweight();

private:
    GLuint textureID;
    float navigationCost;

public:
    GLuint GetTextureID() const { return textureID; }
    float GetNavigationCost() const { return navigationCost; }
};

