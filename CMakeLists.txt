cmake_minimum_required(VERSION 3.21)
project(optionCalculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(OptionCalculator main.cpp src/Simulation/Simulator/PathIndependentSimulation/SimpleMCSimulation.cpp
        src/Simulation/Simulator/PathIndependentSimulation/SimpleMCSimulation.h
        src/Statics/RandomSample.cpp
        src/Statics/RandomSample.h
        src/PayOff/EuropeanCall.cpp
        src/PayOff/EuropeanCall.h
        src/PayOff/EuropeanPut.cpp
        src/PayOff/EuropeanPut.h
        src/PayOff/Payoff.cpp
        src/PayOff/Payoff.h
        src/Discount/Discount.h
        src/Statics/SummaryStatistics.cpp
        src/Statics/SummaryStatistics.h
        src/Simulation/Simulator/PathIndependentSimulation/Simulator.cpp
        src/Simulation/Simulator/PathIndependentSimulation/Simulator.h
        src/PayOff/HW1_Option.cpp src/PayOff/HW1_Option.h
        src/Simulation/Simulator/PathdependentSimulation/DependentSimpleMCSimulation.cpp
        src/Simulation/Simulator/PathdependentSimulation/DependentSimpleMCSimulation.h
        src/Simulation/Simulator/PathdependentSimulation/DependentSimulator.cpp
        src/Simulation/Simulator/PathdependentSimulation/DependentSimulator.h)
