#include<iostream>
#include"server.h"
#include"option.h"
using namespace std;

class Cl : public Client
{
public:
  Cl(string ip, int port) : Client(ip, port) {}
protected:
  int get_full_length(string s) { return s.size();}
};


int main(int ac, char **av)
{
	CMDoption co
	{ {"host", "host ip address", "192.168.0.10"}
	, {"port", "dictionary server port", 4000}
  , {"word", "korean word to search in kor-eng dictionary", "안녕하세요"}
	};
	if(!co.args(ac, av)) return 0;

  Cl cl{co.get<const char*>("host"), co.get<int>("port")};
  cl.send(co.get<const char*>("word"));
  cout << *cl.recv() << endl;
}
