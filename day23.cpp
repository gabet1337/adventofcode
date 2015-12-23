#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct instr {
  string op;
  string reg;
  int rel;
  instr(string o, string r, int re) : op(o), reg(r), rel(re) {}
};

int main() {
  vector<instr> instructions;
  string o,r;
  int re;
  while (cin >> o) {
    if (o == "jmp") {
      cin >> re;
      instructions.push_back(instr(o,"", re));
    } else if (o == "hlf" || o == "tpl" || o == "inc") {
      cin >> r;
      instructions.push_back(instr(o,r,0));
    } else {
      cin >> r; r.pop_back();
      cin >> re;
      instructions.push_back(instr(o,r,re));
    }
  }

  int pos = 0, a = 1, b = 0;
  while (pos < instructions.size()) {
    string op = instructions[pos].op;
    if (op == "hlf") {
      if (instructions[pos].reg == "a") a/=2;
      else b/=2;
      pos++;
    } else if (op == "tpl") {
      if (instructions[pos].reg == "a") a*=3;
      else b*=3;
      pos++;
    } else if (op == "inc") {
      if (instructions[pos].reg == "a") a++;
      else b++;
      pos++;
    } else if (op == "jmp") {
      pos+=instructions[pos].rel;
    } else if (op == "jie") {
      int rel = instructions[pos].rel;
      if (instructions[pos].reg == "a" && a%2 == 0) pos+=rel;
      else if (instructions[pos].reg == "b" && b%2 == 0) pos+=rel;
      else pos++;
    } else if (op == "jio") {
      int rel = instructions[pos].rel;
      if (instructions[pos].reg == "a" && a == 1) pos+=rel;
      else if (instructions[pos].reg == "b" && b == 1) pos+=rel;
      else pos++;
    }
  }
  cout << b << endl;

  return 0;
}
