#include "Terrain.h"
#include "TerrainFlyweight.h"

Terrain::Terrain(GLuint textureID, float navigationCost, vec2 position)
{
	//this->textureID = textureID;
	//this->navigationCost = navigationCost; // Uses flyweight now
	this->position = position;
}

Terrain::Terrain(TerrainFlyweight* sharedTerrainInstance, vec2 position)
{
	this->sharedTerrainInstance = sharedTerrainInstance;
	this->position = position;
}
