// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"
#include <frc/Joystick.h>

#include "subsystems/Drivetrain.h"

#include "commands/ArcadeDrive.h"

RobotContainer::RobotContainer() : m_autonomousCommand(&m_subsystem) {
  // Controls
  joystick1 = new frc::Joystick(constants::Ports::JOYSTICK_1);
  
  // Subsystems
  m_drivetrain = new Drivetrain();

  // Commands
  defaultDriveCommand = new ArcadeDrive(m_drivetrain, 
    [joystick1 = joystick1]() -> double { return -joystick1->GetRawAxis(0); }, 
    [joystick1 = joystick1]() -> double { return joystick1->GetRawAxis(1); });

  // Set Default Commands
  m_drivetrain->SetDefaultCommand(*defaultDriveCommand);

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}

RobotContainer::~RobotContainer() {
  delete m_drivetrain;
}
