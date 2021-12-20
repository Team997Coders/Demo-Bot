// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include "Constants.h"
#include <frc/Joystick.h>

#include "subsystems/Drivetrain.h"

#include "commands/ArcadeDrive.h"

RobotContainer::RobotContainer() {
  // controls
  m_joystick1 = new frc::Joystick(constants::Ports::JOYSTICK_1);
  
  // subsystems
  m_drivetrain = new Drivetrain();

  // commands (need to be mindful of deletion)
  m_defaultDriveCommand = new ArcadeDrive(m_drivetrain, 
    [m_joystick1 = m_joystick1]() -> double { return -m_joystick1->GetRawAxis(0); }, 
    [m_joystick1 = m_joystick1]() -> double { return m_joystick1->GetRawAxis(1); });

  // set default commands
  m_drivetrain->SetDefaultCommand(*m_defaultDriveCommand);

  // Configure the button bindings
  ConfigureButtonBindings();
}

RobotContainer::~RobotContainer() {
  // controls
  delete m_joystick1;
  
  // subsystems
  delete m_drivetrain;

  // commands
  delete m_defaultDriveCommand;
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_autonomousCommand;
}