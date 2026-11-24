#pragma once

#include "main.h"
#include "lemlib/api.hpp"

// Shared robot objects
extern pros::Controller controller;
extern lemlib::Chassis chassis;

// Robot initialization
void setupRobot();