#include <SFML/Graphics.hpp>
#include "vrpn_SFML_interface.h"
#include "../common/Utils3D.h"
using std::cout;
using std::cin;
using std::endl;

int currentsqltTracked = 0;
int previousIndexJoint = -1;

Squelette3D currentSqlt3DTrk0;
Squelette3D prviousSqlt3DTrk0;

int insertJoindInSqletton(vrpn_TRACKERCB b) {
	switch (b.sensor) {
	case (0): currentSqlt3DTrk0.SpineBase = copyTrkToJoint(b, currentSqlt3DTrk0.SpineBase); break;
	case (1): currentSqlt3DTrk0.SpineMid = copyTrkToJoint(b, currentSqlt3DTrk0.SpineMid);break;
	case (2): currentSqlt3DTrk0.Neck = copyTrkToJoint(b, currentSqlt3DTrk0.Neck);break;
	case (3): currentSqlt3DTrk0.head = copyTrkToJoint(b, currentSqlt3DTrk0.head);break;
	case (4): currentSqlt3DTrk0.ShoulderLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ShoulderLeft);break;
	case (5): currentSqlt3DTrk0.ElbowLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ElbowLeft);break;
	case (6): currentSqlt3DTrk0.WristLeft = copyTrkToJoint(b, currentSqlt3DTrk0.WristLeft);break;
	case (7): currentSqlt3DTrk0.HandLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HandLeft);break;
	case (8): currentSqlt3DTrk0.ShoulderRight = copyTrkToJoint(b, currentSqlt3DTrk0.ShoulderRight);break;
	case (9): currentSqlt3DTrk0.ElbowRight = copyTrkToJoint(b, currentSqlt3DTrk0.ElbowRight);break;
	case (10): currentSqlt3DTrk0.WristRight = copyTrkToJoint(b, currentSqlt3DTrk0.WristRight);break;
	case (11): currentSqlt3DTrk0.HandRight = copyTrkToJoint(b, currentSqlt3DTrk0.HandRight);break;
	case (12): currentSqlt3DTrk0.HipLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HipLeft);break;
	case (13): currentSqlt3DTrk0.KneeLeft = copyTrkToJoint(b, currentSqlt3DTrk0.KneeLeft);break;
	case (14): currentSqlt3DTrk0.AnkleLeft = copyTrkToJoint(b, currentSqlt3DTrk0.AnkleLeft);break;
	case (15): currentSqlt3DTrk0.FootLeft = copyTrkToJoint(b, currentSqlt3DTrk0.FootLeft);break;
	case (16): currentSqlt3DTrk0.HipRight = copyTrkToJoint(b, currentSqlt3DTrk0.HipRight);break;
	case (17): currentSqlt3DTrk0.KneeRight = copyTrkToJoint(b, currentSqlt3DTrk0.KneeRight);break;
	case (18): currentSqlt3DTrk0.AnkleRight = copyTrkToJoint(b, currentSqlt3DTrk0.AnkleRight);break;
	case (19): currentSqlt3DTrk0.FootRight = copyTrkToJoint(b, currentSqlt3DTrk0.FootRight);break;
	case (20): currentSqlt3DTrk0.SpineShoulder = copyTrkToJoint(b, currentSqlt3DTrk0.SpineShoulder);break;
	case (21): currentSqlt3DTrk0.HandTipLeft = copyTrkToJoint(b, currentSqlt3DTrk0.HandTipLeft);break;
	case (22): currentSqlt3DTrk0.ThumbLeft = copyTrkToJoint(b, currentSqlt3DTrk0.ThumbLeft);break;
	case (23): currentSqlt3DTrk0.HandTipRight = copyTrkToJoint(b, currentSqlt3DTrk0.HandTipRight);break;
	case (24): currentSqlt3DTrk0.ThumbRight = copyTrkToJoint(b, currentSqlt3DTrk0.ThumbRight);break;
	default: printf("Error of Joint Index");break;
	}

	return(b.sensor);
}

sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
sf::CircleShape circle(100.f);
sf::RectangleShape rectangle(sf::Vector2f(100, 50));
int shapeInt = 0;

sf::Color currentColor = sf::Color::Blue;

//sf::Sprite sprite;
//sf::Texture textureJava;
//sf::Texture texturePHP;

//sprite = new sf::Sprite();

void drawShape(sf::Color color) {
	if (shapeInt == 0) { // Draw Circle
		circle.setFillColor(color);
		currentColor = color;
		window.clear();
		window.draw(circle);
		window.display();
	}
	else if (shapeInt == 1) { // Draw Rectangle
		cout << "#####" << endl;
		rectangle.setFillColor(color);
		currentColor = color;
		window.clear();
		window.draw(rectangle);
		window.display();
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

			// Right Hand Up
			if (prviousSqlt3DTrk0.HandRight.y < prviousSqlt3DTrk0.ShoulderRight.y && currentSqlt3DTrk0.HandRight.y > currentSqlt3DTrk0.ShoulderRight.y) {
				drawShape(sf::Color::Red);
			}

			// Right Hand Down
			else if (prviousSqlt3DTrk0.HandRight.y > prviousSqlt3DTrk0.ShoulderRight.y && currentSqlt3DTrk0.HandRight.y < currentSqlt3DTrk0.ShoulderRight.y) {
				drawShape(sf::Color::Blue);
			}

			// Left Hand Up
			else if (prviousSqlt3DTrk0.HandLeft.y < prviousSqlt3DTrk0.ShoulderLeft.y && currentSqlt3DTrk0.HandLeft.y > currentSqlt3DTrk0.ShoulderLeft.y) {
				shapeInt = 1;
				drawShape(currentColor);
			}

			// Left Hand Down
			else if (prviousSqlt3DTrk0.HandLeft.y > prviousSqlt3DTrk0.ShoulderLeft.y && currentSqlt3DTrk0.HandLeft.y < currentSqlt3DTrk0.ShoulderLeft.y) {
				shapeInt = 0;
				drawShape(currentColor);
			}

			// Push Right Hand : change texture
			else if (prviousSqlt3DTrk0.HandRight.z > 1.3 && currentSqlt3DTrk0.HandRight.z < 1.3) {
				cout << "Push Right Hand" << endl;
				/*window.clear();
				sprite.setTexture(textureJava);
				window.draw(sprite);
				window.display();*/
			}

			// Get Right Hand : change texture
			else if (prviousSqlt3DTrk0.HandRight.z < 1.3 && currentSqlt3DTrk0.HandRight.z > 1.3) {
				cout << "Get Right Hand" << endl;
				/*window.clear();
				sprite.setTexture(texturePHP);
				window.draw(sprite);
				window.display();*/
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

//void VRPN_CALLBACK handle_velocity(void* userData, const vrpn_TRACKERVELCB c) {
//	cout << "b" << endl;
//	cout << c.sensor << " " << c.vel[0] << endl;
//}

int main(int argc, char* argv[])
{
	//textureJava.loadFromFile("java.png");
	//texturePHP.loadFromFile("php.png");

	drawShape(sf::Color::Green);

	vrpn_Tracker_Remote* vrpnTracker = new vrpn_Tracker_Remote("Tracker0@localhost:3883");//Changer en local
	vrpnTracker->register_change_handler(0, handle_tracker);
	//vrpnTracker->register_change_handler(0, handle_velocity);

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