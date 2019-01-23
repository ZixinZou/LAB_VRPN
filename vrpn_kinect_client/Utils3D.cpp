#include "Utils3D.h"


JOINT3D copyTrkToJoint(const vrpn_TRACKERCB src, JOINT3D dis) {
	dis.x = src.pos[0];
	dis.y = src.pos[1];
	dis.z = src.pos[2];

	return dis;
}


double getDistanceAbs(double a, double b) {
	double c = abs(a - b);
	return c;
}

Squelette3D copySqlt2Sqlt(Squelette3D current, Squelette3D previous) {

	previous.SpineBase = current.SpineBase;
	previous.SpineMid = current.SpineMid;
	previous.Neck = current.Neck;
	previous.head = current.head;
	previous.ShoulderLeft = current.ShoulderLeft;

	previous.ElbowLeft = current.ElbowLeft;
	previous.WristLeft = current.WristLeft;
	previous.HandLeft = current.HandLeft;
	previous.ShoulderRight = current.ShoulderRight;
	previous.ElbowRight = current.ElbowRight;

	previous.WristRight = current.WristRight;
	previous.HandRight = current.HandRight;
	previous.HipLeft = current.HipLeft;
	previous.KneeLeft = current.KneeLeft;
	previous.AnkleLeft = current.AnkleLeft;

	previous.FootLeft = current.FootLeft;
	previous.HipRight = current.HipRight;
	previous.KneeRight = current.KneeRight;
	previous.AnkleRight = current.AnkleRight;
	previous.FootRight = current.FootRight;

	previous.SpineShoulder = current.SpineShoulder;
	previous.HandTipLeft = current.HandTipLeft;
	previous.ThumbLeft = current.ThumbLeft;
	previous.HandTipRight = current.HandTipRight;
	previous.ThumbRight = current.ThumbRight;
	return previous;
}