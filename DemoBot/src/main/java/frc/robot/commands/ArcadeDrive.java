// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.commands;

import java.util.function.Supplier;

import edu.wpi.first.wpilibj2.command.CommandBase;
import frc.robot.subsystems.Drivetrain;

public class ArcadeDrive extends CommandBase {
  Drivetrain drivetrain;
  Supplier<Double> xSupplier;
  Supplier<Double> zSupplier;
  /** Creates a new ArcadeDrive. */
  public ArcadeDrive(Drivetrain drive, Supplier<Double> xaxisSupplier, Supplier<Double> zaxisSupplier) {
    // Use addRequirements() here to declare subsystem dependencies.
    drivetrain = drive;
    xSupplier = xaxisSupplier;
    zSupplier = zaxisSupplier;
    addRequirements(drivetrain);
  }

  // Called when the command is initially scheduled.
  @Override
  public void initialize() {}

  // Called every time the scheduler runs while the command is scheduled.
  @Override
  public void execute() {
    drivetrain.betterArcadeDrive(xSupplier.get(), zSupplier.get());
    
  }

  // Called once the command ends or is interrupted.
  @Override
  public void end(boolean interrupted) {}

  // Returns true when the command should end.
  @Override
  public boolean isFinished() {
    return false;
  }
}
