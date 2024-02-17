#include "ObjectiveStructure.h"

template <typename T>
ObjectiveStruct<T>::ObjectiveStruct() : value(-111111), path(""), arcs({}) {}

template <typename T>
ObjectiveStruct<T>::ObjectiveStruct(int value, string path, vector<Arc<T>*> arcs) : value(value), path(path), arcs(arcs) {}
