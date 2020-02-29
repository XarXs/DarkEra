#pragma once

class Piece
{
protected:
	int id;
	Vector2i size;
	Vector2i position;
	Piece *parent;
	int maxExist;
	string tag;
public:
	Piece();
	~Piece();
};

