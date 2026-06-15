#pragma once
#include <vector>
#include <map>

template<class V, class W, bool Direction> 
class Graph
{
private:
	vector<V> _vertexs; //顶点集合
	map<V, int> _indexMap; //顶点映射下标
	vector<vector<w>> _maxrix;
};