//
//  main.cpp
//  merton_jump_with_diffusion
//
//  Created by Dede Oteng on 24/05/2020.
//

#include <iostream>
#include <vector>
#include "merton_jump.hpp"
#include "risk_models.hpp"
#include <iostream>

using namespace std;
const double stpsize = 0.00001;

int main(int argc, const char * argv[]) {
   
    // summary
    std::vector<double>  sample1(1000000), sample2(1000000), sample3(1000000);
    double step_size;
    double sample_size;
    double cycles;
    
    // model parameters
    step_size = stpsize;
    sample_size = 1 / step_size;
    cycles = 3;                            // 3 years
    
    // create two instances of class merton_jump
    merton_jump mjd_model1;
    merton_jump mjd_model2;
    merton_jump mjd_model3;
    risk_models* rm = new risk_models();
    
    // set model parameters
    rm->setModel(sample_size, step_size, cycles);
    mjd_model1.
        SetMJDModelParameters(318.89, step_size, 0.002623133, 0.025277755, 3.75, 2, 1, sample_size * cycles, "tesla");
    
    mjd_model2.
        SetMJDModelParameters(137.54, step_size, -0.000662805, 0.018599667, 5.25, 2, 1, sample_size * cycles, "boeing");
    
    mjd_model3.
        SetMJDModelParameters(0.0068, step_size, 0.013160227, 0.364595947, 0.0102, 2, 1, sample_size * cycles, "rllcf");
    
    // start Merton-Jump Diffusion montecarlo
    sample1 = mjd_model1.BuildModel(sample_size);
    sample2 = mjd_model2.BuildModel(sample_size);
    sample3 = mjd_model3.BuildModel(sample_size);

    // finally generqte summary stats; in this case just correlation
    rm->setData(sample1, sample2);
    std::cout << "correlation of sample 1 and sample 2: " << rm->getCorr() << "\n";
    
    rm->setData(sample3, sample2);
    std::cout << "correlation of sample 3 and sample 2: " << rm->getCorr() << "\n";
    
    rm->setData(sample1, sample3);
    std::cout << "correlation of sample 1 and sample 3: " << rm->getCorr() << "\n";
    
    return 0;
}
