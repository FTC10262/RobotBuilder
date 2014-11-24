#header()

\#include "Robot.h"

#@autogenerated_code("initialization", "")
#parse("${exporter-path}CommandBasedRobot-initialization.cpp")
#end

void Robot::RobotInit() {
	RobotMap::init();
#@autogenerated_code("constructors", "	")
#parse("${exporter-path}CommandBasedRobot-constructors.cpp")
#end
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();

	// instantiate the command used for the autonomous period
#@autogenerated_code("autonomous", "	")
#parse("${exporter-path}CommandBasedRobot-autonomous.cpp")
#end
  }
	
void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);
