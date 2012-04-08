#pragma once

class PVector {
public:
	float x, y, z;
	PVector() {
		x=0.0; y=0.0; z = 0.0;
	}
	PVector(float xPos, float yPos)
	{
		x = xPos; y = yPos; z = 0.0;
	}
};

class PColor {
public:
	float r, g, b, a;
	PColor() {
		r=0.0; g=1.0; b=1.0; a=1.0;
	}
};

class PTexture {
public:
	float u, v;
	PTexture() {
		u = 0.0; v = 0.0;
	}
};

class PTimer 
{
public:
	
	PTimer() 
	{
		_time = 0.0; 
		_duration = 200; 
		_state = 0.0;
		_upDown = false;
	}
	
	void tick()
	{
		_time = _time + _state;
		
		if (_time > _duration) 
		{
			_time = _duration;
			
			if(_upDown)	_state = -1;
			else		_state = 0;
		}
		else if(_time < 0)
		{
			_time = 0;
			
			if(_upDown)	_state = 1;
			else		_state = 0;
		}
	}
	
	void setUpDown(bool upDown)
	{
		_upDown = upDown;
	}
	
	void setDuration(float duration)
	{
		_duration = duration;
	}
	
	void setState(float state)
	{
		_state = state;
	}
	
	float getDuration()
	{
		return _duration;
	}
	
	float getTime()
	{
		return _time;
	}
	
	void setTime(float time)
	{
		_time = time;
	}
	
	float getState()
	{
		return _state;
	}
	
	void reset()
	{
		_time = 0;
		_state = 0;
	}
	
private:
	
	float _state; 
	float _time;
	float _duration;
	bool _upDown;
	
};

class PSetting 
{
public:
	
	
	float sizeMin;
	float sizeMax;
	float percent;
	float dirMin;
	float dirMax;
	float damping;
	float lifeMin;
	float lifeMax;
	float lifeSubMin;
	float lifeSubMax;
	
	PSetting() 
	{
		clear();
	}
	
	void clear()
	{
		sizeMin = 2.0;
		sizeMax = 8.0;
		percent = 1;
		dirMin = 0.2;
		dirMax = 1;
		damping = 0.2;
		lifeMin = 0.3;
		lifeMax = 1.0;
		lifeSubMin = 0.001;
		lifeSubMax = 0.004;
	}
};