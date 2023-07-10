#ifndef MYCELL_H_
#define MYCELL_H_

#include "biodynamo.h"

namespace bdm {

// Define my custom cell MyCell, which extends Cell by adding extra data
// members: cell_color and can_divide
class MyCell : public Cell {  // our object extends the Cell object
  // create the header with our new data member
  BDM_AGENT_HEADER(MyCell, Cell, 1);

 public:
  MyCell() {}
  explicit MyCell(const Real3& position) : Base(position) {}
  virtual ~MyCell() {}

  /// If MyCell divides, the daughter has to initialize its attributes
  void Initialize(const NewAgentEvent& event) override {
    Base::Initialize(event);

    if (auto* mother = dynamic_cast<MyCell*>(event.existing_agent)) {
      cell_color_ = mother->cell_color_;
      if (event.GetUid() == CellDivisionEvent::kUid) {
        // the daughter will be able to divide
        can_divide_ = true;
      } else {
        can_divide_ = mother->can_divide_;
      }
    }
  }

  // getter and setter for our new data member
  void SetCanDivide(bool d) { can_divide_ = d; }
  bool GetCanDivide() const { return can_divide_; }

  void SetCellColor(int cell_color) { cell_color_ = cell_color; }
  int GetCellColor() const { return cell_color_; }

 private:
  // declare new data member and define their type
  // private data can only be accessed by public function and not directly
  bool can_divide_;
  int cell_color_;
};

}  // namespace bdm

#endif  // MYCELL_H_