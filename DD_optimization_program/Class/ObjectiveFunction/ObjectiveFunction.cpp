#include "ObjectiveFunction.h"

ObjectiveFunction::ObjectiveFunction(DD dd) : 
graph(dd.get_desition_diagram()), time(std::chrono::duration<double>::zero()), objective_function(nullptr) {
}

void ObjectiveFunction::set_objective_function(AbstractObjective& objective_function) {
    this->objective_function = &objective_function; 
    this->objective_function->assign_graph(graph);
}

ObjectiveStruct ObjectiveFunction::solve_dd() {
    check_if_objective_is_set();
    auto start = chrono::high_resolution_clock::now();
    answer = objective_function->resolve_graph();
    auto end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << endl;
    cout << " '''La respuesta entregada es una lista de 3 valores, donde el primero hace referencia al valor óptimo" <<
        " el segundo es un string que explica el camino que se debe seguir para llegar al óptimo, donde se sigue" <<
        " una estructura arc_x_y(z) donde x es el nodo del que sale el arco y es el nodo al cual entra y z, el valor" <<
        " que posee la variable en ese arco. y el tercero es una lista con los arcos explicados mostrados en el string" <<
        " anterior.'''" << endl;
    return answer;
}

void ObjectiveFunction::check_if_objective_is_set() {
    if (objective_function == nullptr) {
        cout << "No se ha definido una función objetivo" << endl;
        exit(1);
    }
}

string ObjectiveFunction::get_time() {
    return to_string(time.count());
}

ObjectiveStruct ObjectiveFunction::get_the_solution() {
    if (answer.value != -111111) {
        return answer;
    } else {
        cout << "No se ha resuelto el diagrama de decisión" << endl;
        exit(1);
    }
}