#include <string>

using namespace std;

#if !defined(DEF_FILE)
#define DEF_FILE

class File
{
private:
    string name;
    string path;
public:
    File(const string& name,const string& path);
    ~File();
    void setName(string name);
    void setPath(string path);
    string getName();
    string getPath();
    string read() const;
    string readBin() const;
    void write(string ligne) const;
    void writeBin(string ligne) const;
};


#endif // DEF_FILE
