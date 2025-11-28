#if !defined(DEF_UNIQUELIST)
#define DEF_UNIQUELIST

#include <unordered_map>
#include <vector>
using namespace std;

class UniqueList
{
private:
    vector<int> list;
    unordered_map<int,bool> dico;
public:
    UniqueList();
    ~UniqueList();
    bool hasValue(int val) const;
    bool add(int val);
    bool remove(int val);
    void print() const;
};


#endif // DEF_UNIQUELIST
