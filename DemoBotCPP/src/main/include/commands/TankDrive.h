// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TankDrive : public frc2::CommandHelper<frc2::CommandBase, TankDrive> {
  public:
    TankDrive(Drivetrain* drivetrain, std::function<double(void)> left, std::function<double(void)> right);

    void Initialize() override;

    void Execute() override;

    void End(bool interrupted) override;

    bool IsFinished() override;

  private:
    Drivetrain* m_drivetrain;
    std::function<double(void)> m_left;
    std::function<double(void)> m_right;
};
