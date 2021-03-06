#include "src/grid.h"
#include "src/gridfield.h"
#include "src/array.h"

using namespace GF;

Grid *makeGrid(int scale, string name) {
  CellArray *twocells;
  CellArray *onecells;
  CellArray *zerocells;
  Grid *grid;
  Node triangle[3];
  Node segment[2];
  Node node;

  bool wf;
  int i;
  twocells = new CellArray();
  for (i=0; i<scale/2; i++) {
    triangle[0] = i;
    triangle[1] = i+1;
    triangle[2] = i+2;
    twocells->addCellNodes(triangle, 3);
  }
  //twocells->print();
  //getchar(); 
  onecells = new CellArray();
 for (i=0; i<scale-1; i++) {
    segment[0] = i;
    segment[1] = i+1;
    onecells->addCellNodes(segment, 2);
  }
  //onecells->print();
  
  //getchar(); 
  grid = new Grid(name, 2);
  grid->setImplicit0Cells(scale);
  grid->setKCells(onecells, 1);
  grid->setKCells(twocells, 2);
  //grid->print(0);
  //getchar();
  //printf("foo\n");
  return grid; 
}

Array *makeIntArray(int size,const char *name) {
  Array *arr;
  int data[size];
  int i;

  for (i=0; i<size; i++) {
      data[i] = i*2-10;
  }
  arr = new Array(name, INT);
  arr->copyIntData(data, size);
  return arr;  
}

int main(int argc, char **argv) {

  bool verbose = false;
  // replace this with getopt? jhrg 9/30/11
  if (argc == 2 && strncmp(argv[1], "-v", 2) == 0)
    verbose = true;
  
  Grid *G;
  GridField *GF;
  int k,i;
  Array *data;
  
  G = makeGrid(12, "A");
  k = 0;
  data = makeIntArray(12, "x");

  GF = new GridField(G);
  GF->AddAttribute(k, data);
  if (verbose) cout << GF->GetAttribute(k, "x")->getName() << endl;
  if (verbose) printf("bound\n");
  if (verbose) printf("Valid? %i\n", !GF->notValid());
  //GF->PrintTo(cout, 0);
  //GF->Prune(0);
  //GF->PrintTo(cout, 0);
  GF->Apply("y=x*4", 0);
  if (verbose) GF->print();
}

