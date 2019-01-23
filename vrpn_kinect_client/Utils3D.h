#include "vrpn_Tracker.h"
//#include "vrpn_kinect_client.h"
#include <iostream>

struct JOINT3D {
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

struct Squelette3D {
	JOINT3D SpineBase;
	JOINT3D SpineMid;
	JOINT3D Neck;
	JOINT3D head;
	JOINT3D ShoulderLeft;

	JOINT3D ElbowLeft;
	JOINT3D WristLeft;
	JOINT3D HandLeft;
	JOINT3D ShoulderRight;
	JOINT3D ElbowRight;

	JOINT3D WristRight;
	JOINT3D HandRight;
	JOINT3D HipLeft;
	JOINT3D KneeLeft;
	JOINT3D AnkleLeft;

	JOINT3D FootLeft;
	JOINT3D HipRight;
	JOINT3D KneeRight;
	JOINT3D AnkleRight;
	JOINT3D FootRight;

	JOINT3D SpineShoulder;
	JOINT3D HandTipLeft;
	JOINT3D ThumbLeft;
	JOINT3D HandTipRight;
	JOINT3D ThumbRight;
};

JOINT3D copyTrkToJoint(const vrpn_TRACKERCB src, JOINT3D dis);
double getDistanceAbs(double a, double b);
Squelette3D copySqlt2Sqlt(Squelette3D current, Squelette3D previous);