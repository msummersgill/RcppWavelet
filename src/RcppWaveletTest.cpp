#include <RcppArmadillo.h>
#include "wavelet_all.hpp"

#define USE_ARMA
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::cx_mat RcppWaveletTest(std::vector<double> x,
                             float bands_per_octave = 8,
                             float frequency_min = 0.001953125,
                             float frequency_max = 0.5,
                             float samplerate_hz = 1) {
    wavelet::Filterbank cwt(samplerate_hz,
                          frequency_min,
                          frequency_max,
                          bands_per_octave);
  std::size_t numbands(cwt.size());
  cwt.reset(); // Reset processing
  return cwt.process(x);
}