#include <cassert>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;

int main()
{
	PolyLine pl;

	pl.AddPoint(4,5);
	pl.AddPoint(6, 6);
	pl.AddPoint(1.2, 5.4);
	PolyLine p3(pl);
	p3.Printf();
	
	return 0;
}