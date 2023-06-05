#ifndef CALCULATION_H
#define CALCULATION_H

#include "storage_type.h"

class calculation {
    public:
        virtual void compute(storage_type& data);
};

class average_calculation : public calculation {
    public:
        void compute(storage_type& data)override;
};

class rolling_average_calculation : public calculation {
    public:
        void compute(storage_type& data)override;
};
#endif //CALCULATION_H