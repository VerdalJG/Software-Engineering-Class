#pragma once
#include "../Code/Game/global.h"
#include "TerrainFlyweight.h"

class Terrain
{
public:
	Terrain(GLuint textureID, float navigationCost, vec2 position);
	Terrain(TerrainFlyweight* sharedTerrainInstance, vec2 position);

private:
	//GLuint textureID;
	//float navigationCost;
	TerrainFlyweight* sharedTerrainInstance;
	vec2 position;

public:
	GLuint GetTextureID() { return sharedTerrainInstance->GetTextureID(); }
	float GetNavigationCost() { return sharedTerrainInstance->GetNavigationCost(); }
	vec2 GetPosition() { return position; }
};

