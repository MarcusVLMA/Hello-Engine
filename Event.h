#pragma once
class Event
{
public:
	bool isOn;

	virtual void event() = 0;
	
	Event();
	~Event();
};

