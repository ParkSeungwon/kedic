#include<fstream>
#include<iostream>
#include<map>
#include"token.h"
#include"server.h"
using namespace std;

map<string, string> dictionary;
string dict(string s) { 
  if(dictionary.find(s) != dictionary.end()) return dictionary[s]; 
  else return "not found";
}
class Sv : public Server
{
public:
  Sv(int port) : Server(port) {}
protected:
  int get_full_length(string s) { return s.size(); }
};

Sv sv{4000};

int main()
{
  string s;
  Tokenizer tok;
  tok.separate("\t");
  {
    ifstream f{"kengdic.tsv"};
    while(getline(f, s)) {
      auto v = tok.tokenize(s);
      dictionary[v[1]] = v[2] + '\n' + v[3] + '\n' + v[4];
    }
  }
  sv.nokeep_start(dict);
}
