#pragma once
struct vec
{
	double x, y;
};

class Fish
{
	vec pos, velo, accel;

public:
	
	Fish(vec pos,vec velo);

	void UpdatePos(double dtime);
	vec GetPos();
	void SetAccel(vec a);

};
