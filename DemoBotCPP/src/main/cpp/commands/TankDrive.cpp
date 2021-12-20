// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TankDrive.h"
#include "subsystems/Drivetrain.h"

TankDrive::TankDrive(Drivetrain* drivetrain, std::function<double(void)> left, std::function<double(void)> right) :
  m_drivetrain(drivetrain),
  m_left(left),
  m_right(right) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(drivetrain);
}

// Called when the command is initially scheduled.
void TankDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  m_drivetrain->SetSpeed(m_left(), m_right());
}

// Called once the command ends or is interrupted.
void TankDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool TankDrive::IsFinished() {
  return false;
}
