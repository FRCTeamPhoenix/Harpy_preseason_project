#include "PCMHandler.h"
PCMHandler::PCMHandler(){
}

void PCMHandler::turnOn(){
    m_compressor.SetClosedLoopControl(true);
}

void PCMHandler::turnOff(){
    m_compressor.SetClosedLoopControl(false);
}

void PCMHandler::setLowGear(bool value){
    m_lowgearSol.Set(value);
}

void PCMHandler::setHighGear(bool value){
    m_highgearSol.Set(value);
}

void PCMHandler::openManipulator(){
    m_clawSolLeft.Set(false);
	m_clawSolRight.Set(false);
	m_clawSolLeft2.Set(true);
	m_clawSolRight2.Set(true);
}

void PCMHandler::closeManipulator(){
    m_clawSolLeft.Set(true);
	m_clawSolRight.Set(true);
	m_clawSolLeft2.Set(false);
	m_clawSolRight2.Set(false);
}