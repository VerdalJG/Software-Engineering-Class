#pragma once
#include "IMapSite.h"

class DestructibleWall : public IMapSite
{
public:
	virtual void Enter() override;
	virtual void Draw() { printf("Z"); }
};

