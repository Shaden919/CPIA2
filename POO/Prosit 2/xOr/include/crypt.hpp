#include <string>
#include "file.hpp"
using namespace std;

#if !defined(DEF_CRYPT)
#define DEF_CRYPT

class Crypt
{
private:
    string key;
public:
    Crypt(string key);
    ~Crypt();
    void setKey(string key);
    string getKey();
    bool executeXOR(File file,int mode = 1);
};

#endif // DEF_CRYPT
