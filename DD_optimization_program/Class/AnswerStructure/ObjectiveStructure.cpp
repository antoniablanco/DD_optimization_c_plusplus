#include "ObjectiveStructure.h"

ObjectiveStruct::ObjectiveStruct() : value(-111111), path(""), arcs({}) {}

ObjectiveStruct::ObjectiveStruct(int value, string path, vector<Arc*> arcs) : value(value), path(path), arcs(arcs) {}