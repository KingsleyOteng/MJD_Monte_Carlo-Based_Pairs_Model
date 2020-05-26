//
//  merton_jump.cpp
//  merton_jump_with_diffusion
//
//  Created by Dede Oteng on 24/05/2020.
//

#include "merton_jump.hpp"
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

merton_jump::merton_jump()
    {};

merton_jump::~merton_jump()
    {};

void                      merton_jump::SetDeltaT (double delta_t_in)        // set delta constant
    { delta_t = delta_t_in;}

double                    merton_jump::GetDeltaT()                          // get delta constant
    { return delta_t;}

void                      merton_jump::SetS0 (double S0_in)                 // set starting variable
    { S0 = S0_in;}

double                    merton_jump::GetS0()                              // get starting variable
    { return S0;}

void                      merton_jump::SetMean (double mean_in)             // mean
    {mean = mean_in;};

double                    merton_jump::GetMean()
    {return mean;};

void                      merton_jump::SetSTD (double std_in)               // std
    {std = std_in;};

double                    merton_jump::GetSTD()
    {return std;};

void                      merton_jump::SetKappa(double kappa_in)            // kappa
    {kappa = kappa_in;};

double                    merton_jump::GetKappa()
    {return kappa;}

void                      merton_jump::SetPoissonMean(double poisson_mean_in) // generate Poisson details
    {poisson_mean = poisson_mean_in;};

double                    merton_jump::GetPossionMean()
    {return poisson_mean;}

void                      merton_jump::SetMJDModelParameters    
 (double S0_in, double delta_t_in, double mean_in, double std_in, double kappa_in, double poisson_mean_in, double lambda_in, int N_samples_in, std::string security_in)
{
    // set model parameters
    S0 = S0_in;
    mean = mean_in;
    delta_t = delta_t_in;
    std = std_in;
    kappa = kappa_in;
    poisson_mean = poisson_mean_in;
    lambda = lambda_in;
    N_samples = N_samples_in;
    security = security_in;
}

std::vector<double>                   merton_jump::BuildModel(int sample_size)
{
        std::vector<double>                         ts(10000000);
        double                                      Value;
        int                                         n = 0;
        boost::random::uniform_int_distribution<>   rnd_dist;
        std::default_random_engine                  generator;
        std::poisson_distribution<int>              distribution(4.1);
        int                                         number = distribution(generator);
    
 
    Value = log(S0);
        for (int n = 0; n < N_samples; ++n)
        {
            // generate two random uniform variables
            boost::minstd_rand intgen;
            boost::uniform_01<boost::minstd_rand> gen(intgen);
            boost::minstd_rand intgen2;
            boost::uniform_01<boost::minstd_rand> gen2(intgen2);
            
            // generate a poisson distribution
            std::poisson_distribution<int> distribution(poisson_mean);
            int number = distribution(generator);
            double eta = number/poisson_mean;
            
            // determine whether a jump has occured
            if (eta > kappa)
                {
                    Value = Value + (((mean - (std * std)/2)*delta_t) + + std  * (gen() - 0.5) * sqrt ( delta_t )) + (gen2()-0.5)*Value*0.10;
                }
            else
                {
                    Value = Value + (((mean - (std * std)/2)*delta_t) + + std  * (gen() - 0.5) * sqrt ( delta_t ));
                }
            
            ts[n+1] = (Value);
        }
             
    
    return ts;
}
