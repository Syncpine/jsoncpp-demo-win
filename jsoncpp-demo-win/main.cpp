#include <iostream>
#include <fstream>

#include "json.h"

using namespace std;


Json::Value CreateRoot();
bool WriteJson(const Json::Value& root, const string& path);
bool ReadJson(Json::Value& root, const string& path);
void PrintJson(const Json::Value& root);


int main()
{
    Json::Value root;
    const string path = "../../jsoncpp-demo-win/out/case.json";

    root = CreateRoot();
    std::cout << "Create json node is OK!" << std::endl;

    WriteJson(root, path);
    std::cout << "Write json node is OK!" << std::endl;

    root.clear();

    ReadJson(root, path);
    std::cout << "Read json node is OK!" << std::endl;

    PrintJson(root);
    std::cout << "Print json node is OK!" << std::endl;

    root.clear();
    return 0;
}

Json::Value CreateRoot()
{
    Json::Value root;

    root["id"] = 1;
    root["Name"] = "Syncpine";

    // root["Language"].insert(0, "zh-cn");
    // root["Language"].insert(1, "en-us");

    root["Language"].append("zh-cn");
    root["Language"].append("en-us");

    return root;
}

bool WriteJson(const Json::Value& root, const string& path)
{
    ofstream ofs(path);

    ofs << root;

    ofs.close();

    return true;
}

bool ReadJson(Json::Value& root, const string& path)
{
    ifstream ifs(path);

    ifs >> root;

    ifs.close();

    return true;
}

void PrintJson(const Json::Value& root)
{
    cout << root.toStyledString() << endl;
}

