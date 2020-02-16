#include "Inventory.h"

void Inventory::render(){
	View view;
	view.setViewport(FloatRect(0, 0, 1, 1.7));
	MainWindow::getMainWindow()->getWindow()->setView(view);
	for (int i = 0; i < items.size(); i++){
		items[i]->setPosition(Vector2f((i + 1) * 20, WYS - 50));
		items[i]->render();
	}
}

void Inventory::addItem(Object &obj){
	items.push_back(new Object(obj));
}

bool Inventory::gotKey(string keyName){
	for (int i = 0; i < items.size(); i++){
		if (items[i]->getName() == keyName){
			items.erase(items.begin()+ i);
			return true;
		}
	}
	return false;
}