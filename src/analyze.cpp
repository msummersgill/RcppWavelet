#include <RcppArmadillo.h>
#include "wavelet_all.hpp"

#define USE_ARMA
using namespace Rcpp;
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
Rcpp::List analyze(std::vector<double> x,
                             float bands_per_octave = 8,
                             float frequency_min = 0.001953125,
                             float frequency_max = 0.5,
                             float samplerate_hz = 1,
                             std::string use_family = "MORLET") {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  std::size_t numbands(cwt.size());
  
  cwt.setAttribute("family",use_family);
  cwt.reset();
  arma::cx_mat scalogram = cwt.process(x);
  //std::vector<double> periods = cwt.scales;
  std::vector<double> frequencies = cwt.frequencies;
  arma::vec periods = 1/arma::conv_to<arma::vec>::from(frequencies); 
  
  return Rcpp::List::create(Rcpp::Named("scalogram")=scalogram,
                            Rcpp::Named("periods")=periods);
}

// [[Rcpp::export]]
Rcpp::List analyzeParallel(std::vector<double> x,
                             float bands_per_octave = 8,
                             float frequency_min = 0.001953125,
                             float frequency_max = 0.5,
                             float samplerate_hz = 1,
                             int cores = 1,
                             std::string use_family = "MORLET") {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  std::size_t numbands(cwt.size());
  cwt.setAttribute("family",use_family);
  cwt.reset();
  arma::cx_mat scalogram = cwt.processParallel(x, cores);
  //std::vector<double> periods = cwt.scales;
  std::vector<double> frequencies = cwt.frequencies;
  arma::vec periods = 1/arma::conv_to<arma::vec>::from(frequencies); 
  
  return Rcpp::List::create(Rcpp::Named("scalogram")=scalogram,
                            Rcpp::Named("periods")=periods);
}
