#include <SFML/Graphics.hpp>
#include "Utils3D.h"
#include <iostream>
#include "vrpn_Tracker.h"

using namespace std;

Squelette3D currentSqlt3DTrk0;
Squelette3D prviousSqlt3DTrk0;

int currentsqltTracked = 0;
int previousIndexJoint = -1;

int insertJoindInSqletton(vrpn_TRACKERCB b) {

	switch (b.sensor) {
	case (0): currentSqlt3DTrk0.SpineBase = copyTrkToJoint(b, currentSqlt3DTrk0.SpineBase); break;
	case (1): currentSqlt3DTrk0.SpineMid = copyTrkToJoint(b, currentSqlt3DTrk0.SpineMid); break;
	case (2): currentSqlt3DTrk0.Neck = copyTrkToJoint(b, currentSqlt3DTrk0.Neck); break;
	case (3): currentSqlt3DTrk0.Head = copyTrkToJoint(b, currentSqlt3DTrk0.Head); break;
	case (4): currentSqlt3DTrk0.ShoulderLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ShoulderLeft); break;
	case (5): currentSqlt3DTrk0.ElbowLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ElbowLeft); break;
	case (6): currentSqlt3DTrk0.WristLeft = copyTrkToJoint(b, currentSqlt3DTrk0.WristLeft); break;
	case (7): currentSqlt3DTrk0.HandLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HandLeft); break;// cout <<"HandLeft:  "<<b.pos[1]<<endl;
	case (8): currentSqlt3DTrk0.ShoulderRight = copyTrkToJoint(b, currentSqlt3DTrk0.ShoulderRight); break;
	case (9): currentSqlt3DTrk0.ElbowRight = copyTrkToJoint(b, currentSqlt3DTrk0.ElbowRight); break;
	case (10): currentSqlt3DTrk0.WristRight = copyTrkToJoint(b, currentSqlt3DTrk0.WristRight); break;
	case (11): currentSqlt3DTrk0.HandRight = copyTrkToJoint(b, currentSqlt3DTrk0.HandRight); break;
	case (12): currentSqlt3DTrk0.HipLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HipLeft); break;
	case (13): currentSqlt3DTrk0.KneeLeft = copyTrkToJoint(b, currentSqlt3DTrk0.KneeLeft); break;
	case (14): currentSqlt3DTrk0.AnkleLeft = copyTrkToJoint(b, currentSqlt3DTrk0.AnkleLeft); break;
	case (15): currentSqlt3DTrk0.FootLeft = copyTrkToJoint(b, currentSqlt3DTrk0.FootLeft); break;
	case (16): currentSqlt3DTrk0.HipRight = copyTrkToJoint(b, currentSqlt3DTrk0.HipRight); break;
	case (17): currentSqlt3DTrk0.KneeRight = copyTrkToJoint(b, currentSqlt3DTrk0.KneeRight); break;
	case (18):currentSqlt3DTrk0.AnkleRight = copyTrkToJoint(b, currentSqlt3DTrk0.AnkleRight); break;
	case (19): currentSqlt3DTrk0.FootRight = copyTrkToJoint(b, currentSqlt3DTrk0.FootRight); break;
	case (20): currentSqlt3DTrk0.SpineShoulder = copyTrkToJoint(b, currentSqlt3DTrk0.SpineShoulder); break;
	case (21): currentSqlt3DTrk0.HandTipLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HandTipLeft); break;
	case (22): currentSqlt3DTrk0.ThumbLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ThumbLeft); break;
	case (23): currentSqlt3DTrk0.HandTipRight = copyTrkToJoint(b, currentSqlt3DTrk0.HandTipRight); break;
	case (24): currentSqlt3DTrk0.ThumbRight = copyTrkToJoint(b, currentSqlt3DTrk0.ThumbRight); break;
	default: printf("Error of Joint Index"); break;
	}

	return (b.sensor);
}

sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
sf::CircleShape circle(250.f);
sf::RectangleShape rectangle(sf::Vector2f(400, 400));
int shapeInt = 0;
int flag = -1;

sf::CircleShape cir(250.f);
sf::RectangleShape rect(sf::Vector2f(400, 400));
sf::Texture texture;

bool haveTexture = false;

