#include "Inventory.h"

void Inventory::render(){
	for (int i = 0; i < items.size(); i++){
		//items[i].render();
	}
}

void Inventory::addItem(Object &obj){
	items.push_back(new Object(obj));
}