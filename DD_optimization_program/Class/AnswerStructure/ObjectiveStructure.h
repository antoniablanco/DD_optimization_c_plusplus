
#ifndef DD_OPTIMIZATION_PROGRAM_OBJECTIVESTRUCTURE_H
#define DD_OPTIMIZATION_PROGRAM_OBJECTIVESTRUCTURE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

#include "Graph.h"
#include "Arc.h"

using namespace std;

/**
 * @brief Estructura para almacenar información sobre un objetivo en el programa de optimización.
 */

struct ObjectiveStruct {
    int value; /**< Valor del objetivo. */
    string path; /**< Ruta en formato string explicando el camino que obtiene como resultado el value */
    vector<Arc*> arcs; /**< Objetos arcos en el mismo orden que el path */

    /**
     * @brief Constructor predeterminado. Inicializa los valores predeterminados (-111111, "", {}).
     */
    ObjectiveStruct();

    /**
     * @brief Constructor con parámetros.
     * @param value Valor obtenido del objetivo.
     * @param path Ruta en formato string explicando el camino que obtiene como resultado el value.
     * @param arcs Objetos arcos en el mismo orden que el path.
     */
    ObjectiveStruct(int value, string path, vector<Arc*> arcs);
};

#endif //DD_OPTIMIZATION_PROGRAM_OBJECTIVESTRUCTURE_H