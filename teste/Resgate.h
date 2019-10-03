#ifndef RESGATE_H
#define RESGATE_H

#include <robo_hardware2.h>
#include "Garra.h"

class Resgate: public Garra {
    private :
        Garra garra;
       
    public :
        Resgate ();
       	void alinhar ();
        void procurarVitima();
        void abrirGarra();
        void fecharGarra();
        void salvarVitima();
};

#endif
