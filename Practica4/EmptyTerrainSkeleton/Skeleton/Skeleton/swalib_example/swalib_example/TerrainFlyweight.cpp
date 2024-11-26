#include "TerrainFlyweight.h"

TerrainFlyweight::TerrainFlyweight(GLuint textureID, float navigationCost) :
	textureID(textureID),
	navigationCost(navigationCost)
{
}

TerrainFlyweight::~TerrainFlyweight()
{

}
