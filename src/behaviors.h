#ifndef BEHAVIORS_H_
#define BEHAVIORS_H_

#include "biodynamo.h"

namespace bdm {

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// --------------------- Growth behaviour  ---------------------
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

struct Growth : public Behavior {
  BDM_BEHAVIOR_HEADER(Growth, Behavior, 1);  // Define the behavior class

  Growth() { AlwaysCopyToNew(); }            // Constructor for the behavior

  virtual ~Growth() {}               // Virtual destructor for the behavior

  void Run(Agent* agent) override {  // Define the behavior's Run method
    if (auto* cell =
            dynamic_cast<Cell*>(agent)) {  // Check if the agent is a Cell

      // If the cell is smaller than 10, grow it
      if (cell->GetDiameter() < 10) {

        // Increase the cell's volume based on the growth speed
        cell->ChangeVolume(400);

        // Here 400 is the speed and the change to the volume is based on the
        // simulation time step.
        // The default here is 0.01 for each timestep, not 1.
      }
    }
  }
};

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// --------------------- Growth & Division behaviour  ---------------------
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

struct GrowthAndDivision : public Behavior {
  BDM_BEHAVIOR_HEADER(GrowthAndDivision, Behavior, 1);

  GrowthAndDivision() { AlwaysCopyToNew(); }
  virtual ~GrowthAndDivision() {}

  void Run(Agent* agent) override {
    if (auto* cell = dynamic_cast<Cell*>(agent)) {
      auto* random = Simulation::GetActive()->GetRandom();
      if (cell->GetDiameter() < division_threshold_diameter_) {
        cell->ChangeVolume(growth_speed_);

      } else {
        if (random->Uniform(0, 1) < 0.8) {
          cell->Divide();
        }
      }
    }
  }

  void SetGrowthSpeed(double growth_speed) { growth_speed_ = growth_speed; }
  double GetGrowthSpeed() const { return growth_speed_; }

  void SetDivisionThresholdDiameter(double division_threshold_diameter) {
    division_threshold_diameter_ = division_threshold_diameter;
  }
  double GetDivisionThresholdDiameter() const {
    return division_threshold_diameter_;
  }

 private:
  // Here 400 is the speed and the change to the volume is based on the
  // simulation time step.
  // The default here is 0.01 for each timestep, not 1.
  double growth_speed_ = 800;
  double division_threshold_diameter_ = 10;
};

}  // namespace bdm

#endif  // BEHAVIORS_H_