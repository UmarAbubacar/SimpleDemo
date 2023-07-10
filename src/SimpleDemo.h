// -----------------------------------------------------------------------------
//
// Copyright (C) 2021 CERN & University of Surrey for the benefit of the
// BioDynaMo collaboration. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// See the LICENSE file distributed with this work for details.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership.
//
// -----------------------------------------------------------------------------
#ifndef SIMPLEDEMO_H_
#define SIMPLEDEMO_H_

#include "MyCell.h"
#include "behaviors.h"
#include "biodynamo.h"

namespace bdm {

inline int Simulate(int argc, const char** argv) {
  Simulation simulation(argc, argv);
  auto* rm = simulation.GetResourceManager();
  // ##########################################################################
  // ---------------------------- Simple Cells --------------------------------
  // ##########################################################################

  // TASK 1: Define initial model
  //    in this example: single cell at the origin with a
  //    diameter of 8.0 (no unit associated).

  auto* cell = new MyCell();
  cell->SetDiameter(8.0);
  cell->SetPosition({0, 0, 0});
  // mass is used to compute mechanical interactions of the cell
  cell->SetMass(1.0);
  cell->SetCellColor(1);

  // add agent to the simulation
  rm->AddAgent(cell);

  // ##########################################################################
  // --------------------- Cell with Growth behaviour  ------------------------
  // ##########################################################################

  // TASK 2: Define cell with growth behaviour
  //    in this example: adding a growth behaviour to the cell previously
  //    defined

  auto growth_behavior = new Growth();
  cell->AddBehavior(growth_behavior);

  // ##########################################################################
  // ----------------- Cell with Growth and Division behaviour  ---------------
  // ##########################################################################

  // ######### TODO #########
  // TASK 3: Define cell with growth and division behaviour
  //    in this example: adding a growth and division behaviour to a new cell at
  //    position (30, 0, 0)
  // Task: Add a new growth and division behaviour (GrowthAndDivision()) using
  // the method AddBehavior() to a new cell (you can call it cell2)
  // remember to set the cell's can_divide_ to true

  // Solution:
  // Hint: you can copy the code from the above example and modify it
  auto* cell2 = new MyCell();
  cell2->SetDiameter(8.0);
  cell2->SetPosition({30, 0, 0});
  cell2->SetMass(1.0);
  cell2->SetCellColor(2);

  auto growth_and_div = new GrowthAndDivision();
  growth_and_div->SetGrowthSpeed(1000);
  cell2->AddBehavior(growth_and_div);

  cell2->SetCanDivide(true);

  rm->AddAgent(cell2);

  // ##########################################################################
  // --------------------- Cell with Chemotaxis behaviour  ---------------------
  // ##########################################################################

  // TASK: 4: Define a new cell with a chemotaxi behaviour
  //    in this example: adding a chemotaxis behaviour to a new cell at position
  //    (60, 0, 0)

  // Solution:
  auto* cell3 = new MyCell();
  cell3->SetDiameter(8.0);
  cell3->SetPosition({60, 0, 0});
  cell3->SetMass(1.0);
  cell3->SetCellColor(3);

  enum Substances { kSubstance };  // Define an enum for the substances
  // this can be a list eg {kSubstance1, kSubstance2, kSubstance3}

  // Define an alias for the ModelInitializer class
  using MI = ModelInitializer;

  // Define the substance using the DefineSubstance method of ModelInitializer
  // the arguments for DefineSubstance are: substance id, substance name,
  // diffusion constant, decay constant, resolution
  MI::DefineSubstance(kSubstance, "substance", 0, 0, 200);

  // Initialize the substance with a Gaussian distribution using the
  // GaussianBand method of ModelInitializer The arguments for GaussianBand are:
  // mean, standard deviation, and axis
  auto a_initializer = GaussianBand(200, 100, Axis::kXAxis);

  // UNCOMMENT THE FOLLOWING LINE TO ENABLE CONCENTRATION GRADIENT
  // MI::InitializeSubstance(kSubstance, a_initializer);

  // Add a new chemotaxis behavior to the cell
  cell3->AddBehavior(new Chemotaxis("substance", -0.2));

  // UNCOMMENT THE FOLLOWING LINE TO ENABLE CELL3 AND ITS MOVEMENT
  // rm->AddAgent(cell3);

  // --------------------- Run the Simulation  ---------------------

  // Run simulation for 200 timesteps
  simulation.GetScheduler()->Simulate(200);

  std::cout << "Simulation completed successfully!" << std::endl;
  return 0;
}

}  // namespace bdm

#endif  // SIMPLEDEMO_H_
