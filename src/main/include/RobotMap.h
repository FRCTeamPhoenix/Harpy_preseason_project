/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

const int PCM_CAN_ID = 11;
const int PCM_SLOT_HIGHGEAR = 4;
const int PCM_SLOT_LOWGEAR = 5;
const int PCM_BOX_MANIPULATOR_LEFT = 0;
const int PCM_BOX_MANIPULATOR_LEFT2 = 1;
const int PCM_BOX_MANIPULATOR_RIGHT = 2;
const int PCM_BOX_MANIPULATOR_RIGHT2 = 6;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
const int TALON_HATCH_MANIP = 8;
const int TALON_FRONT_LEFT = 1;
const int TALON_FRONT_RIGHT = 2;
const int TALON_BACK_LEFT = 3;
const int TALON_BACK_RIGHT = 4;
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
