//
// Created by hanz on 21/9/26.
//
//elegimos un .h o cabezera(header) por que en este se puede implementar?? para no llenarnos de archivos y porque
//vamos a trabajar con container stakc o etc , la funcion de este es imprimir cualqueira containers
//para que el container que va a entrar va a imprmir esa funcion
//q tal si pnemos 500 objetos no vamos averlo
//indicamos val a 15 para ver de 15 en 15 uno debajo al otro
//epl:numero de objetos por liena                                         conteneder::array , etc
//cuando epl es 0 no hace nd solo va a imprimir
//si no es 0 tengo que hacer por ejemplo si tengo 50 eleentos  con este .h hago que se vean de 10 en 100 por liena
//y cuando llego al decimo un salto de linea
//const cahr es otra foamr de iscrbir un sitrng y se pasa como const para que no cambie y se pasa com puntero par que guarde el contenido

#ifndef INC_2026_II_SW305_HELLPERS_H
#define INC_2026_II_SW305_HELLPERS_H

#include <format>
#include <iostream>
#include <map>

template <typename T>
static void print_container(const char *msg, T &container, size_t epl_max = 0) {
    if (msg != nullptr) {
        std::cout << msg << std::endl;
    }
    size_t epl{};
    size_t num_elem{};
    //se  le pone auto por que no sabemos que tipo de objeto entra ya que
    //puede entrar cualquier tipo de objeto al container o plantilla?



    for (const auto &e : container) {
     ++num_elem;
        std::cout << e << " ";
        if (epl_max != 0) {
            if (++epl % epl_max == 0) {
                std::cout << std::endl;
            }
        }
    }
    if (num_elem == 0) {
        std::cout << "<empty>" << std::endl;
    }
    std::cout << std::endl;
}

// Print each multimap entry as a (key, value) pair.
// Set epl_max to 0 to print all pairs on one line.
template <typename T, typename U>
void print_multimap(const char* msg,const std::multimap<T, U>& container, size_t epl_max = 0) {

    // Print the message if one was provided.
    if (msg != nullptr) {
        std::cout << msg << std::endl;
    }

    // Indicate that the multimap is empty and stop printing.
    if (container.empty()) {
        std::cout << "<empty>" << std::endl;
        return;
    }

    // Count the pairs printed to control line breaks.
    size_t epl{0};

    for (const auto& [key, value] : container) {
        std::cout << std::format("({}, {}) ", key, value) ;

        // Start a new line after each group of epl_max pairs.
        if (epl_max != 0) {
            if (++epl % epl_max == 0) {
                std::cout << std::endl;
            }
        }
    }

    // End the final line unless the loop already ended it.
    if (epl_max == 0 || container.size() % epl_max != 0) {
        std::cout << std::endl;
    }
}


// Copy the map entries into a multimap to reuse print_multimap.
template <typename T, typename U>
void print_map(const char *msg, const std::map<T, U> &container, size_t epl_max =0){

    std::multimap<T, U> map(container.begin(), container.end());

    print_multimap(msg, map, epl_max);
}

#endif //INC_2026_II_SW305_HELLPERS_H
