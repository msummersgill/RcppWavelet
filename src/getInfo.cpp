#include "wavelet_all.hpp"
#include "filterbank.hpp"
#include <RcppArmadillo.h>

#define USE_ARMA


using namespace Rcpp;
// [[Rcpp::depends(RcppArmadillo)]]


arma::vec getScales(float bands_per_octave = 8,
                              float frequency_min = 0.001953125,
                              float frequency_max = 0.5,
                              float samplerate_hz = 1) {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  
  std::vector<double> frequencies = cwt.frequencies;
  arma::vec periods = 1/arma::conv_to<arma::vec>::from(frequencies); 
  
  return periods;
}

std::size_t getSize(float bands_per_octave = 8,
                              float frequency_min = 0.001953125,
                              float frequency_max = 0.5,
                              float samplerate_hz = 1) {
  wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  return cwt.size();
}
