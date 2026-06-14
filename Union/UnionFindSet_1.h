#pragma once

#include <vector>
#include <map>

template<class T>
class UnionFindSet
{
public:
    UnionFindSet(const T* a, size_t n)
    {
        for (size_t i = 0; i < n; i++)
        {
            _a.push_back(a[i]);
            _indexMap[a[i]] = i;
            _parent.push_back(i);   // 初始每个元素自己是一个集合
        }
        _setCount = n;
    }

    //template<class T>
    //class UnionFindSet
    //{
    //public:
    //    UnionFindSet(const T* a, size_t n)
    //    {
    //        for (size_t i = 0; i < n; i++)
    //        {
    //            _a.push_back(a[i]);
    //            _indexMap[a[i]] = i;
    //        }
    //    }
    //
    //private:
    //    vector<T> _a;             //编号找人
    //    map<T, int> _indexMap;    //人找编号
    //};

    // 查找根（带路径压缩）
    int FindRoot(int index)
    {
        if (index < 0 || index >= (int)_parent.size())
            return -1;

        // 路径压缩：把沿途所有结点直接挂到根上
        if (_parent[index] != index)
            _parent[index] = FindRoot(_parent[index]);

        return _parent[index];

        //return _parent[index] == index ? index : _parent[index] = FindRoot(_parent[index]);
    }

    // 根据值查找根
    int FindRoot(const T& val)
    {
        auto it = _indexMap.find(val);
        if (it == _indexMap.end())
            return -1;
        return FindRoot(it->second);
    }

    // 合并两个元素所在的集合（按秩合并）
    void Union(int index1, int index2)
    {
        int root1 = FindRoot(index1);
        int root2 = FindRoot(index2);

        if (root1 == root2 || root1 == -1 || root2 == -1)
            return;

        // 按秩合并：小集合挂到大集合下面
        if (_rank[root1] < _rank[root2])
        {
            _parent[root1] = root2;
        }
        else if (_rank[root1] > _rank[root2])
        {
            _parent[root2] = root1;
        }
        else
        {
            _parent[root2] = root1;
            _rank[root1]++;
        }

        _setCount--;
    }

    // 根据值合并
    void Union(const T& v1, const T& v2)
    {
        int i1 = GetIndex(v1);
        int i2 = GetIndex(v2);
        Union(i1, i2);
    }

    // 判断两个元素是否在同一个集合
    bool IsSameSet(int index1, int index2)
    {
        int root1 = FindRoot(index1);
        int root2 = FindRoot(index2);

        if (root1 == -1 || root2 == -1)
            return false;

        return root1 == root2;
    }

    bool IsSameSet(const T& v1, const T& v2)
    {
        return FindRoot(v1) == FindRoot(v2);
    }

    // 当前集合个数
    int Count() const
    {
        return _setCount;
    }

private:
    int GetIndex(const T& val)
    {
        auto it = _indexMap.find(val);
        if (it == _indexMap.end())
            return -1;
        return it->second;
    }

private:
    std::vector<T>      _a;         // 编号 → 值
    std::map<T, int>    _indexMap;  // 值 → 编号
    std::vector<int>    _parent;    // 父结点索引（并查集核心）
    std::vector<int>    _rank;      // 秩（按秩合并用）
    int                 _setCount;  // 当前集合个数
};
