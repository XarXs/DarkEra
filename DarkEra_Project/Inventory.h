#pragma once
#include "Biblioteki.h"

class Inventory{
	friend class Object;
private:
	vector<Object*> items;
public:
	void render();
	void addItem(Object &obj);
	bool gotKey(string keyName);
};