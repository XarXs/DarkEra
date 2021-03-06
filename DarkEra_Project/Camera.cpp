#include "Camera.h"
//========= Konstruktor
Camera::Camera(){
	view.setSize(900.f, 550.f);
	offset = Vector2i(100, 50);
	center = view.getCenter();
	border = Vector2i(view.getSize().x - center.x + 50, view.getSize().y - center.y + 225);
}

//========= Settery
void Camera::setView(View view){
	MainWindow::getMainWindow()->getWindow()->setView(view);
}

void Camera::setOffset(Vector2i offset){
	this->offset = offset;
}

void Camera::setBorder(Vector2i border){
	this->border = border;
}

void Camera::setCenter(Vector2f center){
	this->center = center;
}

//========= Gettery
View Camera::getView(){
	return view;
}

Vector2i Camera::getOffset(){
	return offset;
}

Vector2i Camera::getBorder(){
	return border;
}

Vector2f Camera::getCenter(){
	return center;
}

//======== Metody
void Camera::update(Vector2f position, Vector2i mapSize){

	Vector2f delta(0, 0);
	if (position.x >= (center.x + offset.x)){
		delta = Vector2f(position.x - (center.x + offset.x), center.y);
		center = Vector2f(center.x + delta.x, center.y);
	}
	if (position.x <= (center.x - offset.x)){
		delta = Vector2f(position.x - (center.x - offset.x), center.y);
		center = Vector2f(center.x + delta.x, center.y);
	}

	if (position.y >= (center.y + offset.y)){
		delta = Vector2f(center.x, position.y - (center.y + offset.y));
		center = Vector2f(center.x, center.y + delta.y);
	}
	if (position.y <= (center.y - offset.y)){
		delta = Vector2f(center.x, position.y - (center.y - offset.y));
		center = Vector2f(center.x, center.y + delta.y);
	}

	// ============= czy kamera wychodzi poza planszę
	cornerLUp = Vector2f(center.x - border.x, center.y - border.y);
	cornerRDown = Vector2f(center.x + border.x, center.y + border.y);
	
	if (cornerLUp.x <= 0 || cornerLUp.y <= 0){
		delta.x = 0 - cornerLUp.x;
		delta.y = 0 - cornerLUp.y;

		if (delta.x >= 0){
			center.x = center.x + delta.x;
		}
		if (delta.y >= 0){
			center.y = center.y + delta.y;
		}
	}

	if (cornerRDown.x >= mapSize.x * TEXSIZE || cornerRDown.y >= mapSize.y * TEXSIZE){
		delta.x = mapSize.x * TEXSIZE - cornerRDown.x;
		delta.y = mapSize.y * TEXSIZE - cornerRDown.y;

		if (delta.x <= 0){
			center.x = center.x + delta.x;
		}
		if (delta.y <= 0){
			center.y = center.y + delta.y;
		}
	}

	view.setCenter(center);
	MainWindow::getMainWindow()->getWindow()->setView(view);

}