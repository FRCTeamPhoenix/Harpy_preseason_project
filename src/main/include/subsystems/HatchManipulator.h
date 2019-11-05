#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>

#include "RobotMap.h"

class HatchManipulator : public frc::Subsystem {
    public:
        //a singleton
        static HatchManipulator* getInstance(){
            static HatchManipulator instance;

            return &instance;
        }    

        //prevents copying
        HatchManipulator(HatchManipulator const&) = delete;
        void operator=(HatchManipulator const&) = delete;

        void setSpeed(double speed);

    private:
        HatchManipulator();

        WPI_TalonSRX m_talonhatch = {TALON_HATCH_MANIP};
};