#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
class table
{
public:
    string tablename;
    vector<string> column;
    vector<vector<string>> data;
    table(string name)
    {
        tablename = name;
    }
    void addcolumn(string colname)
    {
    }
    void deletecolumn(string colname)
    {
    }
    void insertrecord(vector<string> record)
    {
    }
    void deleterecord(string rowindex)
    {
    }
    void search(string colindex, string value)
    {
    }
    void display()
    {
    }
};
class database
{
private:
    vector<table> tables;

public:
    table *gettable(string name)
    {
        for (int i = 0; i < (int)tables.size(); i++)
        {
            if (tables[i].tablename == name)
            {
                return &tables[i];
            }
        }
        return NULL;
    }
    void createdatabase(string name, vector<string> cols)
    {
        if (gettable(name) != NULL)
        {
            cout << "表已经存在！" << endl;
            return;
        }
        table newtable(name);
        for (int i = 0; i < (int)cols.size(); i++)
        {
            newtable.addcolumn(cols[i]);
        }
        tables.push_back(newtable);
        cout << "表[" << name << "]已创建成功！" << endl;
    }
    void deletedatabase(string name)
    {
        if (gettable(name) == NULL)
        {
            cout << "表不存在！" << endl;
            return;
        }
        else
        {
            for (int i = 0; i < (int)tables.size(); i++)
            {
                if (tables[i].tablename == name)
                {
                    tables.erase(tables.begin() + i);
                    cout << "表[" << name << "]已删除成功！" << endl;
                    return;
                }
            }
        }
    }
};
int main()
{

    return 0;
}