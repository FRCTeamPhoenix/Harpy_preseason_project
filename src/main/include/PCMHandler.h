#pragma once

#include <frc/compressor.h>
#include <frc/solenoid.h>
#include <frc/smartdashboard/smartdashboard.h>
#include "RobotMap.h"

class PCMHandler{
	private:
		frc::Compressor compressor; 
        frc::Solenoid highgearSol = frc::Solenoid(PCM_SLOT_HIGHGEAR);
		frc::Solenoid lowgearSol = frc::Solenoid(PCM_SLOT_LOWGEAR);
		frc::Solenoid clawSolRight = frc::Solenoid(PCM_BOX_MANIPULATOR_RIGHT);
		frc::Solenoid clawSolLeft = frc::Solenoid(PCM_BOX_MANIPULATOR_LEFT);
		frc::Solenoid clawSolRight2 = frc::Solenoid(PCM_BOX_MANIPULATOR_RIGHT2);
		frc::Solenoid clawSolLeft2 = frc::Solenoid(PCM_BOX_MANIPULATOR_LEFT2);

    public:
		PCMHandler(int port);
		void turnOn();
		void turnOff();
		void setLowGear(bool value);
		void setHighGear(bool value);
		double getCurrent();
		void openManipulator();
		void closeManipulator();
};
