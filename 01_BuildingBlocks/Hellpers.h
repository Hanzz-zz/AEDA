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

#include <iostream>
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
#endif //INC_2026_II_SW305_HELLPERS_H
