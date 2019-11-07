#pragma once

#include <frc/compressor.h>
#include <frc/solenoid.h>
#include <frc/smartdashboard/smartdashboard.h>
#include "RobotMap.h"

class PCMHandler{
	private:
		frc::Compressor m_compressor  = frc::Compressor(PCM_CAN_ID); 
        frc::Solenoid m_highgearSol = frc::Solenoid(PCM_CAN_ID, PCM_SLOT_HIGHGEAR);
		frc::Solenoid m_lowgearSol = frc::Solenoid(PCM_CAN_ID, PCM_SLOT_LOWGEAR);
		frc::Solenoid m_clawSolRight = frc::Solenoid(PCM_CAN_ID, PCM_BOX_MANIPULATOR_RIGHT);
		frc::Solenoid m_clawSolLeft = frc::Solenoid(PCM_CAN_ID, PCM_BOX_MANIPULATOR_LEFT);
		frc::Solenoid m_clawSolRight2 = frc::Solenoid(PCM_CAN_ID, PCM_BOX_MANIPULATOR_RIGHT2);
		frc::Solenoid m_clawSolLeft2 = frc::Solenoid(PCM_CAN_ID, PCM_BOX_MANIPULATOR_LEFT2);
		PCMHandler();
   
    public:
		void turnOn();
		void turnOff();
		void setLowGear(bool value);
		void setHighGear(bool value);
		void openManipulator();
		void closeManipulator();
		static PCMHandler* getInstance()
		{
            static PCMHandler instance;
            
            return &instance;
        }
		PCMHandler(PCMHandler const&) = delete;
        void operator=(PCMHandler const&)  = delete;
};
