//
//  risk_models.hpp
//  merton_jump_with_diffusion
//
//  Created by Dede Oteng on 24/05/2020.
//

#ifndef risk_models_hpp
#define risk_models_hpp

#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>

using namespace std;
class risk_models
{
    
private:

    // members
   

    std::vector<double>  sample1;
    std::vector<double>  sample2;
    double               sample_size;
    double               step_size;
    double               cycles;
    double               correl;
    
public:

  // constructors  and destructors
     risk_models();
    ~risk_models();

    void                    setModel(double sample_size_in, double step_size_in, double cycles_in);
    void                    setData(std::vector<double> ssample1_in, std::vector<double> ssample2_in);
    double                  getCorr();
    
};

#endif /* risk_models_hpp */

