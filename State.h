#pragma once
class State
{

public:
	virtual void init() = 0;

	// handle userinput in begining state
	virtual void HandleInput() = 0;
	// update state
	virtual void update() = 0;

	//draw current frame in state 
	virtual void draw() = 0;

	//pause state
	virtual void pause() {};
	//resume state 
	virtual void resume() {}
};

