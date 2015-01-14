#ifndef POTATO_DRIVE_H
#define POTATO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class PotatoDrive: public CommandBase
{
public:
	PotatoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
