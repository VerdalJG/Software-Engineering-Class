#pragma once
#include "IMapSite.h"

class Wall : public IMapSite
{
public:
	virtual void Enter() override;
	virtual void Draw() override { printf("X"); }
};

