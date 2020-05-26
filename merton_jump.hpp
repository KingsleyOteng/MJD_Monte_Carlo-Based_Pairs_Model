//
//  merton_jump.hpp
//  merton_jump_with_diffusion
//
//  Created by Dede Oteng on 24/05/2020.
//

#ifndef merton_jump_hpp
#define merton_jump_hpp

#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>


class merton_jump
{
    
private:

    
   // macro defining array size
   #define         ARRAY_SIZE                              50

    
  // members
  char             parse_input_phrase                       [ARRAY_SIZE];
  char             parsed_string                            [ARRAY_SIZE];
  double           m_epoch_julian_date;
    double          S0;
    double          mean;
    double          std;
    double          kappa;
    double          poisson_mean;
    int             N_samples;
    double          delta_t;
    double          lambda;
    std::string     security;
    
public:

  // constructors  and destructors
     merton_jump();
    ~merton_jump();

    void                      SetDeltaT (double delta_t_in);
    double                    GetDeltaT();

    
    char*                     GetSimpleDateFormatLong          ();
    double                    GetEpochJulianDate               ();
    
    void                      SetS0                            (double S0_in);
    double                    GetS0();
    
    void                      SetMean                          (double mean_in);
    double                    GetMean();
    
    void                      SetSTD                           (double std_in);
    double                    GetSTD();
    
    void                      SetKappa                         (double kappa_in);
    double                    GetKappa();
    
    void                      SetPoissonMean                   (double poisson_mean_in);
    double                    GetPossionMean();
    
    void                      SetMJDModelParameters
            (double S0, double delta_t_in, double mean, double std, double kappa, double poisson_mean, double lambda, int N_samples, std::string name);
    
   std::vector<double>               BuildModel(int samplesize);

};

#endif /* merton_jump_hpp */
