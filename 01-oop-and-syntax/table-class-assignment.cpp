#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==================== 表类 ====================
class Table
{
public:
    string tableName;            // 表名
    vector<string> columns;      // 表头（动态数组存列名）
    vector<vector<string> > data; // 数据（二维动态数组，存所有行）

    // 构造函数
    Table(string name)
    {
        tableName = name;
    }

    // 1. 修改表结构：添加字段
    void addColumn(string colName)
    {
        columns.push_back(colName);
        // 遍历每一行，给已有的行末尾补一个 "NULL"
        for (int i = 0; i < data.size(); i++)
        {
            data[i].push_back("NULL");
        }
        cout << "字段 [" << colName << "] 已添加。" << endl;
    }

    // 2. 修改表结构：删除字段
    void deleteColumn(string colName)
    {
        int colIndex = -1;
        // 找到列名对应的索引
        for (int i = 0; i < columns.size(); i++)
        {
            if (columns[i] == colName)
            {
                colIndex = i;
                break;
            }
        }

        if (colIndex == -1)
        {
            cout << "错误：找不到字段 " << colName << endl;
            return;
        }

        // 删除表头
        columns.erase(columns.begin() + colIndex);
        // 删除每一行对应的数据
        for (int i = 0; i < data.size(); i++)
        {
            data[i].erase(data[i].begin() + colIndex);
        }
        cout << "字段 [" << colName << "] 已删除。" << endl;
    }

    // 3. 添加记录
    void insertRecord(vector<string> record)
    {
        if (record.size() != columns.size())
        {
            cout << "错误：输入的数据列数不匹配！" << endl;
            return;
        }
        data.push_back(record);
        cout << "记录添加成功！" << endl;
    }

    // 4. 删除记录
    void deleteRecord(int rowIndex)
    {
        if(rowIndex<0 || rowIndex >= data.size()){
        	cout<<"错误：没有第 "<<rowIndex<<"行！"<<endl;
			return; 
		} 
		data.erase(data.begin()+rowIndex);
        cout << "成功删除了第 " << rowIndex << " 行。" << endl;
    }

    // 5. 查询记录
    void queryRecord(int colIndex, string value)
    {
        cout << "\n--- 查询结果 ---" << endl;
        for (int i = 0; i < columns.size(); i++)
        {
            cout << setw(15) << left << columns[i];
        }
        cout << endl;

        bool found = false;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i][colIndex] == value)
            {
                for (int j = 0; j < data[i].size(); j++)
                {
                    cout << setw(15) << left << data[i][j];
                }
                cout << endl;
                found = true;
            }
        }
        if (!found)
            cout << "未找到匹配的记录。" << endl;
    }

    // 6. 显示全表
    void display()
    {
        cout << "\n--- 表: " << tableName << " ---" << endl;
        for (int i = 0; i < columns.size(); i++)
        {
            cout << setw(15) << left << columns[i];
        }
        cout << endl;
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < data[i].size(); j++)
            {
                cout << setw(15) << left << data[i][j];
            }
            cout << endl;
        }
    }
};

// ==================== 数据库类 ====================
class Database
{
private:
    vector<Table> tables; // 核心：用一个 vector 存所有的表，完美替代 map！

public:
    // 找表函数（返回指针）
    Table *getTable(string name)
    {
        // 遍历 vector 查找表
        for (int i = 0; i < tables.size(); i++)
        {
            if (tables[i].tableName == name)
            {
                return &tables[i]; // 找到了，返回这张表的指针
            }
        }
        return NULL; // 没找到，返回空指针
    }

    // 创建表
    void createTable(string name, vector<string> cols)
    {
        if (getTable(name) != NULL)
        {
            cout << "错误：表已存在！" << endl;
            return;
        }
        Table newTable(name); // 创建新表
        for (int i = 0; i < cols.size(); i++)
        {
            newTable.addColumn(cols[i]); // 循环添加列名
        }
        tables.push_back(newTable); // 把表存进数据库的 vector 里
        cout << "表 [" << name << "] 创建成功！" << endl;
    }

    // 删除表
    void dropTable(string name)
    {
        for (int i = 0; i < tables.size(); i++)
        {
            if (tables[i].tableName == name)
            {
                tables.erase(tables.begin() + i); // 从 vector 中删掉这张表
                cout << "表 [" << name << "] 已删除！" << endl;
                return;
            }
        }
        cout << "错误：找不到表！" << endl;
    }
};

