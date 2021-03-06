#pragma once
#include "Biblioteki.h"

class Camera{
private:
	View view;				//widok kamery
	Vector2f center;		//poprzednie współrzędne środka ekranu
	Vector2i offset;		//wewnętrzny obszar kamery, w którym można poruszać się swobodnie
	Vector2i border;		//obszard do którego ma być przemieszczana kamera;
							//ma zapobiec wychodzenia kamerą poza obszar planszy.
	Vector2f cornerLUp;		//lewy górny róg kamery
	Vector2f cornerRDown;	//prawy dowlny róg kamery
public:
	void setView(View view);
	View getView();
	void setOffset(Vector2i offset);
	Vector2i getOffset();
	void setBorder(Vector2i border);
	Vector2i getBorder();
	void setCenter(Vector2f center);
	Vector2f getCenter();

	void update(Vector2f position, Vector2i mapSize);		//aktualizacja kamery
	Camera();
};