#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_pop_push() {
    vector<int> obj;//创建一个向量存储容器 int
    for(int i=0;i<10;i++) // push_back(elem)在数组最后添加数据
    {
        obj.push_back(i);
        cout<<obj[i]<<",";
    }

    for(int i=0;i<5;i++)//去掉数组最后一个数据
    {
        obj.pop_back();
    }

    cout<<"\n"<<endl;

    for(int i=0;i<obj.size();i++)//size()容器中实际数据个数
    {
        cout<<obj[i]<<",";
    }
}

void test_clear() {
    vector<int> obj;
    for(int i=0;i<10;i++)//push_back(elem)在数组最后添加数据
    {
        obj.push_back(i);
        cout<<obj[i]<<",";
    }

    obj.clear();//清除容器中所以数据
    for(int i=0;i<obj.size();i++)
    {
        cout<<obj[i]<<endl;
    }
}

void test_sort() {
    vector<int>obj;

    obj.push_back(1);
    obj.push_back(3);
    obj.push_back(0);

    sort(obj.begin(),obj.end());//从小到大

    cout<<"从小到大:"<<endl;
    for(int i=0;i<obj.size();i++)
    {
        cout<<obj[i]<<",";
    }

    cout<<"\n"<<endl;

    cout<<"从大到小:"<<endl;
    reverse(obj.begin(),obj.end());//从大到小
    for(int i=0;i<obj.size();i++)
    {
        cout<<obj[i]<<",";
    }
}

void test_visit() {
    //顺序访问
    vector<int>obj;
    for(int i=0;i<10;i++)
    {
        obj.push_back(i);
    }

    cout<<"直接利用数组：";
    for(int i=0;i<10;i++)//方法一
    {
        cout<<obj[i]<<" ";
    }

    cout<<endl;
    cout<<"利用迭代器：" ;
    //方法二，使用迭代器将容器中数据输出
    vector<int>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素
    for(it=obj.begin();it!=obj.end();it++)
    {
        cout<<*it<<" ";
    }
}

void test_matrix() {
    int N=5, M=6;
    vector<vector<int> > obj(N); //定义二维动态数组大小5行
    for(int i =0; i< obj.size(); i++)//动态二维数组为5行6列，值全为0
    {
        obj[i].resize(M);
    }

    for(int i=0; i< obj.size(); i++)//输出二维动态数组
    {
        for(int j=0;j<obj[i].size();j++)
        {
            cout<<obj[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    test_pop_push();

    test_clear();

    test_sort();

    test_visit();

    test_matrix();
    return 0;
}