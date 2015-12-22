#include <iostream>
#include <algorithm>
using namespace std;

int b_dmg = 10;
int b_start_hp = 71;
int best = 100000;
int threshold = 0;
bool winnable(int mana, int hp, int b_hp, int shield, int poison, int recharge, int used, bool player_turn) {
  //win or lose?
  if (player_turn) hp--;
  if (used > threshold) return false;
  if (b_hp <= 0) { best = min(best, used); return true;}
  if (hp <= 0) return false;

  //spell effects!
  if (recharge) {mana+=101; recharge--;}
  if (poison) {b_hp -= 3; poison--;}
  if (!player_turn) {
    if (shield) {hp -= (b_dmg-7); shield--;}
    else hp -= b_dmg;
  } else {
    if (shield) shield--;
  }
  if (b_hp <= 0) { best = min(best, used); return true;}
  //cast spell
  if (mana <= 0) return false;
  if (player_turn) {
    return
      (mana >= 53 ? winnable(mana-53, hp, b_hp-4, shield, poison, recharge, used+53,false) : false) ||
      (mana >= 73 ? winnable(mana-73, hp+2, b_hp-2, shield, poison, recharge, used+73,false) : false) ||
      (mana >= 113 && shield == 0 ? winnable(mana-113, hp, b_hp, 6, poison, recharge, used+113, !player_turn) : false) ||
      (mana >= 173 && poison == 0 ? winnable(mana-173, hp, b_hp, shield, 6, recharge, used+173, !player_turn) : false) ||
      (mana >= 229 && recharge == 0 ? winnable(mana-229, hp, b_hp, shield, poison, 5, used+229, !player_turn) : false);
  } else {
    return winnable(mana, hp, b_hp, shield, poison, recharge, used, !player_turn);
  }
}

int main() {
  for (int i = 0; i < 5000; i++) {
    threshold = i;
    if (winnable(500, 50, b_start_hp, 0,0,0,0,true)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << winnable(500, 50, b_start_hp, 0, 0, 0, 0, true) << endl;
  cout << best << endl;
  return 0;
}
