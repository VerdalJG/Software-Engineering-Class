#pragma once
#include "IMapSite.h"


enum EDirection
{
	North,
	South,
	East,
	West
};

class Room : public IMapSite
{
public:
	Room(unsigned int roomID);
	virtual void Enter() override;
	virtual void Draw() override { printf(" "); }

private:
	unsigned int roomID;
	std::vector<IMapSite*> neighbors; // Can only have neighbors in cardinal directions

public:
	IMapSite* GetAdjacentNeighbor(EDirection direction) const { return neighbors[direction]; }
	void SetAdjacentNeighbor(IMapSite* newNeighbor, EDirection direction) { neighbors[direction] = newNeighbor; }

	std::vector<IMapSite*> GetNeighbors() { return neighbors; }

	unsigned int GetRoomID() const { return roomID; }
};

