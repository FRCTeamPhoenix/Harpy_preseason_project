#include "PCMHandler.h"

PCMHandler::PCMHandler(int port){
    compressor = frc::Compressor(port);
    compressor.SetClosedLoopControl(true);
}

void PCMHandler::turnOn(){
    compressor.SetClosedLoopControl(true);
}

void PCMHandler::turnOff(){
    compressor.SetClosedLoopControl(false);
}

void PCMHandler::setLowGear(bool value){
    lowgearSol.Set(value);
}

void PCMHandler::setHighGear(bool value){
    highgearSol.Set(value);
}

double PCMHandler::getCurrent(){
    return compressor.GetCompressorCurrent();
}

void PCMHandler::openManipulator(){
    clawSolLeft.Set(false);
	clawSolRight.Set(false);
	clawSolLeft2.Set(true);
	clawSolRight2.Set(true);
}

void PCMHandler::closeManipulator(){
    clawSolLeft.Set(true);
	clawSolRight.Set(true);
	clawSolLeft2.Set(false);
	clawSolRight2.Set(false);
}