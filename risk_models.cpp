//
//  risk_models.cpp
//  merton_jump_with_diffusion
//
//  Created by Dede Oteng on 24/05/2020.
//

#include "risk_models.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <boost/xpressive/xpressive.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include "boost/random.hpp"
#include <boost/random/random_device.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_01.hpp>
#include <boost/random/linear_congruential.hpp>

using namespace boost::math;
using namespace std;

risk_models::risk_models()
    {};

risk_models::~risk_models()
    {};

void                      risk_models::setData(std::vector<double> sample1_in, std::vector<double> sample2_in)
    {
        sample1 = sample1_in;
        sample2 = sample2_in;
    }

// calculate the spearman correlation coefficient
double                    risk_models::getCorr()

{
        double sample_1_mean, sample_2_mean;
        double sx, sy, ssxy, sxx, syy;
    
        sample_1_mean = 0;
        sample_2_mean = 0;
        sx = 0;
        sy = 0;
        sxx = 0;
        syy = 0;
        ssxy = 0;
    
    for (int x=0; x < sample_size; ++x)
        {
            sample_1_mean += sample1[x];
            sample_2_mean += sample2[x];
        }
    
    for (int x=0; x <= sample_size; ++x)
        {
            sx = (sample1[x] - sample_1_mean);
            sy = (sample2[x] - sample_2_mean);
        
            ssxy += sx * sy;
            sxx += sx * sx;
            syy += sy * sy;
        }
    
    return (ssxy / sqrt(sxx * syy));
    }

// set model constants
void                     risk_models::setModel(double sample_size_in, double step_size_in, double cycles_in)
    {
        sample_size = sample_size_in;
        step_size   = step_size_in;
        cycles      = cycles_in;
    };
