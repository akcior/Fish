#include"Fish.h"

Fish::Fish(vec pos, vec velo)
{
	this->pos = pos;
	this->velo = velo;
	this->accel.x = 0;
	this->accel.y = 0;
}

void Fish::UpdatePos(double dTime)
{
	pos.x += velo.x * dTime;
	pos.y += velo.y * dTime;
}

vec Fish::GetPos()
{
	return pos;
}
void Fish::SetAccel(vec a)
{
	accel.x = a.x;
	accel.y = a.y;

}