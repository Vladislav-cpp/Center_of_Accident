#pragma once

class Player
{
public:
	virtual void shot() = 0;
	virtual void movement() = 0;
private:
	unsigned int Xp;

};

