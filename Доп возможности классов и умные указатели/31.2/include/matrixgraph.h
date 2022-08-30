#pragma once
#include <vector>
#include "igraph.h"

class MatrixGraph : public IGraph
{
    const int c_ratio;
    size_t _size;
    size_t _capacity;
    bool** _graph;

    struct Quantity_cache
    {
        mutable bool status;
        mutable size_t vertices;
    } cache;

    void resize(size_t new_size);

public:
    MatrixGraph(int capacity = 5);

    MatrixGraph(IGraph *oth);

    MatrixGraph(const MatrixGraph &matrix_g);

    MatrixGraph& operator= (const MatrixGraph &matrix_g);

    ~MatrixGraph();

    void AddEdge(size_t from, size_t to) override;

    int VerticesCount() const override;

    void ShowGraph() const override;

    void GetNextVertices(size_t vertex, std::vector<size_t> &vertices) const override;

    void GetPrevVertices(size_t vertex, std::vector<size_t> &vertices) const override;

    int SizeMatrix() const {return _size;}

    int CapacityMatrix() const {return _capacity;}
};