void drawShape(sf::Color color) {
	if (shapeInt == 0) { // Draw Circle
		circle.setFillColor(color);
		window.clear();
		window.draw(circle);
		window.display();
	}
	else if (shapeInt == 1) { // Draw Rectangle
		rectangle.setFillColor(color);
		window.clear();
		window.draw(rectangle);
		window.display();
	}
}

void drawShape() {//texture

	if (shapeInt == 0)  //  Circle
	{
		cir.setTexture(&texture);
		window.clear();
		window.draw(cir);
		window.display();
		//haveTexture = false;
	}
	else if (shapeInt == 1) //  Rectangle
	{
		rect.setTexture(&texture);
		window.clear();
		window.draw(rect);
		window.display();
		//haveTexture = false;
	}
}

void changeTexture()
{
	if (flag == 0)
	{
		if (!texture.loadFromFile("timg.jpg"))
			cout << "Erreur de chargement de la texture 0" << endl;
		//flag = 1;
	}
	else if (flag == 1)
	{
		if (!texture.loadFromFile("fleur.jpg"))
			cout << "Erreur de chargement de la texture 1" << endl;
		//flag = 2;
	}
	else if (flag == 2)
	{
		if (!texture.loadFromFile("lena.jpg"))
			cout << "Erreur de chargement de la texture 2" << endl;
		flag = -1;
	}
}


void VRPN_CALLBACK handle_tracker(void* userData, const vrpn_TRACKERCB b)
{
	if (currentsqltTracked == 0) {
		if (previousIndexJoint <= b.sensor) {
			previousIndexJoint = b.sensor;
			insertJoindInSqletton(b);
		}
		else {
			currentsqltTracked = 1;

			// Push Right Hand : change texture
			if (prviousSqlt3DTrk0.HandRight.z > 1.3 && currentSqlt3DTrk0.HandRight.z < 1.3) {
				cout << "Push Right Hand" << endl;
				haveTexture = true;
				flag++;
				changeTexture();
				drawShape();
			}
			// Right Hand Up
			else if (prviousSqlt3DTrk0.HandRight.y < prviousSqlt3DTrk0.ShoulderRight.y && currentSqlt3DTrk0.HandRight.y > currentSqlt3DTrk0.ShoulderRight.y) {
				haveTexture = false;
				drawShape(sf::Color::Red);
			}

			// Right Hand Down
			else if (prviousSqlt3DTrk0.HandRight.y > prviousSqlt3DTrk0.ShoulderRight.y && currentSqlt3DTrk0.HandRight.y < currentSqlt3DTrk0.ShoulderRight.y) {
				haveTexture = false;
				drawShape(sf::Color::Blue);
			}

			// Left Hand Up, change shape(rectangle)
			else if (prviousSqlt3DTrk0.HandLeft.y < prviousSqlt3DTrk0.ShoulderLeft.y && currentSqlt3DTrk0.HandLeft.y > currentSqlt3DTrk0.ShoulderLeft.y) {
				shapeInt = 1;
				if (haveTexture)//(rect.getTexture() != NULL)
					drawShape();
				else
					drawShape(circle.getFillColor());
			}
			// Left Hand Down, change shape(circle)
			else if (prviousSqlt3DTrk0.HandLeft.y > prviousSqlt3DTrk0.ShoulderLeft.y && currentSqlt3DTrk0.HandLeft.y < currentSqlt3DTrk0.ShoulderLeft.y) {
				shapeInt = 0;
				if (haveTexture)//(cir.getTexture() != NULL)
					drawShape();
				else
					drawShape(rectangle.getFillColor());
			}
		}
	}
	else if (currentsqltTracked == 1) {
		insertJoindInSqletton(b);
		previousIndexJoint = b.sensor;
		currentsqltTracked = 0;
		prviousSqlt3DTrk0 = copySqlt2Sqlt(currentSqlt3DTrk0, prviousSqlt3DTrk0);
	}

}

int main(int argc, char* argv[])
{
	drawShape(sf::Color::Green);

	vrpn_Tracker_Remote* vrpnTracker = new vrpn_Tracker_Remote("Tracker0@10.3.2.125:3883");//Changer en local/IP
	vrpnTracker->register_change_handler(0, handle_tracker);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		vrpnTracker->mainloop();
		Sleep(100);
	}

	return 0;
}