// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  ~Drivetrain();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void SetSpeed(double left, double right);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  ctre::phoenix::motorcontrol::can::TalonSRX* frontLeft;
  ctre::phoenix::motorcontrol::can::TalonSRX* frontRight;
  ctre::phoenix::motorcontrol::can::TalonSRX* backLeft;
  ctre::phoenix::motorcontrol::can::TalonSRX* backRight;
};
