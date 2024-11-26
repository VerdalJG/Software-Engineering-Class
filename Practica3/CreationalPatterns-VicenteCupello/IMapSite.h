#pragma once
#include <iostream>
#include <vector>

class IMapSite // interface
{
public:
	virtual void Enter() = 0;
	virtual void Draw() = 0;
};

