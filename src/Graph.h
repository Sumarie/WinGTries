/* -------------------------------------------------
      _       _     ___
 __ _| |_ _ _(_)___/ __| __ __ _ _ _  _ _  ___ _ _
/ _` |  _| '_| / -_)__ \/ _/ _` | ' \| ' \/ -_) '_|
\__, |\__|_| |_\___|___/\__\__,_|_||_|_||_\___|_|
|___/

gtrieScanner: quick discovery of network motifs
Released under Artistic License 2.0
(see README and LICENSE)

Pedro Ribeiro - CRACS & INESC-TEC, DCC/FCUP

----------------------------------------------------
Partially Abstract Base Graph Class

Last Update: 11/02/2012
---------------------------------------------------- */

#ifndef _GRAPH_
#define _GRAPH_

#include "Common.h"

typedef enum{DIRECTED, UNDIRECTED} GraphType;

class Graph {
 public:

         Graph();
     Graph(int n);
     Graph(bool a, Graph &g);
  virtual void   _createGraph(int num_nodes);
  virtual void  _init();
  virtual void _delete();

  int _num_nodes;
  int _num_edges;

  int *_in;
  int *_out;
  int *_num_neighbours;

  int * _in_ds;
  int * _out_ds;
  iPair * _io_ds;

  int **_adjM;
  list<pair<int,int> > * _adjL;
  list<pair<int,int> > * _adjLI;
  int  **_array_neighbours;
  vector<int> *_adjOut;
  vector<int> *_adjIn;
  list<int> *_neighbours;

    void addEdge(int a, int b, int c);
  void rmEdge(int a, int b, int c);
  void rmEdgesNode(int v);
  int readFile(char *file_name, bool undir);

  virtual bool **adjacencyMatrix() = 0;

  virtual ~Graph();

  virtual void createGraph(int n, GraphType t) = 0; // create graph with n nodes
                                                    // and type 't'

  virtual GraphType type() = 0;           // Graph Type

  virtual void zero() = 0;                // remove all connections

  virtual void addEdge(int a, int b) = 0; // add edge from a to b
  virtual void rmEdge(int a, int b)  = 0; // remove edge from a to b

//  virtual int numNodes()  = 0; // Number of nodes in graph
//  virtual int numEdges()  = 0; // Number of edges in graph

  virtual bool hasEdge(int a, int b) = 0; // Edge between a and b?
  virtual bool isConnected(int a, int b) = 0;  // Edge (a,b) or (b,a)?
//
//  virtual int nodeOutEdges(int a) = 0;    // nr Edges from node a
//  virtual int nodeInEdges(int a) = 0;     // nr Edges to   node a
  virtual int numNeighbours(int a) = 0;   // Nr Neighbours of node a

  virtual void sortNeighbours() = 0;       // All neighbours sorted in increasing order (sort vectors)
  virtual void sortNeighboursArray() = 0;  // All neighbours sorted in increasing order (sort arrays)

  virtual void makeArrayNeighbours() = 0;  // Create arrays of neighbours and discard vectors
  virtual void makeVectorNeighbours() = 0; // Create vectors of neighbours and discard arrays

  virtual vector<int> *neighbours(int a) = 0; // Neighbours of node a
  virtual int **matrixNeighbours() = 0;            // Neighbours of node a in array form
  virtual int *arrayNeighbours(int a) = 0;         // Neighbours of node a in array form
  virtual int *arrayNumNeighbours() = 0;           // Numbers of neighbours in array form
  virtual vector<int> *outEdges(int a) = 0;   // Outgoing edges of node a
  virtual vector<int> *inEdges(int a) = 0;    // Ingoing edges of node a

  virtual int numEdges()             {return _num_edges;}
  virtual int numNodes()             {return _num_nodes;}
   int getEdge(int i, int j)      {return _adjM[i][j];}
  list <iPair> *getEdgesList(int i)    {return &_adjL[i];}
  list <iPair> *getEdgesInList(int i)  {return &_adjLI[i];}
  list <int>   *getNeighbours(int i)   {return &_neighbours[i];}
   bool hasConn(int i, int j)     {return _adjM[i][j];}
   bool hasConnDual(int i, int j) {return (_adjM[i][j] || _adjM[j][i]);}
  virtual int nodeOutEdges(int i)=0;
 virtual  int nodeInEdges(int i)         {return _in[i];}
 virtual  int nodeIOEdges(int i)         {return _out[i]+_in[i];}

   int *inDegreeSequence()        {return _in_ds;}
   int *outDegreeSequence()       {return _out_ds;}
   iPair *ioDegreeSequence()      {return _io_ds;}

//  void vecEdges(vEdges &v);
  list<iPair> adjL(int v);

//  int *makeInDegreeSequence();
//  int *makeOutDegreeSequence();
//  iPair *makeIODegreeSequence();



  /* --------------------- */

};

#endif
