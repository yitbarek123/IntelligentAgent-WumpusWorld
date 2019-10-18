#ifndef INFERENCE_H
#define INFERENCE_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include "../KnowledgeBase/KB.h"
#include "../../utilities/DataStructures.h"
#include "../../utilities/Model.h"

namespace components{

class Inference
{
  /*
  *
  * This class used to infer possible action to be performed by the agent.
  * and it also updates the knowledgebase with the infered parameters
  *
  */
  private:
    std::set<std::pair<int, int>> ok_rooms;
    std::pair<int, int> wumpus_room;
    std::set<std::pair<int, int>> pit_rooms;
    KnowledgeBase current_kb;
    std::map<std::pair<int, int>, DataStructures::Knowledge> p_hist;

  public:
    Inference(KnowledgeBase current_kb);
    // Inference(KnowledgeBase& kb);

    bool is_valid_position(int i, int j);
    std::vector<std::pair<int, int>> get_adjacent_rooms(std::pair<int, int> current_room);
    std::vector<std::pair<int, int>> get_adjacent_visited_rooms(std::pair<int, int> current_room);
    std::pair<int, int> find_possible_move(std::pair<int, int> current_room);

    bool infer_wumpus(std::pair<int, int> current_room);
    bool infer_not_wumpus(std::pair<int, int> current_room);
    bool infer_pit(std::pair<int, int> current_room);
    bool infer_not_pit(std::pair<int, int> current_room);
    bool infer_gold(std::pair<int, int> current_room);

    bool check_equivalence(std::pair<int, int> room, DataStructures::constraint specific_constraint, DataStructures::model specified_model);
    bool infer_presence(std::pair<int, int> room, DataStructures::Rule character);
    void rule_matching(std::pair<int, int> room);

    DataStructures::Decision infer(std::pair<int, int> current_room);
};

}
#endif
