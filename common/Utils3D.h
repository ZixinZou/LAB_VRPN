#include "vrpn_Tracker.h"
#include <iostream>

struct JOINT3D {
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	//double a = 0.0;
	//double b = 0.0;
	//double c = 0.0;
	//double d = 0.0;
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

/*
	ORIENT4D SpineBaseORIENT;
	ORIENT4D SpineMidORIENT;
	ORIENT4D NeckORIENT;
	ORIENT4D headORIENT;
	ORIENT4D ShoulderLeftORIENT;

	ORIENT4D ElbowLeftORIENT;
	ORIENT4D WristLeftORIENT;
	ORIENT4D HandLeftORIENT;
	ORIENT4D ShoulderRightORIENT;
	ORIENT4D ElbowRightORIENT;

	ORIENT4D WristRightORIENT;
	ORIENT4D HandRightORIENT;
	ORIENT4D HipLeftORIENT;
	ORIENT4D KneeLeftORIENT;
	ORIENT4D AnkleLeftORIENT;

	ORIENT4D FootLeftORIENT;
	ORIENT4D HipRightORIENT;
	ORIENT4D KneeRightORIENT;
	ORIENT4D AnkleRightORIENT;
	ORIENT4D FootRightORIENT;

	ORIENT4D SpineShoulderORIENT;
	ORIENT4D HandTipLeftORIENT;
	ORIENT4D ThumbLeftORIENT;
	ORIENT4D HandTipRightORIENT;
	ORIENT4D ThumbRightORIENT;*/
};

JOINT3D copyTrkToJoint(const vrpn_TRACKERCB src, JOINT3D dis);
//ORIENT4D copyTrkToOrient(const vrpn_TRACKERCB src, ORIENT4D orien);
double getDistanceAbs(double a, double b);
Squelette3D copySqlt2Sqlt(Squelette3D current, Squelette3D previous);