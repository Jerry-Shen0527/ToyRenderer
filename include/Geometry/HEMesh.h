#pragma once
#include <utility>

class HalfEdge;

class Vertex {
public:
	// functions ...
private:
	HalfEdge* he;
};

class Edge {
public:
	// functions ...
private:
	HalfEdge* he;
};

class Polygon {
public:
	// functions ...
private:
	HalfEdge* he;
};

class HalfEdge {
public:
	// functions ...
private:
	HalfEdge* next;
	HalfEdge* pair;
	Vertex* origin;
	Edge* edge;
	Polygon* polygon;
};

class HEMesh
{
public:
	HEMesh() {}

private:
};