// ==================== 主函数 ====================
int main()
{
    Database db;
    int choice;

    while (true)
    {
        cout << "\n======== 简易数据库管理系统 ========" << endl;
        cout << "/==============\\" << endl;
		cout << "||1. 创建表格 ||" << endl;
        cout << "||2. 删除表格 ||" << endl;
        cout << "||3. 增加字段 ||" << endl;
        cout << "||4. 删除字段 ||" << endl;
        cout << "||5. 添加记录 ||" << endl;
        cout << "||6. 删除记录 ||" << endl;
        cout << "||7. 查询信息 ||" << endl;
        cout << "||8. 显示全表 ||" << endl;
        cout << "||0. 退出系统 ||" << endl;
        cout << "\\==============/" << endl;
        cout << "====================================" << endl;
        cout << "|请输入你的选择 (0-8): ";
        cin >> choice;

        if (choice == 0)
            break;

        string tbName;
        Table *tb = NULL; // 定义指针，准备接收找表的返回值

        switch (choice)
        {
        case 1:
        {
            cout << "请输入表名: ";
            cin >> tbName;
            int colCount;
            cout << "请输入列数: ";
            cin >> colCount;
            vector<string> cols;
            for (int i = 0; i < colCount; i++)
            {
                string c;
                cout << "输入第" << i + 1 << "列列名: ";
                cin >> c;
                cols.push_back(c);
            }
            db.createTable(tbName, cols);
            break;
        }
        case 2:
            cout << "请输入要删除的表名: ";
            cin >> tbName;
            db.dropTable(tbName);
            break;
        case 3:
        {
            cout << "请输入表名: ";
            cin >> tbName;
            tb = db.getTable(tbName); // 用指针接收
            if (tb == NULL)
            {
                cout << "表不存在！" << endl;
                break;
            }
            string colName;
            cout << "输入新字段名: ";
            cin >> colName;
            tb->addColumn(colName); // 通过指针调用函数
            break;
        }
        case 4:
        {
            cout << "请输入表名: ";
            cin >> tbName;
            tb = db.getTable(tbName);
            if (tb == NULL)
            {
                cout << "表不存在！" << endl;
                break;
            }
            string colName;
            cout << "输入要删除的字段名: ";
            cin >> colName;
            tb->deleteColumn(colName);
            break;
        }
        case 5:
        {
            cout << "请输入表名: ";
            cin >> tbName;
            tb = db.getTable(tbName);
            if (tb == NULL)
            {
                cout << "表不存在！" << endl;
                break;
            }

            vector<string> newRow;
            cout << "请依次输入数据：" << endl;
            for (int i = 0; i < tb->columns.size(); i++)
            {
                string val;
                cout << tb->columns[i] << ": ";
                cin >> val;
                newRow.push_back(val);
            }
            tb->insertRecord(newRow);
            break;
        }
        case 6:
        {
            cout << "请输入表名: ";
            cin >> tbName;
            tb = db.getTable(tbName);
            if (tb == NULL)
            {
                cout << "表不存在！" << endl;
                break;
            }
            if(tb->data.size()==0){
                cout << "表为空！" << endl;
                break;
            }
            int rowIndex;
            cout << "第几行删除(0到" << tb->data.size() - 1 << "): ";
            cin >> rowIndex;
            tb->deleteRecord(rowIndex);
            break;
        }
        case 7:
        {
            cout << "请输入表名: ";
            cin >> tbName;
            tb = db.getTable(tbName);
            if (tb == NULL)
            {
                cout << "表不存在！" << endl;
                break;
            }

            int colIdx;
            string val;
            cout << "按第几列查询(0到" << tb->columns.size() - 1 << "): ";
            cin >> colIdx;
            cout << "查询的值是: ";
            cin >> val;
            tb->queryRecord(colIdx, val);
            break;
        }
        case 8:
            cout << "请输入表名: ";
            cin >> tbName;
            tb = db.getTable(tbName);
            if (tb == NULL)
            {
                cout << "表不存在！" << endl;
                break;
            }
            tb->display();
            break;
        default:
            cout << "输入错误！" << endl;
        }
    }
    return 0;
}
