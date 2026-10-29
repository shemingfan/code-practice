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
        for(int i=0;i < (int)column.size();i++){
            if(column[i] == colname){
                cout << "错误：有重名字段！" << endl;
                return;
            }else{
                column.push_back(colname);
            for(int i=0;i < (int)data.size();i++){
                    data[i].push_back(NULL);
                }
                cout << "已成功创建["<< colname <<"]列。" << endl;
            }
        }
    }
    void deletecolumn(string colname)
    {
        for(int i=0;i < (int)column.size();i++){
            if(column[i] == colname){
                column.erase(column.begin()+i);
                cout << "已成功删除[" << colname << "]列。" << endl;
                return;
            }
        }
        cout << "错误:未找到名为[" << colname << "]的列！"<< endl;
    }
    void insertrecord(vector<string> record)
    {
        if((int)record.size() != (int)column.size()){
            cout <<"错误：记录的输入格式不符!"<< endl;
        }else{
            data.push_back(record);
            cout <<"记录已成功添加。"<< endl;
        }
    }
    void deleterecord(string rowindex)
    {
        if(rowindex>data.size()){
            cout <<"错误：行不存在！"<< endl;
            return;
        }else{
            data.erase(data.begin()+rowindex);
            cout <<"已成功删除第["<< rowindex <<"]行。"<< endl;
        }
    }
    void search(string colindex, string value)
    {
        for(int i=0;i < (int)data.size();i++){
           if(data[i][colindex]==value){
                for(int j=0;i < (int)column.size();j++){
                    cout << setw(15) << left << column[j];
                }
                cout << endl;
                for(int j=0;j < (int)colum.size();j++){
                    cout << setw(15) << lsft << data[i][j];
                }
                cout << endl;
           } 
        }
    }
    void display()
    {
        cout <<"\n----表："<< name <<" ----"<< endl;
        for(int i=0;i < (int)column.size();i++){
            cout << setw(15) << left << column[i];
        }
        cout << endl;
        for(int i=0;i < (int)data.size();i++){
            for(int j = 0;j < (int)column.size();j++){
                cout << setw(15) << left << data[i][j];
            }
            cout << endl;
        }
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