/*----------------------------------------------------------------------
  File     : testfpgrowth.cpp
  Contents : FP-growth algorithm for finding frequent sets
----------------------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "item.h"
#include "fptree.h"
#include "fpgrowth.h"

using namespace std;

int main(int argc, char *argv[])
{
  cout << "FP-growth frequent itemset mining implementation" << endl;
  cout << "by Mukesh Kumar" << endl << endl;


  if(argc < 4){
    cerr << "usage: " << argv[0] << " datafile datatype minsup [output]" << endl;
    cerr << "datatype = 1 for Quest datagenerator binary" << endl;
    cerr << "datatype = 2 for Quest datagenerator ascii" << endl;
    cerr << "datatype = 3 for flat, i.e. all items per transaction on a single line" << endl;
    cerr << "datatype = 4 for ascii version of Quest datagenerator binary" << endl;
  }
  else{
    FPgrowth *fpgrowth = new FPgrowth();

    fpgrowth -> setData(argv[1],atoi(argv[2]));
    fpgrowth -> setMinsup(atoi(argv[3]));
    if(argc==5) fpgrowth -> setOutput(argv[4]);

    clock_t start = clock();
    int added = fpgrowth -> mine();
    cout << added << "\t[" << (clock()-start)/double(CLOCKS_PER_SEC) << "s]" << endl;
    if(argc==5) cout << "Frequent sets written to " << argv[4] << endl;

    delete fpgrowth;
  }

  return 0;
}

