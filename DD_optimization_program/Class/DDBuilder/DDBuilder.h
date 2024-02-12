#ifndef DD_OPTIMIZATION_PROGRAM_DDBUILDER_H
#define DD_OPTIMIZATION_PROGRAM_DDBUILDER_H

#include "AbstractDDBuilder.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Clase concreta que hereda de AbstractDDBuilder, genera la construcción básica de un diagrama de decisión.
 */

class DDBuilder: public AbstractDDBuilder {
    public:
        /**
         * @brief Constructor de la clase DDBuilder.
         * @param problem Problema de optimización que se desea resolver.
         */
        DDBuilder(AbstractProblem& problem);
    private:
        /**
         * @brief Función específica de la capa para la construcción de diagramas de decisión.
         *        No es implementada
         */
        void specificLayerFunction() override;

        /**
         * @brief Función específica final para la construcción de diagramas de decisión.
         *        No es implementada
         */
        void specific_final_function() override;
};

#endif //DD_OPTIMIZATION_PROGRAM_DDBUILDER_H